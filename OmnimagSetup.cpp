#include "OmnimagSetup.h"

#include "Producers/Configuration5DOF_Producer.h"
#include "Producers/TransformedPositionProducer.h"

OmnimagSetup::OmnimagSetup():
    systemSetup( "Omnimagnet System Data Log Files", true )
{
    // SETUP CONTROLLER
    //cout << "SETUP POSITION CONTROLLER" << endl;
    //std::vector<double> Numerator = {  0.3, - 0.2675};
    //std::vector<double> Denominator = {1, - 0.3509};

    // Amdrew's PD controller: need PD controller for "Find Tool Weight"\
    // comes from Kp = 0.0002, Kd = 0.05, pole = 125
    std::vector<double> Numerator = {  0.62, -0.6009};
    std::vector<double> Denominator = {1,    -0.04321};

    // Just Kp
    //std::vector<double> Numerator = {0.0001, 0};
    //std::vector<double> Denominator = {1, 0};

    // Lowered Andrew's PD - marg stable
    //std::vector<double> Numerator = {.17, -.1509};
    //std::vector<double> Denominator = {1, -0.04321};

    // PID
    //0.62 z^2 - 1.221 z + 0.6008
    //---------------------------
    //  z^2 - 1.043 z + 0.04321
    //std::vector<double> Numerator = {0.62, - 1.221, 0.6008};
    //std::vector<double> Denominator = {1, -1.043, 0.04321};


    positionController = new DiscreteVectorController(Numerator,Denominator);

    // Setup Force Signal
    desiredForce = new analogVectorTimeStampedSignal("desired Force","N",500);

    // Initialize Analog Input Cards
    //omni2Pos = new ArduinoSerialPosition("/dev/ttyUSB0", Math::STAND_FRAME_1, MILLIMETER, "Omnimag 2 Slide Position");

    Matrix3x3 orient;
    Math::Position OmnimagnetPosition;
    Math::Orientation OmnimagnetOrientation;

    // Omimagnet 0 Setup (Big Omnimag)
    OmnimagnetPosition = Math::Position( 85, 155, 335, WORLD_FRAME, MILLIMETER );  // Config 0
    OmnimagnetPosition = Math::Position( 305, 155, 95, WORLD_FRAME, MILLIMETER );  // Config 3
    OmnimagnetPosition = Math::Position( 85, 155, 335, WORLD_FRAME, MILLIMETER );  // Config 2
    OmnimagnetPosition = Math::Position( 85, 155, 335, WORLD_FRAME, MILLIMETER );  // Config 1
    OmnimagnetPosition = Math::Position( 85, 155, 335, WORLD_FRAME, MILLIMETER );  // Config 6
    OmnimagnetPosition = Math::Position( 85, 155, 335, WORLD_FRAME, MILLIMETER );  // Config 7

    OmnimagnetPosition = Math::Position( 85, 155, 330, WORLD_FRAME, MILLIMETER );  // Config F5 F4 F4b F3 F5b





    orient <<   0,  0,   1,
                1,  0,   0,
                0,  1,   0;
    OmnimagnetOrientation = Math::Orientation( orient, WORLD_FRAME, OMNIMAGNET_FRAME);
    // Create Omnimagnet
    systemSetup(OmniMag0)->changeConfiguration6DOF_Producer( Configuration6DOF_Producer( OmnimagnetPosition, OmnimagnetOrientation ));


    // Omimagnet 2 Setup (Small Omnimagnet)
    // Arduino Position Input Orientation
    orient << 	 1,  0,  0,
                 0,  1,  0,
                 0,  0,  1;
    //omniMag2Location = new TransformedPositionProducer( HomogeneousTransform(orient, Math::Displacement(275,453,120,Math::WORLD_FRAME,MILLIMETER),omni2Pos->getFrame(), Math::WORLD_FRAME), omni2Pos, 500);
    OmnimagnetPosition = Math::Position( -100.0, 45.0, 65, WORLD_FRAME, MILLIMETER );  // Config 0
    OmnimagnetPosition = Math::Position( -100.0, 45.0, 65, WORLD_FRAME, MILLIMETER );  // Config 5
    OmnimagnetPosition = Math::Position( -100.0, 45.0, 65, WORLD_FRAME, MILLIMETER );  // Config 4
    OmnimagnetPosition = Math::Position( -100.0, 45.0, 65, WORLD_FRAME, MILLIMETER );  // Config 3
    OmnimagnetPosition = Math::Position( -100.0, 45.0, 65, WORLD_FRAME, MILLIMETER );  // Config 2
    OmnimagnetPosition = Math::Position( -100.0, 45.0, 65, WORLD_FRAME, MILLIMETER );  // Config 1
    OmnimagnetPosition = Math::Position( -100.0, 45.0, 65, WORLD_FRAME, MILLIMETER );  // Config 6
    OmnimagnetPosition = Math::Position( -100.0, 45.0, 65, WORLD_FRAME, MILLIMETER );  // Config 7

    OmnimagnetPosition = Math::Position( -95.0, 40.0, 65, WORLD_FRAME, MILLIMETER );  // Config F5 F4 F4b F3 F5b






    // Omnimagent Orientation (From World Frame to Omnimagnet Frame)
    orient << 	 1,  0,  0,
                 0,  1,  0,
                 0,  0,  1;
    OmnimagnetOrientation = Math::Orientation( orient, WORLD_FRAME, OMNIMAGNET_FRAME);
    systemSetup(OmniMag2)->changeConfiguration6DOF_Producer( Configuration6DOF_Producer( OmnimagnetPosition, OmnimagnetOrientation ));



    // Omimagnet 3 Setup (Small Omnimagnet)
    OmnimagnetPosition = Math::Position( -100, 292, 65, WORLD_FRAME, MILLIMETER );  // Config 0
    OmnimagnetPosition = Math::Position( -100, 292, 65, WORLD_FRAME, MILLIMETER );  // Config 5
    OmnimagnetPosition = Math::Position( -100, 292, 65, WORLD_FRAME, MILLIMETER );  // Config 4
    OmnimagnetPosition = Math::Position( -100, 292, 65, WORLD_FRAME, MILLIMETER );  // Config 3
    OmnimagnetPosition = Math::Position( -100, 292, 65, WORLD_FRAME, MILLIMETER );  // Config 2
    OmnimagnetPosition = Math::Position( -100, 292, 65, WORLD_FRAME, MILLIMETER );  // Config 6
    OmnimagnetPosition = Math::Position( -100, 292, 65, WORLD_FRAME, MILLIMETER );  // Config 7

    OmnimagnetPosition = Math::Position( -95, 260, 65, WORLD_FRAME, MILLIMETER );  // Config F4
    OmnimagnetPosition = Math::Position( 0, 375, 65, WORLD_FRAME, MILLIMETER );  // Config F4b F5
    OmnimagnetPosition = Math::Position( 260, 330, 65, WORLD_FRAME, MILLIMETER );  // Config F5b





    // Omnimagent Orientation (From World Frame to Omnimagnet Frame)
    orient << 	 1,  0,  0,
                 0,  1,  0,
                 0,  0,  1;
    OmnimagnetOrientation = Math::Orientation( orient, WORLD_FRAME, OMNIMAGNET_FRAME);
    systemSetup(OmniMag3)->changeConfiguration6DOF_Producer( Configuration6DOF_Producer( OmnimagnetPosition, OmnimagnetOrientation ));


    // Omimagnet 4 Setup (Small Omnimagnet)
    OmnimagnetPosition = Math::Position( 73.0, 382, 62, WORLD_FRAME, MILLIMETER );  // Config 0
    OmnimagnetPosition = Math::Position( 82.0, 158, 305, WORLD_FRAME, MILLIMETER );  // Config 5
    OmnimagnetPosition = Math::Position( 82.0, 83, 305, WORLD_FRAME, MILLIMETER );  // Config 4
    OmnimagnetPosition = Math::Position( 82.0, 83, 305, WORLD_FRAME, MILLIMETER );  // Config 3
    OmnimagnetPosition = Math::Position( 250.0, 50, 62, WORLD_FRAME, MILLIMETER );  // Config 6
    OmnimagnetPosition = Math::Position( 250.0, 50, 62, WORLD_FRAME, MILLIMETER );  // Config 7

    OmnimagnetPosition = Math::Position( 255.0, 50, 190, WORLD_FRAME, MILLIMETER );  // Config F5
    OmnimagnetPosition = Math::Position( 260, 330, 190, WORLD_FRAME, MILLIMETER );  // Config F5b



    // Omnimagent Orientation (From World Frame to Omnimagnet Frame)
    orient << 	 1,  0,  0,
                 0,  1,  0,
                 0,  0,  1;
    OmnimagnetOrientation = Math::Orientation( orient, WORLD_FRAME, OMNIMAGNET_FRAME);
    systemSetup(OmniMag4)->changeConfiguration6DOF_Producer( Configuration6DOF_Producer( OmnimagnetPosition, OmnimagnetOrientation ));


    // Omimagnet 5 Setup (Small Omnimagnet)
    OmnimagnetPosition = Math::Position( 275, 160, 62, WORLD_FRAME, MILLIMETER );  // Config 0
    OmnimagnetPosition = Math::Position( 275, 160, 62, WORLD_FRAME, MILLIMETER );  // Config 5
    OmnimagnetPosition = Math::Position( 82.0, 220, 305, WORLD_FRAME, MILLIMETER );  // Config 4
    OmnimagnetPosition = Math::Position( 82.0, 220, 305, WORLD_FRAME, MILLIMETER );  // Config 3
    OmnimagnetPosition = Math::Position( 250.0, 242, 62, WORLD_FRAME, MILLIMETER );  // Config 7

    OmnimagnetPosition = Math::Position( 255.0, 50, 65, WORLD_FRAME, MILLIMETER );  // Config F4 F4b F5 F5b



    // Omnimagent Orientation (From World Frame to Omnimagnet Frame)
    orient << 	 1,  0,  0,
                 0,  1,  0,
                 0,  0,  1;
    OmnimagnetOrientation = Math::Orientation( orient, WORLD_FRAME, OMNIMAGNET_FRAME);
    systemSetup(OmniMag5)->changeConfiguration6DOF_Producer( Configuration6DOF_Producer( OmnimagnetPosition, OmnimagnetOrientation ));




    // Add Cameras after 626 setup (Important if using the Firewire cameras because it can affect the 626 card)
    cam1 = new PTGreyCamera2(12343284);
    //cam0 = new PTGreyCamera2(12343292);
    cam0 = new PTGreyCamera2(12343292);
    Timing::Timer::wait(250); // wait for cameras to initialize

    //setup Color tracker
    leftPixelLocation   = new analogVectorTimeStampedSignal("Left Pixel Location", "pixel");
    rightPixelLocation  = new analogVectorTimeStampedSignal("Right Pixel Location", "pixel");

    goal_LeftPixelLocation = new analogVectorTimeStampedSignal("Goal Left Pixel Location", "pixel");
    goal_RightPixelLocation = new analogVectorTimeStampedSignal("Goal Right Pixel Location", "pixel");

    colorTrackLeft  = new UnderwaterColorTracker();
    colorTrackLeft->colorMin(65);
    colorTrackLeft->colorMax(95);
    colorTrackLeft->FilterStDev(20);
    colorTrackLeft->addPixelSensor(leftPixelLocation);

    colorTrackRight = new UnderwaterColorTracker();
    colorTrackRight->colorMin(65);
    colorTrackRight->colorMax(95);
    colorTrackRight->FilterStDev(20);
    colorTrackRight->addPixelSensor(rightPixelLocation);

    // Load Calibration Information and World Transform
    //stereoCal = new StereoCalibration("/media/Telerobotics/code/Sandbox/CameraCalibration/currentCalFiles/fishtank_stereo_calibration.dat");
    //CameraToWorld.readTransformFromFile("/media/Telerobotics/code/Sandbox/CameraCalibration/currentCalFiles/fishtank_stereo_calibration.dat.htrans");
    stereoCal = new StereoCalibration("../Sandbox/CameraCalibration/currentCalFiles/fishtank_stereo_calibration.dat");
    CameraToWorld.readTransformFromFile("../Sandbox/CameraCalibration/currentCalFiles/fishtank_stereo_calibration.dat.htrans");
    cout << CameraToWorld << endl;

    //Determing offset distance of glass
    Math::Position camInCamera(stereoCal->setreo_translation().at<double>(0),stereoCal->setreo_translation().at<double>(1),stereoCal->setreo_translation().at<double>(2),CAMERA_FRAME,MILLIMETER);
    /*
    cout << "Cam 0 to Cam 1 in CAM: " << camInCamera << endl;
    cout << "CAM to WORLD Trans " << worldTransform.getTranslation() << endl;
    cout << "Cam 0 to Cam 1 in CAM: " << (worldTransform*camInCamera) << endl;
    */
    double z1 = -(3.03 - CameraToWorld.getTranslation().x(MILLIMETER));
    double z2 = (3.03 - (CameraToWorld*camInCamera).y(MILLIMETER));

    underwaterTriangulation = new UnderwaterOrthogonalTriangulator(*stereoCal, z1, z2);

    stereoCamera = new StereoCamera(cam0,cam1,colorTrackLeft,colorTrackRight, underwaterTriangulation, true, NULL, NULL, "Tool Location", 500);

    //stereoCamera = new StereoCamera(cam0,cam1,colorTrackLeft,colorTrackRight, stereoCal, true, NULL, NULL, "Tool Location", 500);

    // Setup Stereo Camera
    stereoCamera->start(cam0->getMaxROI(), cam1->getMaxROI(), 40, 40 );
    //Timing::Timer::wait(100);

    // Setup Tool Location
    toolLocation = new TransformedPositionProducer( CameraToWorld , stereoCamera->asPositionProducer(),500);




    // Setup Goal Pose Info
    goodDirection = new TwoOmnimagnet_SingularDirectionProducer(systemSetup(OmniMag0),systemSetup(OmniMag2),toolLocation,TwoOmnimagnet_SingularDirectionProducer::WELL_CONDITIONED);
//    goodDirection = new TwoOmnimagnet_SingularDirectionProducer(systemSetup(OmniMag2), systemSetup(OmniMag3),toolLocation,TwoOmnimagnet_SingularDirectionProducer::WELL_CONDITIONED);


    // SETUP Trajectory
    // manual
    //trajectory_PositionProducer = new Configuration5DOF_FromFile("doublecircle.csv", Configuration5DOF_FromFile::MANUAL, true, "Trajectory", METER, TRAJECTORY_FRAME, 500);
    trajectory_PositionProducer = new Configuration5DOF_FromFile("cube.csv", 1000.0/20.0, true, "Trajectory", METER, TRAJECTORY_FRAME, 500);
//    trajectory_PositionProducer = new Configuration5DOF_FromFile("cube.csv", 1000.0/40.0, true, "Trajectory", METER, TRAJECTORY_FRAME, 500);
    //trajectory_PositionProducer = new Configuration5DOF_FromFile("stationary.csv", Configuration5DOF_FromFile::MANUAL, true, "Trajectory", METER, TRAJECTORY_FRAME, 500);
    trajectory_PositionProducer->getNext(); // Get the first position
    // timed
    //trajectory_PositionProducer = new Configuration5DOF_FromFile("cube_up.csv", 10, true, "Trajectory", METER, TRAJECTORY_FRAME, 500);

    Eigen::Matrix3d val;
    val << 1, 0, 0,
           0, 1, 0,
           0, 0, 1;
    TrajectoryToWorld = Math::HomogeneousTransform(val, Math::Displacement(80, 160, 100, Math::WORLD_FRAME,MILLIMETER), TRAJECTORY_FRAME, WORLD_FRAME);

    // for pictures
    // TrajectoryToWorld = Math::HomogeneousTransform(val, Math::Displacement(80, 120, 100, Math::WORLD_FRAME,MILLIMETER), TRAJECTORY_FRAME, WORLD_FRAME);

    // Setup Goal Pose Info
    //goalLocation = new TransformedPositionProducer(TrajectoryToWorld,trajectory_PositionProducer->asPositionProducer(),200);
    //goalDirection = new DirectionProducer(Math::Direction(0,0,1,WORLD_FRAME));
    //goalDirection = new DirectionProducer(TrajectoryToWorld,trajectory_PositionProducer->asDirectionHistoryPointer())
    //goalPose = new  Configuration5DOF_Producer(goalLocation, goalDirection);
    //goalPose = new  Configuration5DOF_Producer(goalLocation,goodDirection); //TransformedConfiguration5DOF_producer(TrajectoryToWorld, tempGoalPoseProducer, 500);


    goalPose = new TransformedConfiguration5DOF_producer(TrajectoryToWorld ,trajectory_PositionProducer);
    goalLocation = goalPose ->asPositionProducer();
    //goalDirection = goalPose->asDirectionProducer();



    // SETUP MAGNETIC TOOL INFO
    DipoleMoment toolDipoleMoment(.126);  // nice pill
    // DipoleMoment toolDipoleMoment(.938);    // green monster
    // DipoleMoment toolDipoleMoment(.0586);  // little green
    // DipoleMoment toolDipoleMoment(.467);  // daddy green


    ForceVector toolWeight(0,0,-.001230, WORLD_FRAME, NEWTON); // Effective Weight given boyancy.  Can change in time from water obsorption need to modify during runs
    toolProducer = new MagneticToolProducer( toolLocation, toolDipoleMoment, goalPose, toolWeight);
    magneticTool = new SinglePerminantMagnetTool(toolProducer);


    // Multiple Omnimagnet Setup

    // F5
    std::vector< Omnimagnet* > omnimagnetPointerList = {systemSetup(OmniMag0), systemSetup(OmniMag2), systemSetup(OmniMag3), systemSetup(OmniMag4), systemSetup(OmniMag5)};

    // F4
    // std::vector< Omnimagnet* > omnimagnetPointerList = {systemSetup(OmniMag0), systemSetup(OmniMag2), systemSetup(OmniMag3), systemSetup(OmniMag5)};

    // F3
    //std::vector< Omnimagnet* > omnimagnetPointerList = {systemSetup(OmniMag0), systemSetup(OmniMag2), systemSetup(OmniMag5)};

    // 5
    // std::vector< Omnimagnet* > omnimagnetPointerList = {systemSetup(OmniMag0), systemSetup(OmniMag2), systemSetup(OmniMag3), systemSetup(OmniMag4), systemSetup(OmniMag5)};
    // 4 - yes big
    //std::vector< Omnimagnet* > omnimagnetPointerList = {systemSetup(OmniMag0), systemSetup(OmniMag2), systemSetup(OmniMag3), systemSetup(OmniMag4)};
    // 4 - no big
    //std::vector< Omnimagnet* > omnimagnetPointerList = {systemSetup(OmniMag2), systemSetup(OmniMag3), systemSetup(OmniMag4), systemSetup(OmniMag5)};
    // 3 - yes big
    //std::vector< Omnimagnet* > omnimagnetPointerList = {systemSetup(OmniMag0), systemSetup(OmniMag2), systemSetup(OmniMag3)};
    // 2 - yes big
    //std::vector< Omnimagnet* > omnimagnetPointerList = {systemSetup(OmniMag0), systemSetup(OmniMag2)};


    omnimagSystem = new MultipleOmnimagnetSystem(omnimagnetPointerList, magneticTool, MultipleOmnimagnetSystem::MINIMIZE_POWER, Math::WORLD_FRAME);


    videoWriteSignal    = new logicTimeStampedSignal("Video Write",2.5);

    // setup file logging
    fileLog = systemSetup.dataLogger;

    // add video Write Signal
    fileLog->addSignal(videoWriteSignal);
    fileLog->addSignal(leftPixelLocation);
    fileLog->addSignal(rightPixelLocation);
    fileLog->addSignal(goal_LeftPixelLocation);
    fileLog->addSignal(goal_RightPixelLocation);

    // add desired trajectory signal
    fileLog->addSignal( trajectory_PositionProducer->asPositionHistoryPointer() );
    fileLog->addSignal( goalPose->asPositionHistoryPointer() );
    fileLog->addSignal( trajectory_PositionProducer->asDirectionHistoryPointer());
    fileLog->addSignal( desiredForce );

    // add tool location
    fileLog->addSignal( toolLocation->asPositionHistoryPointer() );

    // add system inhibit signal
    fileLog->addSignal(systemSetup.inhibitSignalPointer());

    fileLog->addSignal(omnimagSystem->p_powerSignal);



    // Initialize Zero Time
    fileLog ->clearHistory();
    fileLog ->resetTimeStamp();
    fileLog ->writeAllEvery( 250 );


    cout << "Omnimagnet System Setup and Enabled.\n";

}

OmnimagSetup::~OmnimagSetup()
{
    systemSetup.inhibit();

    // Controller
    delete positionController;

    delete omnimagSystem;

    //delete omniMag2Location;

    delete magneticTool;
    delete toolProducer;
    delete toolLocation;

    delete stereoCamera;
    delete colorTrackLeft;
    delete colorTrackRight;
    delete cam0;
    delete cam1;
    delete underwaterTriangulation;
    delete stereoCal;


    delete trajectory_PositionProducer;
    delete goalPose;

    delete videoWriteSignal;

    delete leftPixelLocation;
    delete rightPixelLocation;

    delete goal_LeftPixelLocation;
    delete goal_RightPixelLocation;

    delete desiredForce;

    //delete omni2Pos;


}

void OmnimagSetup::OFF()
{
    omnimagSystem->OFF();
}
