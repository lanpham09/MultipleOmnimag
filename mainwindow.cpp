#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>
#include <QMessageBox>

#include "opencv2/highgui/highgui.hpp"

#include "Utilities/Units.h"
#include "Utilities/Timer.h"

#define UPDATE_FRAME_RATE 30.0



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    update_timer = new QTimer();

    // Create Demo
    thisSetup   = new OmnimagSetup();
    thisDemo    = new Field_and_Force_Demo( thisSetup->omnimagSystem,  thisSetup->toolProducer, thisSetup->goalPose, thisSetup->positionController, MagneticField(1.5,MILLITESLA), thisSetup->desiredForce);

    constPosition  = 0;

    // Create Position Labels
    ui->label_DesPos    ->setUnits("mm",1);
    ui->label_DesPos    ->value(0,0,0);
    ui->label_ActPos    ->setUnits("mm",1);
    ui->label_ActPos    ->value(0,0,0);
    ui->label_ErrorPos  ->setUnits("mm",2);
    ui->label_ErrorPos  ->value(0,0,0);
    ui->label_Current_1 ->setUnits("A",2);
    ui->label_Current_1 ->value(0,0,0);
    ui->label_Current_2 ->setUnits("A",2);
    ui->label_Current_2 ->value(0,0,0);
    ui->label_Temp_2 ->setUnits("C",0);
    ui->label_Temp_2 ->value(0,0,0);
    ui->label_ContForce ->setUnits("mN",2);
    ui->label_ContForce ->value(0,0,0);
    ui->omni1_pos ->setUnits("mm",1);
    ui->omni1_pos ->value(0,0,0);
    ui->omni2_pos ->setUnits("mm",1);
    ui->omni2_pos ->value(0,0,0);
    ui->label_heading ->setUnits("",1);
    ui->label_heading ->value(0,0,0);


    // Create Buttons
    ui->button_FindWeight       ->setup("Find Tool Weight"  , "Stop Finding Weight" , false);
    ui->button_StartDataLogging ->setup("Start Logging"     , "Stop Logging"      , false);
    ui->button_StartDemo        ->setup("Start Demo"        , "Stop Demo"           , false);
    ui->button_StartVideoRec    ->setup("Start Recording"   , "Stop Recording"        , false);

    ui->button_o1_PlusX            ->setup("+X Moment", "Off", false);
    ui->button_o1_PlusY            ->setup("+Y Moment", "Off", false);
    ui->button_o1_PlusZ            ->setup("+Z Moment", "Off", false);
    ui->button_o2_PlusX            ->setup("+X Moment", "Off", false);
    ui->button_o2_PlusY            ->setup("+Y Moment", "Off", false);
    ui->button_o2_PlusZ            ->setup("+Z Moment", "Off", false);

    ui->button_ROI              ->setup("Enable ROI","Disable ROI", false);

    ui->button_Inhibit          ->setup("ENABLE", "INHIBIT", false);

    ui->button_currentBias      ->setup("Find Bias" ,"Running" , false);

    // Initialize Values
    ui->doubleSpinBox->setValue( thisSetup->toolProducer->returnMagneticTool().weight.norm(NEWTON) );

    // Setup Display Size
    displaySize = cv::Size(480,360);

    display_image_one = cv::Mat(displaySize.width, displaySize.height, CV_8UC3, cv::Scalar(0,0,0));
    display_image_two = cv::Mat(displaySize.width, displaySize.height, CV_8UC3, cv::Scalar(0,0,0));
    capture_image_one = cv::Mat(displaySize.width, displaySize.height, CV_8UC3, cv::Scalar(0,0,0));
    capture_image_two = cv::Mat(displaySize.width, displaySize.height, CV_8UC3, cv::Scalar(0,0,0));
    capture_image_oneFilter = cv::Mat(displaySize.width, displaySize.height, CV_8UC3, cv::Scalar(0,0,0));
    capture_image_twoFilter = cv::Mat(displaySize.width, displaySize.height, CV_8UC3, cv::Scalar(0,0,0));


    // Setup Camera Display
    ui->leftCamera  ->setup( displaySize.width, displaySize.height, "Camera Left" );
    ui->rightCamera ->setup( displaySize.width, displaySize.height, "Camera Right");

    ui->leftFilterImage ->setup( displaySize.width, displaySize.height, "Filter Left" );
    ui->rightFieterImage ->setup( displaySize.width, displaySize.height, "Filter Right" );

    // Setup Video Recorder
    video_recorderRT = new cv::VideoWriter();
    video_recorderLFT = new cv::VideoWriter();


    // Setup Timer for Trajectory Tracking Stuff
    goal_timer = new QTimer();
    mode = NOTSET;

    // Connect Timer To Update Function
    connect( update_timer, SIGNAL(timeout(void)), this, SLOT( updateDisplayValues(void) ) );
    connect( goal_timer,   SIGNAL(timeout(void)), this, SLOT( updateDemoProperties(void)) );

    // Connect Buttons to Function Calls
    connect( ui->button_FindWeight,         SIGNAL(clicked()),  this,   SLOT( startWeightCalibrationMode(void) ));
    connect( ui->button_StartDataLogging,   SIGNAL(clicked()),  this,   SLOT( startDataLogging(void) )          );
    connect( ui->button_StartDemo,          SIGNAL(clicked()),  this,   SLOT( startTrajectoryMode(void) )       );
    connect( ui->button_StartVideoRec,      SIGNAL(clicked()),  this,   SLOT( startVideoRecording(void) )       );

    connect( ui->button_o1_PlusX,      SIGNAL(clicked()),  this,   SLOT( plusXMoment1(void) ) );
    connect( ui->button_o1_PlusY,      SIGNAL(clicked()),  this,   SLOT( plusYMoment1(void) ) );
    connect( ui->button_o1_PlusZ,      SIGNAL(clicked()),  this,   SLOT( plusZMoment1(void) ) );

    connect( ui->button_o2_PlusX,      SIGNAL(clicked()),  this,   SLOT( plusXMoment2(void) ) );
    connect( ui->button_o2_PlusY,      SIGNAL(clicked()),  this,   SLOT( plusYMoment2(void) ) );
    connect( ui->button_o2_PlusZ,      SIGNAL(clicked()),  this,   SLOT( plusZMoment2(void) ) );

    connect( ui->button_Inhibit,    SIGNAL(clicked()),  this,   SLOT( inhibit(void) ) );

    connect( ui->horizontalSliderColorMaxRight, SIGNAL(valueChanged(int)), this, SLOT(setColorMaxRight(int)) );
    connect( ui->horizontalSliderColorMinRight, SIGNAL(valueChanged(int)), this, SLOT(setColorMinRight(int)) );
    connect( ui->horizontalSliderColorMaxLeft, SIGNAL(valueChanged(int)), this, SLOT(setColorMaxLeft(int)) );
    connect( ui->horizontalSliderColorMinLeft, SIGNAL(valueChanged(int)), this, SLOT(setColorMinLeft(int)) );

    connect( ui->doubleSpinBoxFilter, SIGNAL(valueChanged(double)), this, SLOT(setFilterStDev(double)) );

    connect( ui->button_camReset, SIGNAL(clicked()), this, SLOT( camReset(void) ));

    connect( ui->rightCamera, SIGNAL(pointSelected(void)), this, SLOT( updateRightPoint(void) ));
    connect( ui->leftCamera, SIGNAL(pointSelected(void)), this, SLOT( updateLeftPoint(void) ));



    connect( ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(setWeight(double) ));


    connect( ui->dial, SIGNAL(valueChanged(int)), this, SLOT(changeGoalDirection()) );
    connect( ui->dial_2, SIGNAL(valueChanged(int)), this, SLOT(changeGoalDirection()) );


    connect( ui->horizontalSliderXPosition, SIGNAL(valueChanged(int)),this,SLOT(changeGoalPosition()) );
    connect( ui->horizontalSliderYPosition, SIGNAL(valueChanged(int)),this,SLOT(changeGoalPosition()) );
    connect( ui->horizontalSliderZPosition, SIGNAL(valueChanged(int)),this,SLOT(changeGoalPosition()) );


    // setAMC_A_Bias(-0.079);
    // setAMC_B_Bias(-0.207);
    // setAMC_C_Bias(0.018);


    // Setup Timer for Screen Updates
    update_timer->start(1000.0/UPDATE_FRAME_RATE);

    return;
}

MainWindow::~MainWindow()
{
    if( thisDemo )
        if( thisDemo->isRunning() )
            thisDemo->stop();

    thisSetup->OFF();

    delete thisDemo;
    delete thisSetup;

    delete ui;
}

void MainWindow::updateRightPoint( )
{
    Math::Pixel val;
    ui->rightCamera->getImagePosition(val);
    thisSetup->colorTrackRight->setPrevPos(val);
}

void MainWindow::updateLeftPoint( )
{
    Math::Pixel val;
    ui->leftCamera->getImagePosition(val);

    thisSetup->colorTrackLeft->setPrevPos(val);
}

void MainWindow::setWeight(double newWeight)
{
    thisSetup->toolProducer->setWeight(Math::ForceVector(0,0,-newWeight,Math::WORLD_FRAME,NEWTON));
}


void MainWindow::setColorMinLeft(int val)
{
    if( val != thisSetup->colorTrackLeft->colorMin() )
    {
        thisSetup->colorTrackLeft->colorMin(val);
    }

    ui->spinBoxColorMinLeft->setValue( thisSetup->colorTrackLeft->colorMin() );

}

void MainWindow::setColorMaxLeft(int val)
{
    if( val != thisSetup->colorTrackLeft->colorMax() )
    {
        thisSetup->colorTrackLeft->colorMax(val);
    }
    ui->spinBoxColorMaxLeft->setValue( thisSetup->colorTrackLeft->colorMax() );
}

void MainWindow::setColorMinRight(int val)
{
    if( val != thisSetup->colorTrackRight->colorMin() )
    {
        thisSetup->colorTrackRight->colorMin(val);
    }

    ui->spinBoxColorMinRight->setValue( thisSetup->colorTrackRight->colorMin() );

}

void MainWindow::setColorMaxRight(int val)
{
    if( val != thisSetup->colorTrackRight->colorMax() )
    {
        thisSetup->colorTrackRight->colorMax(val);
    }
    ui->spinBoxColorMaxRight->setValue( thisSetup->colorTrackRight->colorMax() );
}

void MainWindow::setFilterStDev( double val)
{
    if( val != thisSetup->colorTrackLeft->FilterStDev() )
    {
        thisSetup->colorTrackLeft->FilterStDev(val);
        thisSetup->colorTrackRight->FilterStDev(val);
    }
    ui->doubleSpinBoxFilter->setValue( thisSetup->colorTrackLeft->FilterStDev() );
}

void MainWindow::inhibit()
{
    cout << "Enable System " << ui->button_Inhibit->getState() << endl;
    if( !ui->button_Inhibit->getState() )
    {
        cout << "INHIBIT SYSTEM" << endl;
        thisSetup->systemSetup.inhibit();
    }else
    {
        cout << "ENABLE SYSTEM" << endl;
        thisSetup->systemSetup.enable();
        cout << "Sucess" << thisSetup->systemSetup.isEnabled() << endl;
    }

    ui->button_Inhibit->setState( thisSetup->systemSetup.isEnabled() );
}

void MainWindow::ROI()
{
    if( !ui->button_ROI->getState() )
    {
        thisSetup->stereoCamera->enableROI(90);
    }else {
        thisSetup->stereoCamera->disableROI();
    }
    ui->button_ROI->setState( !ui->button_ROI->getState() );

    return;
}

void MainWindow::updateDisplayValues()
{
    ui->button_Inhibit->setState( thisSetup->systemSetup.isEnabled() );

    if( ui->spinBoxColorMinRight->value() != thisSetup->colorTrackRight->colorMin())
    {
        ui->spinBoxColorMinRight->setValue( thisSetup->colorTrackRight->colorMin() );
    }
    if(  ui->spinBoxColorMaxRight->value() != thisSetup->colorTrackRight->colorMax() )
    {
        ui->spinBoxColorMaxRight->setValue( thisSetup->colorTrackRight->colorMax() );

    }
    if( ui->spinBoxColorMinLeft->value() != thisSetup->colorTrackLeft->colorMin())
    {
        ui->spinBoxColorMinLeft->setValue( thisSetup->colorTrackLeft->colorMin() );
    }
    if(  ui->spinBoxColorMaxLeft->value() != thisSetup->colorTrackLeft->colorMax() )
    {
        ui->spinBoxColorMaxLeft->setValue( thisSetup->colorTrackLeft->colorMax() );

    }
    if( ui->doubleSpinBoxFilter->value() != thisSetup->colorTrackLeft->FilterStDev() )
    {
        ui->doubleSpinBoxFilter->setValue( thisSetup->colorTrackLeft->FilterStDev() );
    }

    if( thisDemo->isRunning() && thisSetup->desiredForce->historyLength() > 0 )
    {
        ui->label_ContForce ->value(thisSetup->desiredForce->value().value*1000);
    } else {
        ui->label_ContForce ->value(0,0,0);
    }

    ui->label_Current_1 ->value(thisSetup->systemSetup(OmniMag0)->commandedCurrent() );
    ui->label_Current_2 ->value(thisSetup->systemSetup(OmniMag2)->commandedCurrent());
    ui->label_Current_3 ->value(thisSetup->systemSetup(OmniMag3)->commandedCurrent());
    ui->label_Current_4 ->value(thisSetup->systemSetup(OmniMag4)->commandedCurrent());
    ui->label_Current_5 ->value(thisSetup->systemSetup(OmniMag5)->commandedCurrent());
    ui->label_Current_6 ->value(thisSetup->systemSetup(OmniMag6)->commandedCurrent());

    //ui->label_Temp_2    ->value( thisSetup->omnimagnet2->getTemperature() );

    if( ui->doubleSpinBox->value() != -thisSetup->toolProducer->returnMagneticTool().weight.z(NEWTON))
    {
        ui->doubleSpinBox->setValue( -thisSetup->toolProducer->returnMagneticTool().weight.z(NEWTON) );
    }

    bool gotImages = false;
    double scale1 = 0, scale2 = 0;
    // Update the immages if the video is streaming
    if( thisSetup->stereoCamera->isVideoStreaming() )
    {
        gotImages = thisSetup->colorTrackLeft->getFilterResult( capture_image_oneFilter);
        gotImages &= thisSetup->colorTrackRight->getFilterResult( capture_image_twoFilter);
        scale1 = (double)displaySize.height/(double)capture_image_oneFilter.size().height;
        scale2 = (double)displaySize.height/(double)capture_image_twoFilter.size().height;
    } else {
        ui->leftCamera->noImage();
        ui->rightCamera->noImage();
    }

    if( gotImages && scale1 > 0 && scale2 > 0 )
    {
        cv::resize(capture_image_oneFilter,capture_image_oneFilter,Size(0,0),scale1 , scale1, cv::INTER_NEAREST);
        cv::resize(capture_image_twoFilter,capture_image_twoFilter,Size(0,0),scale2 , scale2, cv::INTER_NEAREST);


        ui->leftFilterImage->updateImage(capture_image_oneFilter);
        ui->rightFieterImage->updateImage(capture_image_twoFilter);


        thisSetup->cam0->getFrame(capture_image_one);
        thisSetup->cam1->getFrame(capture_image_two);

        Math::Pixel leftPixelGoal( (int) capture_image_one.rows/2, (int) capture_image_one.cols/2 );
        Math::Pixel rightPixelGoal( (int) capture_image_one.rows/2, (int) capture_image_one.cols/2 );
        //thisSetup->stereoCamera->getTrackingPos(leftPixelGoal,rightPixelGoal);

        bool pixelIsValid = false;

        if( thisDemo ->isRunning() )
        {
            Math::Position goal = thisSetup->goalPose->returnPosition().convertToUnits(MILLIMETER);
            Math::Position goalINCamera = (thisSetup->toolLocation->getTransformation().inverseTransform())*goal;
            thisSetup->underwaterTriangulation->mapToImage( goalINCamera.asVector(MILLIMETER) ,leftPixelGoal,rightPixelGoal);

            pixelIsValid =  (leftPixelGoal.x > 0) && (leftPixelGoal.y > 0)  && (leftPixelGoal.x < capture_image_one.rows) && (leftPixelGoal.y < capture_image_one.cols);
            pixelIsValid = pixelIsValid && (rightPixelGoal.x > 0) && (rightPixelGoal.y > 0) && (rightPixelGoal.x < capture_image_two.rows) && (rightPixelGoal.y < capture_image_two.cols);
        }

        if ( video_recorderRT->isOpened() && video_recorderLFT->isOpened() )
        {
            (*video_recorderRT) << capture_image_one;
            (*video_recorderLFT) << capture_image_two;
            // Record object pixel location



            thisSetup->videoWriteSignal  ->append(true);
            thisSetup->leftPixelLocation ->append( Math::Vector( leftPixelGoal.x,  leftPixelGoal.y,  0) );
            thisSetup->rightPixelLocation->append( Math::Vector( rightPixelGoal.x, rightPixelGoal.y, 0) );

            if( pixelIsValid )
            {
                thisSetup->goal_LeftPixelLocation->append( Math::Vector( (int)(leftPixelGoal.x+.5),  (int)(leftPixelGoal.y+.5),  0) );
                thisSetup->goal_RightPixelLocation->append( Math::Vector( (int)(rightPixelGoal.x+.5), (int)(rightPixelGoal.y+.5), 0) );
            }

        }




        if( pixelIsValid)
        {
            // put dot at point
            circle(capture_image_one, Point2i(leftPixelGoal.x, leftPixelGoal.y), 3, cv::Scalar(255,0,0), 2);
            circle(capture_image_two, Point2i(rightPixelGoal.x, rightPixelGoal.y), 3, cv::Scalar(255,0,0), 2);
        }
        Mat imR,imL;

        scale1 = (double)displaySize.height/(double)capture_image_one.size().height;
        cv::resize(capture_image_one, imL, Size(0,0),scale1 , scale1, cv::INTER_NEAREST);

        scale2 = (double)displaySize.height/(double)capture_image_two.size().height;
        cv::resize(capture_image_two, imR, Size(0,0),scale2 , scale2, cv::INTER_NEAREST);



        Math::Pixel left;
        Math::Pixel right;
        thisSetup->stereoCamera->getTrackingPos(left,right);

        QVector2D LPOS(left.x*scale1,left.y*scale1);
        QVector2D RPOS(right.x*scale2,right.y*scale2);

        QString fpsLeft;
        QString fpsRight;

        fpsLeft.setNum(thisSetup->cam0->getFPS(),'f',1);
        fpsRight.setNum(thisSetup->cam1->getFPS(),'f',1);

        // Print Position of Capsule
        Math::Position pos;
        thisSetup->toolLocation->getPosition(pos);
        std::stringstream LeftString;
        LeftString << "Camera Left. FPS: " << fpsLeft.toStdString() << "\tPOS: " << pos.toStr();
        // display image
        QString output;
        output = LeftString.str().c_str();



        ui->leftCamera->setDisplayText( output );
        ui->leftCamera->updateImage(imL,LPOS);

        ui->rightCamera->setDisplayText("Camera Right. FPS: " + fpsRight );
        ui->rightCamera->updateImage(imR,RPOS);


    }else {
        ui->leftCamera->noImage();
        ui->rightCamera->noImage();
    }

    Math::Position posDes;
    Math::Position posTool;

    bool pos1good, pos2good;


    if( ( pos1good = thisSetup->goalPose->getPosition( posDes )) )
    {
        ui->label_DesPos->value( posDes.convertToUnits(MILLIMETER), MILLIMETER );
        ui->label_heading->value(thisSetup->goalPose->returnDirection().asVector());
    } else
        ui->label_ActPos->value( Math::Zero() );

    if ( (pos2good = thisSetup->toolLocation->getPosition( posTool ) ))
        ui->label_ActPos->value( posTool.convertToUnits(MILLIMETER), MILLIMETER );
    else
        ui->label_ActPos->value( Math::Zero() );

    if ( thisDemo->isRunning() )
        ui->label_ErrorPos->value( (posDes - posTool).convertToUnits(MILLIMETER), MILLIMETER );
    else
        ui->label_ErrorPos->value( Math::Zero() );

    ui->omni1_pos->value( thisSetup->systemSetup(OmniMag0)->returnPosition() );
    ui->omni2_pos->value( thisSetup->systemSetup(OmniMag2)->returnPosition() );

    return;
}

void MainWindow::plusXMoment1()
{
    if( ui->button_o1_PlusX->getState() )
    {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(100,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        ui->button_o1_PlusX->setState( true );
        ui->button_o1_PlusY->setState( false );
        ui->button_o1_PlusZ->setState( false );
        ui->button_o2_PlusX->setState( false );
        ui->button_o2_PlusY->setState( false );
        ui->button_o2_PlusZ->setState( false );
        ui->button_FindWeight->setEnabled( false );
        ui->button_StartDemo->setEnabled( false );

    } else {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        ui->button_o1_PlusX->setState( false );
        ui->button_FindWeight->setEnabled( true );
        ui->button_StartDemo->setEnabled( true );
    }
}

void MainWindow::plusYMoment1()
{
    if( ui->button_o1_PlusY->getState() )
    {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,100,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        ui->button_o1_PlusX->setState( false );
        ui->button_o1_PlusY->setState( true );
        ui->button_o1_PlusZ->setState( false );
        ui->button_o2_PlusX->setState( false );
        ui->button_o2_PlusY->setState( false );
        ui->button_o2_PlusZ->setState( false );
        ui->button_FindWeight->setEnabled( false );
        ui->button_StartDemo->setEnabled( false );

    } else {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        ui->button_o1_PlusY->setState( false );
        ui->button_FindWeight->setEnabled( true );
        ui->button_StartDemo->setEnabled( true );
    }
}

void MainWindow::plusZMoment1()
{
    if( ui->button_o1_PlusZ->getState() )
    {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,100, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        ui->button_o1_PlusX->setState( false );
        ui->button_o1_PlusY->setState( false );
        ui->button_o1_PlusZ->setState( true );
        ui->button_o2_PlusX->setState( false );
        ui->button_o2_PlusY->setState( false );
        ui->button_o2_PlusZ->setState( false );
        ui->button_FindWeight->setEnabled( false );
        ui->button_StartDemo->setEnabled( false );

    } else {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        ui->button_o1_PlusZ->setState( false );
        ui->button_FindWeight->setEnabled( true );
        ui->button_StartDemo->setEnabled( true );
    }
}

void MainWindow::plusXMoment2()
{
    if( ui->button_o2_PlusX->getState() )
    {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        if (ui->spin_whichOmni->value() == 2)
            thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(50,0,0, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 3)
            thisSetup->systemSetup(OmniMag3)->dipoleMoment(Math::DipoleMomentVector(50,0,0, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 4)
            thisSetup->systemSetup(OmniMag4)->dipoleMoment(Math::DipoleMomentVector(50,0,0, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 5)
            thisSetup->systemSetup(OmniMag5)->dipoleMoment(Math::DipoleMomentVector(50,0,0, Math::WORLD_FRAME));

        ui->button_o1_PlusX->setState( false );
        ui->button_o1_PlusY->setState( false );
        ui->button_o1_PlusZ->setState( false );
        ui->button_o2_PlusX->setState( true );
        ui->button_o2_PlusY->setState( false );
        ui->button_o2_PlusZ->setState( false );
        ui->button_FindWeight->setEnabled( false );
        ui->button_StartDemo->setEnabled( false );

    } else {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag3)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag4)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag5)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));

        ui->button_o2_PlusX->setState( false );
        ui->button_FindWeight->setEnabled( true );
        ui->button_StartDemo->setEnabled( true );
    }
}

void MainWindow::plusYMoment2()
{
    if( ui->button_o2_PlusY->getState() )
    {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        if (ui->spin_whichOmni->value() == 2)
            thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,50,0, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 3)
            thisSetup->systemSetup(OmniMag3)->dipoleMoment(Math::DipoleMomentVector(0,50,0, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 4)
            thisSetup->systemSetup(OmniMag4)->dipoleMoment(Math::DipoleMomentVector(0,50,0, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 5)
            thisSetup->systemSetup(OmniMag5)->dipoleMoment(Math::DipoleMomentVector(0,50,0, Math::WORLD_FRAME));
        ui->button_o1_PlusX->setState( false );
        ui->button_o1_PlusY->setState( false );
        ui->button_o1_PlusZ->setState( false );
        ui->button_o2_PlusX->setState( false );
        ui->button_o2_PlusY->setState( true );
        ui->button_o2_PlusZ->setState( false );
        ui->button_FindWeight->setEnabled( false );
        ui->button_StartDemo->setEnabled( false );

    } else {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag3)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag4)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag5)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        ui->button_o2_PlusY->setState( false );
        ui->button_FindWeight->setEnabled( true );
        ui->button_StartDemo->setEnabled( true );
    }
}

void MainWindow::plusZMoment2()
{
    if( ui->button_o2_PlusZ->getState() )
    {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        if (ui->spin_whichOmni->value() == 2)
            thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,50, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 3)
            thisSetup->systemSetup(OmniMag3)->dipoleMoment(Math::DipoleMomentVector(0,0,50, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 4)
            thisSetup->systemSetup(OmniMag4)->dipoleMoment(Math::DipoleMomentVector(0,0,50, Math::WORLD_FRAME));
        else if (ui->spin_whichOmni->value() == 5)
            thisSetup->systemSetup(OmniMag5)->dipoleMoment(Math::DipoleMomentVector(0,0,50, Math::WORLD_FRAME));
        ui->button_o1_PlusX->setState( false );
        ui->button_o1_PlusY->setState( false );
        ui->button_o1_PlusZ->setState( false );
        ui->button_o2_PlusX->setState( false );
        ui->button_o2_PlusY->setState( false );
        ui->button_o2_PlusZ->setState( true );
        ui->button_FindWeight->setEnabled( false );
        ui->button_StartDemo->setEnabled( false );

    } else {
        thisSetup->systemSetup(OmniMag0)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag2)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag3)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag4)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        thisSetup->systemSetup(OmniMag5)->dipoleMoment(Math::DipoleMomentVector(0,0,0, Math::WORLD_FRAME));
        ui->button_o2_PlusZ->setState( false );
        ui->button_FindWeight->setEnabled( true );
        ui->button_StartDemo->setEnabled( true );
    }
}

void MainWindow::camReset()
{
    thisSetup->colorTrackLeft->resetPrevPos();
    thisSetup->colorTrackRight->resetPrevPos();
}

void MainWindow::startWeightCalibrationMode()
{
    if( thisDemo->isRunning() )
    {
        thisDemo->stop();
        goal_timer->stop();
        mode = NOTSET;
        ui->button_o1_PlusX->setEnabled( true );
        ui->button_o1_PlusY->setEnabled( true );
        ui->button_o1_PlusZ->setEnabled( true );
        ui->button_o2_PlusX->setEnabled( true );
        ui->button_o2_PlusY->setEnabled( true );
        ui->button_o2_PlusZ->setEnabled( true );
    }
    else
    {
        ui->button_o1_PlusX->setEnabled( false );
        ui->button_o1_PlusY->setEnabled( false );
        ui->button_o1_PlusZ->setEnabled( false );
        ui->button_o2_PlusX->setEnabled( false );
        ui->button_o2_PlusY->setEnabled( false );
        ui->button_o2_PlusZ->setEnabled( false );


        Math::MagneticTool thisTool;
        thisSetup->toolProducer->getMagneticTool( thisTool );

        thisSetup->toolProducer->setWeight(Math::ForceVector(0,0,0,thisTool.getFrame(),NEWTON));

        Math::Position capsulePos = thisSetup->toolLocation->returnPosition();

        // set it to 1 cm above current position
        capsulePos = capsulePos + Math::Displacement( 0, 0, 3, capsulePos.getFrame(), CENTIMETER );

        thisSetup->goalPose->setPosition(Math::Position(70,160,90,WORLD_FRAME,MILLIMETER));

        //thisDemo ->saturateMoment( true );

        thisDemo->start(40);
        mode = WEIGHT;
        goal_timer->start(50.0); // Wait for 2 secnods to align
    }
    ui->button_FindWeight->setState( thisDemo->isRunning() );
    ui->button_StartDemo->setState( false );
    return;
}

void MainWindow::updateDemoProperties(void)
{

    Math::MagneticTool thisTool;
    Math::Position goalPosition;
    Math::Position toolPosition;
    Math::Displacement   errorVector;

    double Igain = .0000003;
    Distance distanceTreshold(20,MILLIMETER);        // acceptable position error

    if( thisDemo->isRunning() )
    {

        thisSetup->toolProducer->getMagneticTool( thisTool );
        thisSetup->toolLocation->getPosition( toolPosition );
        thisSetup->goalPose->getPosition( goalPosition );
        errorVector = goalPosition-toolPosition;

    }else {
        cout << "demo not running" << endl;
        mode = NOTSET;
        goal_timer->stop();
        ui->button_FindWeight->setState( false );
        ui->button_StartDemo->setState( false );
        thisSetup->OFF();
    }

    switch( mode )
    {
    case NOTSET:
        break;
    case WEIGHT:
    {
        // don't include the integrator
        //thisDemo->integratedforce[0] = 0.0;
        //thisDemo->integratedforce[1] = 0.0;
        //thisDemo->integratedforce[2] = 0.0;

        thisSetup->toolProducer->setWeight( thisTool.weight - Math::ForceVector(0,0,1,thisTool.getFrame(),NEWTON)*Math::sign(errorVector.z(MILLIMETER))*Igain );
        cout << "Weight " <<  thisTool.weight << endl;

        break;
    }

    case TRAJECTORY:
        if( thisSetup->trajectory_PositionProducer->fileOpen() )
        {
            // cout << "Error Distance: " << errorVector.norm() <<endl;
            // determine if new waypoint shoudl be selected
            if( errorVector.norm() < distanceTreshold )
            {
                Math::Position trajectoryPos;
            //    thisSetup->trajectory_PositionProducer->getNext();
                thisSetup->trajectory_PositionProducer->getPosition(trajectoryPos);
            }
        }else {
            // trajectory is complete
            cout << "Trajectory file no longer open" << endl;
            mode = NOTSET;
            goal_timer->stop();
            startTrajectoryMode();
        }

        break;
    }

    return;
}

void MainWindow::startTrajectoryMode()
{
    if( thisDemo->isRunning() )
    {
        thisDemo->stop();
        thisSetup->trajectory_PositionProducer->stop();
        goal_timer->stop();
        mode = NOTSET;
        ui->button_o1_PlusX->setEnabled( true );
        ui->button_o1_PlusY->setEnabled( true );
        ui->button_o1_PlusZ->setEnabled( true );
        ui->button_o2_PlusX->setEnabled( true );
        ui->button_o2_PlusY->setEnabled( true );
        ui->button_o2_PlusZ->setEnabled( true );
        thisSetup->OFF();

    } else {

        ui->button_o1_PlusX->setEnabled( false );
        ui->button_o1_PlusY->setEnabled( false );
        ui->button_o1_PlusZ->setEnabled( false );
        ui->button_o2_PlusX->setEnabled( false );
        ui->button_o2_PlusY->setEnabled( false );
        ui->button_o2_PlusZ->setEnabled( false );



        //Math::Position omniMagPos;
        //thisSetup->systemSetup(OmniMag0)->getPosition( omniMagPos );
        Math::Position trajectoryPos;
        thisSetup->goalPose->changeProducer( thisSetup->trajectory_PositionProducer );
        thisSetup->trajectory_PositionProducer->start();
        //thisSetup->goalPose->setPosition( thisSetup->goalPose->asPositionProducer() );
        thisSetup->goalPose->getPosition(trajectoryPos);
        cout << "Trajectory Position" << (trajectoryPos).convertToUnits(MILLIMETER) << endl;
        //cout << (TrajectoryToWorld*trajectoryPos).convertToUnits(MILLIMETER) << endl;
        //thisSetup->goalPose->setPosition( (TrajectoryToWorld*Position(0,0,2,TRAJECTORY_FRAME,CENTIMETER)).convertToUnits(MILLIMETER) );

        // Go to first position

        //thisDemo->saturateMoment(true);


        mode  = TRAJECTORY;
        thisDemo->start( 40 );
        //goal_timer->start( 1000.0/80.0 );

    }
    ui->button_StartDemo->setState( thisDemo->isRunning() );
    ui->button_FindWeight->setState( false );
    return;
}

void MainWindow::startDataLogging()
{
    if( !thisSetup->fileLog->isWritting() ) {

        // Need to pause cameras so they dont wigg out
        //        bool demoRunning = thisDemo->isRunning();
        //        if( demoRunning )
        //            thisDemo->stop();

        //        thisSetup->cam0->pause();
        //        thisSetup->cam1->pause();

        //        QFileDialog dialog(this);
        //        dialog.setFileMode(QFileDialog::Directory);
        //        dialog.setOption(QFileDialog::ShowDirsOnly);
        //        QString dirName = dialog.getExistingDirectory(this,tr("Directory"),"~/");

        //        // Unpause Cameras
        //        thisSetup->cam0->unpause();
        //        thisSetup->cam1->unpause();
        //        if( demoRunning )
        //            thisDemo->start();

        //        thisSetup->fileLog->setDirectory(dirName.toStdString());
        //        thisSetup->fileLog->resetTimeStamp();
        thisSetup->fileLog->writeAllEvery(1000.0/UPDATE_FRAME_RATE*10.5);

    } else {

        // Pause Updates for File IO
        switch( QMessageBox::information( this, "Stop Data Recording",
                                          "Are you sure you wish to cancel data recording?",
                                          "Yes", "No",
                                          0, 1 ) ) {
        case 0:
            thisSetup->fileLog->stopWritting();
            break;
        case 1:
            ui->button_StartDataLogging->setState(thisSetup->fileLog->isWritting());
            break;
        }
    }
    return;
}

void MainWindow::startVideoRecording()
{
    if( thisSetup->stereoCamera->isVideoStreaming() ) {

        if ( !video_recorderRT->isOpened() ) {

            string fileNameStr = "Right Video Stream.avi";
            video_recorderRT->open(fileNameStr, CV_FOURCC('D','I','V','X'), UPDATE_FRAME_RATE, capture_image_one.size(), true);


            fileNameStr = "Left Video Stream.avi";
            video_recorderLFT->open(fileNameStr, CV_FOURCC('D','I','V','X'), UPDATE_FRAME_RATE, capture_image_one.size(), true);

        }else {
            video_recorderRT->release();
            video_recorderLFT->release();
        }
    }
    ui->button_StartVideoRec->setState(video_recorderRT->isOpened() && thisSetup->stereoCamera->isVideoStreaming());
    return;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // Stop Everything I have going
    clean();

    // Let QT Do its thing.
    event->accept();
    this->close();
    return;
}

void MainWindow::clean()
{
    cout << "Prepareing to close " << endl;
    update_timer->stop();

    // Stop Demo
    if( thisDemo->isRunning() )
    {
        cout << "stoping current Demo " << endl;
        thisDemo->stop();
    }

    // Stop Recording; Release Buffer; Delete Recorder
    if( video_recorderRT->isOpened() ) {
        cout << "Stopping Video Recording" << endl;
        video_recorderRT->release();
    }
    // Stop Recording; Release Buffer; Delete Recorder
    if( video_recorderLFT->isOpened() ) {
        cout << "Stopping Video Recording" << endl;
        video_recorderLFT->release();
    }

    if( this->thisSetup->stereoCamera->isVideoStreaming() ) {
        cout << "stoping Video stream" << endl;
        this->thisSetup->stereoCamera->stop();
    }

    cout << "Stopping Data Reading" << endl;
    // Stop Reading Data
    //thisSetup->s626->stopReadings();

    cout << "Sending Off Command " << endl;
    thisSetup->OFF();

    cout << "Inhibiting System" << endl;
    // Inhibit system
    thisSetup->systemSetup.inhibit();

    if( thisSetup->fileLog->isWritting() )
    {
        cout << "stoping File Logging" << endl;
        thisSetup->fileLog->stopWritting();
    }

    cout << "Deleting objects" << endl;

    // Delete Runtime Allocated Objects
    delete video_recorderRT;
    delete video_recorderLFT;
    delete update_timer;
    delete thisDemo;
    delete thisSetup;
    if( constPosition )
        delete constPosition;


    cout << "Done..." << endl;
    return;
}


void MainWindow::changeGoalDirection()
{

    double phi = ui->dial->value();
    double thet = ui->dial_2->value();

    double x = cos(thet*M_PI/180.0)*sin(phi*M_PI/180.0);
    double y = sin(thet*M_PI/180.0)*sin(phi*M_PI/180.0);
    double z = cos(phi*M_PI/180.0);
    thisSetup->goalPose->setDirection( Math::Direction(x,y,z,WORLD_FRAME) );
}

void MainWindow::changeGoalPosition()
{

    double x = ui->horizontalSliderXPosition->value() / 10.0+70;  // slider is in 10ths of mm, convert to m
    double y = ui->horizontalSliderYPosition->value() / 10.0+160;  // slider is in 10ths of mm, convert to m
    double z = ui->horizontalSliderZPosition->value() / 10.0+90;  // slider is in 10ths of mm, convert to m

    thisSetup->goalPose->setPosition( Math::Position(x/1000.0,y/1000.0,z/1000.0,WORLD_FRAME,METER) );

}
