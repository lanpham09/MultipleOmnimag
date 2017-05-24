/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jan 28 20:28:02 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "GUI/InterfaceButtons.h"
#include "GUI/Vector_Label.h"
#include "GUI/VideoDisplayWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    SwitcherButton *button_currentBias;
    QPushButton *button_camReset;
    SwitcherButton *button_Inhibit;
    SwitcherButton *button_ROI;
    QGridLayout *gridLayout_2;
    SwitcherButton *button_StartDataLogging;
    SwitcherButton *button_StartVideoRec;
    SwitcherButton *button_FindWeight;
    SwitcherButton *button_StartDemo;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    VideoDisplayWidget *leftCamera;
    VideoDisplayWidget *rightCamera;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_19;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_11;
    QDial *dial;
    QDial *dial_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_20;
    QSlider *horizontalSliderXPosition;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_21;
    QSlider *horizontalSliderYPosition;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_22;
    QSlider *horizontalSliderZPosition;
    QGridLayout *gridLayout_3;
    Vector_Label *label_ContForce;
    Vector_Label *label_ActPos;
    Vector_Label *label_ErrorPos;
    Vector_Label *label_Current_2;
    QLabel *label_14;
    Vector_Label *label_Current_1;
    QLabel *text_ErrorPos;
    QLabel *text_DesPos;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_17;
    Vector_Label *omni1_pos;
    Vector_Label *label_DesPos;
    QLabel *label_15;
    Vector_Label *label_heading;
    Vector_Label *label_Temp_2;
    Vector_Label *omni2_pos;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_13;
    QLabel *text_ActPos;
    QLabel *label_16;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    Vector_Label *label_Current_3;
    Vector_Label *label_Current_4;
    Vector_Label *label_Current_5;
    Vector_Label *label_Current_6;
    QHBoxLayout *horizontalLayout_3;
    VideoDisplayWidget *leftFilterImage;
    VideoDisplayWidget *rightFieterImage;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSlider *horizontalSliderColorMinLeft;
    QSpinBox *spinBoxColorMinLeft;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSlider *horizontalSliderColorMinRight;
    QSpinBox *spinBoxColorMinRight;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QSlider *horizontalSliderColorMaxLeft;
    QSpinBox *spinBoxColorMaxLeft;
    QLabel *label_7;
    QSlider *horizontalSliderColorMaxRight;
    QSpinBox *spinBoxColorMaxRight;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxFilter;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_12;
    SwitcherButton *button_o1_PlusX;
    SwitcherButton *button_o1_PlusY;
    SwitcherButton *button_o1_PlusZ;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_11;
    QSpinBox *spin_whichOmni;
    SwitcherButton *button_o2_PlusX;
    SwitcherButton *button_o2_PlusY;
    SwitcherButton *button_o2_PlusZ;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menuBar;
    QMenu *menuAligned_Force_Control;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(713, 914);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        button_currentBias = new SwitcherButton(centralWidget);
        button_currentBias->setObjectName(QString::fromUtf8("button_currentBias"));

        horizontalLayout_2->addWidget(button_currentBias);

        button_camReset = new QPushButton(centralWidget);
        button_camReset->setObjectName(QString::fromUtf8("button_camReset"));

        horizontalLayout_2->addWidget(button_camReset);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        button_Inhibit = new SwitcherButton(centralWidget);
        button_Inhibit->setObjectName(QString::fromUtf8("button_Inhibit"));

        gridLayout->addWidget(button_Inhibit, 4, 0, 1, 1);

        button_ROI = new SwitcherButton(centralWidget);
        button_ROI->setObjectName(QString::fromUtf8("button_ROI"));

        gridLayout->addWidget(button_ROI, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        button_StartDataLogging = new SwitcherButton(centralWidget);
        button_StartDataLogging->setObjectName(QString::fromUtf8("button_StartDataLogging"));

        gridLayout_2->addWidget(button_StartDataLogging, 1, 1, 1, 1);

        button_StartVideoRec = new SwitcherButton(centralWidget);
        button_StartVideoRec->setObjectName(QString::fromUtf8("button_StartVideoRec"));

        gridLayout_2->addWidget(button_StartVideoRec, 0, 1, 1, 1);

        button_FindWeight = new SwitcherButton(centralWidget);
        button_FindWeight->setObjectName(QString::fromUtf8("button_FindWeight"));

        gridLayout_2->addWidget(button_FindWeight, 0, 0, 1, 1);

        button_StartDemo = new SwitcherButton(centralWidget);
        button_StartDemo->setObjectName(QString::fromUtf8("button_StartDemo"));

        gridLayout_2->addWidget(button_StartDemo, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftCamera = new VideoDisplayWidget(centralWidget);
        leftCamera->setObjectName(QString::fromUtf8("leftCamera"));
        sizePolicy.setHeightForWidth(leftCamera->sizePolicy().hasHeightForWidth());
        leftCamera->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(leftCamera);

        rightCamera = new VideoDisplayWidget(centralWidget);
        rightCamera->setObjectName(QString::fromUtf8("rightCamera"));
        sizePolicy.setHeightForWidth(rightCamera->sizePolicy().hasHeightForWidth());
        rightCamera->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(rightCamera);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_19);

        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_18);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        dial = new QDial(centralWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        sizePolicy.setHeightForWidth(dial->sizePolicy().hasHeightForWidth());
        dial->setSizePolicy(sizePolicy);
        dial->setMaximum(360);
        dial->setWrapping(true);
        dial->setNotchesVisible(true);

        horizontalLayout_11->addWidget(dial);

        dial_2 = new QDial(centralWidget);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        sizePolicy.setHeightForWidth(dial_2->sizePolicy().hasHeightForWidth());
        dial_2->setSizePolicy(sizePolicy);
        dial_2->setMaximum(360);
        dial_2->setWrapping(true);
        dial_2->setNotchesVisible(true);

        horizontalLayout_11->addWidget(dial_2);


        verticalLayout_2->addLayout(horizontalLayout_11);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_13->addWidget(label_20);

        horizontalSliderXPosition = new QSlider(centralWidget);
        horizontalSliderXPosition->setObjectName(QString::fromUtf8("horizontalSliderXPosition"));
        horizontalSliderXPosition->setMinimum(-500);
        horizontalSliderXPosition->setMaximum(500);
        horizontalSliderXPosition->setSingleStep(1);
        horizontalSliderXPosition->setOrientation(Qt::Horizontal);
        horizontalSliderXPosition->setInvertedAppearance(false);
        horizontalSliderXPosition->setInvertedControls(false);
        horizontalSliderXPosition->setTickPosition(QSlider::NoTicks);

        horizontalLayout_13->addWidget(horizontalSliderXPosition);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_14->addWidget(label_21);

        horizontalSliderYPosition = new QSlider(centralWidget);
        horizontalSliderYPosition->setObjectName(QString::fromUtf8("horizontalSliderYPosition"));
        horizontalSliderYPosition->setMinimum(-500);
        horizontalSliderYPosition->setMaximum(500);
        horizontalSliderYPosition->setOrientation(Qt::Horizontal);

        horizontalLayout_14->addWidget(horizontalSliderYPosition);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_15->addWidget(label_22);

        horizontalSliderZPosition = new QSlider(centralWidget);
        horizontalSliderZPosition->setObjectName(QString::fromUtf8("horizontalSliderZPosition"));
        horizontalSliderZPosition->setMinimum(-500);
        horizontalSliderZPosition->setMaximum(500);
        horizontalSliderZPosition->setOrientation(Qt::Horizontal);

        horizontalLayout_15->addWidget(horizontalSliderZPosition);


        verticalLayout_2->addLayout(horizontalLayout_15);


        horizontalLayout->addLayout(verticalLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_ContForce = new Vector_Label(centralWidget);
        label_ContForce->setObjectName(QString::fromUtf8("label_ContForce"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ContForce->sizePolicy().hasHeightForWidth());
        label_ContForce->setSizePolicy(sizePolicy1);
        label_ContForce->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_ContForce, 4, 1, 1, 1);

        label_ActPos = new Vector_Label(centralWidget);
        label_ActPos->setObjectName(QString::fromUtf8("label_ActPos"));
        sizePolicy1.setHeightForWidth(label_ActPos->sizePolicy().hasHeightForWidth());
        label_ActPos->setSizePolicy(sizePolicy1);
        label_ActPos->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_ActPos, 2, 1, 1, 1);

        label_ErrorPos = new Vector_Label(centralWidget);
        label_ErrorPos->setObjectName(QString::fromUtf8("label_ErrorPos"));
        sizePolicy1.setHeightForWidth(label_ErrorPos->sizePolicy().hasHeightForWidth());
        label_ErrorPos->setSizePolicy(sizePolicy1);
        label_ErrorPos->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_ErrorPos, 3, 1, 1, 1);

        label_Current_2 = new Vector_Label(centralWidget);
        label_Current_2->setObjectName(QString::fromUtf8("label_Current_2"));
        label_Current_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_Current_2, 8, 1, 1, 1);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_14, 0, 0, 1, 1);

        label_Current_1 = new Vector_Label(centralWidget);
        label_Current_1->setObjectName(QString::fromUtf8("label_Current_1"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_Current_1->sizePolicy().hasHeightForWidth());
        label_Current_1->setSizePolicy(sizePolicy2);
        label_Current_1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_Current_1, 7, 1, 1, 1);

        text_ErrorPos = new QLabel(centralWidget);
        text_ErrorPos->setObjectName(QString::fromUtf8("text_ErrorPos"));
        sizePolicy1.setHeightForWidth(text_ErrorPos->sizePolicy().hasHeightForWidth());
        text_ErrorPos->setSizePolicy(sizePolicy1);
        text_ErrorPos->setFont(font);
        text_ErrorPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(text_ErrorPos, 3, 0, 1, 1);

        text_DesPos = new QLabel(centralWidget);
        text_DesPos->setObjectName(QString::fromUtf8("text_DesPos"));
        sizePolicy1.setHeightForWidth(text_DesPos->sizePolicy().hasHeightForWidth());
        text_DesPos->setSizePolicy(sizePolicy1);
        text_DesPos->setFont(font);
        text_DesPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(text_DesPos, 1, 0, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 14, 0, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_9, 4, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 7, 0, 1, 1);

        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_17, 6, 0, 1, 1);

        omni1_pos = new Vector_Label(centralWidget);
        omni1_pos->setObjectName(QString::fromUtf8("omni1_pos"));
        omni1_pos->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(omni1_pos, 5, 1, 1, 1);

        label_DesPos = new Vector_Label(centralWidget);
        label_DesPos->setObjectName(QString::fromUtf8("label_DesPos"));
        sizePolicy1.setHeightForWidth(label_DesPos->sizePolicy().hasHeightForWidth());
        label_DesPos->setSizePolicy(sizePolicy1);
        label_DesPos->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_DesPos, 1, 1, 1, 1);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_15, 5, 0, 1, 1);

        label_heading = new Vector_Label(centralWidget);
        label_heading->setObjectName(QString::fromUtf8("label_heading"));
        label_heading->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_heading, 0, 1, 1, 1);

        label_Temp_2 = new Vector_Label(centralWidget);
        label_Temp_2->setObjectName(QString::fromUtf8("label_Temp_2"));
        label_Temp_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_Temp_2, 13, 1, 1, 1);

        omni2_pos = new Vector_Label(centralWidget);
        omni2_pos->setObjectName(QString::fromUtf8("omni2_pos"));
        omni2_pos->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(omni2_pos, 6, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy3);
        doubleSpinBox->setDecimals(7);
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.0001);

        gridLayout_3->addWidget(doubleSpinBox, 14, 1, 1, 1);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 13, 0, 1, 1);

        text_ActPos = new QLabel(centralWidget);
        text_ActPos->setObjectName(QString::fromUtf8("text_ActPos"));
        sizePolicy1.setHeightForWidth(text_ActPos->sizePolicy().hasHeightForWidth());
        text_ActPos->setSizePolicy(sizePolicy1);
        text_ActPos->setFont(font);
        text_ActPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(text_ActPos, 2, 0, 1, 1);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_16, 8, 0, 1, 1);

        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_3->addWidget(label_23, 9, 0, 1, 1);

        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_3->addWidget(label_24, 10, 0, 1, 1);

        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_3->addWidget(label_25, 11, 0, 1, 1);

        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_3->addWidget(label_26, 12, 0, 1, 1);

        label_Current_3 = new Vector_Label(centralWidget);
        label_Current_3->setObjectName(QString::fromUtf8("label_Current_3"));
        label_Current_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_Current_3, 9, 1, 1, 1);

        label_Current_4 = new Vector_Label(centralWidget);
        label_Current_4->setObjectName(QString::fromUtf8("label_Current_4"));
        label_Current_4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_Current_4, 10, 1, 1, 1);

        label_Current_5 = new Vector_Label(centralWidget);
        label_Current_5->setObjectName(QString::fromUtf8("label_Current_5"));
        label_Current_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_Current_5, 11, 1, 1, 1);

        label_Current_6 = new Vector_Label(centralWidget);
        label_Current_6->setObjectName(QString::fromUtf8("label_Current_6"));
        label_Current_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_Current_6, 12, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        leftFilterImage = new VideoDisplayWidget(centralWidget);
        leftFilterImage->setObjectName(QString::fromUtf8("leftFilterImage"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(50);
        sizePolicy4.setVerticalStretch(50);
        sizePolicy4.setHeightForWidth(leftFilterImage->sizePolicy().hasHeightForWidth());
        leftFilterImage->setSizePolicy(sizePolicy4);
        leftFilterImage->setSizeIncrement(QSize(100, 100));
        leftFilterImage->setBaseSize(QSize(400, 400));

        horizontalLayout_3->addWidget(leftFilterImage);

        rightFieterImage = new VideoDisplayWidget(centralWidget);
        rightFieterImage->setObjectName(QString::fromUtf8("rightFieterImage"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(50);
        sizePolicy5.setVerticalStretch(50);
        sizePolicy5.setHeightForWidth(rightFieterImage->sizePolicy().hasHeightForWidth());
        rightFieterImage->setSizePolicy(sizePolicy5);
        rightFieterImage->setSizeIncrement(QSize(100, 100));
        rightFieterImage->setBaseSize(QSize(400, 400));

        horizontalLayout_3->addWidget(rightFieterImage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(label_6);

        horizontalSliderColorMinLeft = new QSlider(centralWidget);
        horizontalSliderColorMinLeft->setObjectName(QString::fromUtf8("horizontalSliderColorMinLeft"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(horizontalSliderColorMinLeft->sizePolicy().hasHeightForWidth());
        horizontalSliderColorMinLeft->setSizePolicy(sizePolicy6);
        horizontalSliderColorMinLeft->setMaximum(255);
        horizontalSliderColorMinLeft->setValue(80);
        horizontalSliderColorMinLeft->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSliderColorMinLeft);

        spinBoxColorMinLeft = new QSpinBox(centralWidget);
        spinBoxColorMinLeft->setObjectName(QString::fromUtf8("spinBoxColorMinLeft"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(spinBoxColorMinLeft->sizePolicy().hasHeightForWidth());
        spinBoxColorMinLeft->setSizePolicy(sizePolicy7);
        spinBoxColorMinLeft->setMaximum(255);
        spinBoxColorMinLeft->setValue(80);

        horizontalLayout_8->addWidget(spinBoxColorMinLeft);


        horizontalLayout_4->addLayout(horizontalLayout_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(1);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(label_5);

        horizontalSliderColorMinRight = new QSlider(centralWidget);
        horizontalSliderColorMinRight->setObjectName(QString::fromUtf8("horizontalSliderColorMinRight"));
        sizePolicy6.setHeightForWidth(horizontalSliderColorMinRight->sizePolicy().hasHeightForWidth());
        horizontalSliderColorMinRight->setSizePolicy(sizePolicy6);
        horizontalSliderColorMinRight->setMaximum(255);
        horizontalSliderColorMinRight->setValue(78);
        horizontalSliderColorMinRight->setSliderPosition(78);
        horizontalSliderColorMinRight->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSliderColorMinRight);

        spinBoxColorMinRight = new QSpinBox(centralWidget);
        spinBoxColorMinRight->setObjectName(QString::fromUtf8("spinBoxColorMinRight"));
        sizePolicy3.setHeightForWidth(spinBoxColorMinRight->sizePolicy().hasHeightForWidth());
        spinBoxColorMinRight->setSizePolicy(sizePolicy3);
        spinBoxColorMinRight->setMinimum(0);
        spinBoxColorMinRight->setMaximum(255);
        spinBoxColorMinRight->setValue(80);

        horizontalLayout_7->addWidget(spinBoxColorMinRight);


        verticalLayout_5->addLayout(horizontalLayout_7);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_4->addLayout(horizontalLayout_4);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(1);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(label_8);

        horizontalSliderColorMaxLeft = new QSlider(centralWidget);
        horizontalSliderColorMaxLeft->setObjectName(QString::fromUtf8("horizontalSliderColorMaxLeft"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(horizontalSliderColorMaxLeft->sizePolicy().hasHeightForWidth());
        horizontalSliderColorMaxLeft->setSizePolicy(sizePolicy8);
        horizontalSliderColorMaxLeft->setMaximum(255);
        horizontalSliderColorMaxLeft->setValue(80);
        horizontalSliderColorMaxLeft->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(horizontalSliderColorMaxLeft);

        spinBoxColorMaxLeft = new QSpinBox(centralWidget);
        spinBoxColorMaxLeft->setObjectName(QString::fromUtf8("spinBoxColorMaxLeft"));
        sizePolicy3.setHeightForWidth(spinBoxColorMaxLeft->sizePolicy().hasHeightForWidth());
        spinBoxColorMaxLeft->setSizePolicy(sizePolicy3);
        spinBoxColorMaxLeft->setMaximum(255);
        spinBoxColorMaxLeft->setValue(90);

        horizontalLayout_10->addWidget(spinBoxColorMaxLeft);


        horizontalLayout_9->addLayout(horizontalLayout_10);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(label_7);

        horizontalSliderColorMaxRight = new QSlider(centralWidget);
        horizontalSliderColorMaxRight->setObjectName(QString::fromUtf8("horizontalSliderColorMaxRight"));
        sizePolicy8.setHeightForWidth(horizontalSliderColorMaxRight->sizePolicy().hasHeightForWidth());
        horizontalSliderColorMaxRight->setSizePolicy(sizePolicy8);
        horizontalSliderColorMaxRight->setMaximum(255);
        horizontalSliderColorMaxRight->setValue(90);
        horizontalSliderColorMaxRight->setSliderPosition(90);
        horizontalSliderColorMaxRight->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSliderColorMaxRight);

        spinBoxColorMaxRight = new QSpinBox(centralWidget);
        spinBoxColorMaxRight->setObjectName(QString::fromUtf8("spinBoxColorMaxRight"));
        sizePolicy3.setHeightForWidth(spinBoxColorMaxRight->sizePolicy().hasHeightForWidth());
        spinBoxColorMaxRight->setSizePolicy(sizePolicy3);
        spinBoxColorMaxRight->setMaximum(255);
        spinBoxColorMaxRight->setValue(90);

        horizontalLayout_9->addWidget(spinBoxColorMaxRight);


        verticalLayout_6->addLayout(horizontalLayout_9);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        doubleSpinBoxFilter = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxFilter->setObjectName(QString::fromUtf8("doubleSpinBoxFilter"));
        doubleSpinBoxFilter->setValue(20);

        horizontalLayout_6->addWidget(doubleSpinBoxFilter);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_12);

        button_o1_PlusX = new SwitcherButton(centralWidget);
        button_o1_PlusX->setObjectName(QString::fromUtf8("button_o1_PlusX"));

        verticalLayout_7->addWidget(button_o1_PlusX);

        button_o1_PlusY = new SwitcherButton(centralWidget);
        button_o1_PlusY->setObjectName(QString::fromUtf8("button_o1_PlusY"));

        verticalLayout_7->addWidget(button_o1_PlusY);

        button_o1_PlusZ = new SwitcherButton(centralWidget);
        button_o1_PlusZ->setObjectName(QString::fromUtf8("button_o1_PlusZ"));

        verticalLayout_7->addWidget(button_o1_PlusZ);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(label_11);

        spin_whichOmni = new QSpinBox(centralWidget);
        spin_whichOmni->setObjectName(QString::fromUtf8("spin_whichOmni"));
        spin_whichOmni->setMaximum(6);

        horizontalLayout_16->addWidget(spin_whichOmni);


        verticalLayout_7->addLayout(horizontalLayout_16);

        button_o2_PlusX = new SwitcherButton(centralWidget);
        button_o2_PlusX->setObjectName(QString::fromUtf8("button_o2_PlusX"));

        verticalLayout_7->addWidget(button_o2_PlusX);

        button_o2_PlusY = new SwitcherButton(centralWidget);
        button_o2_PlusY->setObjectName(QString::fromUtf8("button_o2_PlusY"));

        verticalLayout_7->addWidget(button_o2_PlusY);

        button_o2_PlusZ = new SwitcherButton(centralWidget);
        button_o2_PlusZ->setObjectName(QString::fromUtf8("button_o2_PlusZ"));

        verticalLayout_7->addWidget(button_o2_PlusZ);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 713, 25));
        menuAligned_Force_Control = new QMenu(menuBar);
        menuAligned_Force_Control->setObjectName(QString::fromUtf8("menuAligned_Force_Control"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuAligned_Force_Control->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderColorMaxRight, SIGNAL(valueChanged(int)), spinBoxColorMaxRight, SLOT(setValue(int)));
        QObject::connect(horizontalSliderColorMinRight, SIGNAL(valueChanged(int)), spinBoxColorMinRight, SLOT(setValue(int)));
        QObject::connect(spinBoxColorMaxRight, SIGNAL(valueChanged(int)), horizontalSliderColorMaxRight, SLOT(setValue(int)));
        QObject::connect(spinBoxColorMinRight, SIGNAL(valueChanged(int)), horizontalSliderColorMinRight, SLOT(setValue(int)));
        QObject::connect(horizontalSliderColorMaxLeft, SIGNAL(valueChanged(int)), spinBoxColorMaxLeft, SLOT(setValue(int)));
        QObject::connect(horizontalSliderColorMinLeft, SIGNAL(valueChanged(int)), spinBoxColorMinLeft, SLOT(setValue(int)));
        QObject::connect(spinBoxColorMinLeft, SIGNAL(valueChanged(int)), horizontalSliderColorMinLeft, SLOT(setValue(int)));
        QObject::connect(spinBoxColorMaxLeft, SIGNAL(valueChanged(int)), horizontalSliderColorMaxLeft, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        button_currentBias->setText(QApplication::translate("MainWindow", "Zero Current", 0, QApplication::UnicodeUTF8));
        button_camReset->setText(QApplication::translate("MainWindow", "Reset Cameras", 0, QApplication::UnicodeUTF8));
        button_Inhibit->setText(QApplication::translate("MainWindow", "INHIBIT", 0, QApplication::UnicodeUTF8));
        button_ROI->setText(QApplication::translate("MainWindow", "ROI", 0, QApplication::UnicodeUTF8));
        button_StartDataLogging->setText(QApplication::translate("MainWindow", "Start Data Logging", 0, QApplication::UnicodeUTF8));
        button_StartVideoRec->setText(QApplication::translate("MainWindow", "Start Video", 0, QApplication::UnicodeUTF8));
        button_FindWeight->setText(QApplication::translate("MainWindow", "Determine Tool Weight", 0, QApplication::UnicodeUTF8));
        button_StartDemo->setText(QApplication::translate("MainWindow", "Exicute Trajectory", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Phi", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Theta", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label_ContForce->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_ActPos->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_ErrorPos->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_Current_2->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Desired Heading:", 0, QApplication::UnicodeUTF8));
        label_Current_1->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        text_ErrorPos->setText(QApplication::translate("MainWindow", "Error In Position:", 0, QApplication::UnicodeUTF8));
        text_DesPos->setText(QApplication::translate("MainWindow", "Desired Position:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Tool Weight:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Control Force:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Omnimag 1 Currents:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Omnimagnet 2 Position:", 0, QApplication::UnicodeUTF8));
        omni1_pos->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_DesPos->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Omnimagnet 1 Position:", 0, QApplication::UnicodeUTF8));
        label_heading->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_Temp_2->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        omni2_pos->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Omnimagnet 2 Temp:", 0, QApplication::UnicodeUTF8));
        text_ActPos->setText(QApplication::translate("MainWindow", "Actual Position:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Omnimagnet 2 Currents:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Omnimag 3 Currents", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "Omnimag 4 Currents", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "Omnimag 5 Currents", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "Omnimag 6 Currents", 0, QApplication::UnicodeUTF8));
        label_Current_3->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_Current_4->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_Current_5->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_Current_6->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Color Min ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Color Max", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Filtter StDev", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Omnimagent 1", 0, QApplication::UnicodeUTF8));
        button_o1_PlusX->setText(QApplication::translate("MainWindow", "Plus X", 0, QApplication::UnicodeUTF8));
        button_o1_PlusY->setText(QApplication::translate("MainWindow", "Plus Y", 0, QApplication::UnicodeUTF8));
        button_o1_PlusZ->setText(QApplication::translate("MainWindow", "Plus Z", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Omnimagnet:  ", 0, QApplication::UnicodeUTF8));
        button_o2_PlusX->setText(QApplication::translate("MainWindow", "Plus X", 0, QApplication::UnicodeUTF8));
        button_o2_PlusY->setText(QApplication::translate("MainWindow", "Plus Y", 0, QApplication::UnicodeUTF8));
        button_o2_PlusZ->setText(QApplication::translate("MainWindow", "Plus Z", 0, QApplication::UnicodeUTF8));
        menuAligned_Force_Control->setTitle(QApplication::translate("MainWindow", "Aligned Force Control", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
