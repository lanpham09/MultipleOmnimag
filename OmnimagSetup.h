#ifndef OMNIMAGSETUP_H
#define OMNIMAGSETUP_H

#include "Devices/MultipleOmnimagnetSetup.h"

#include "Devices/ArduinoSerialPosition.h"
#include "Devices/MultipleOmnimagnetSystem.h"
#include "Devices/PTGreyCamera2.h"

#include "AD_IO/AD_IO.h"

#include "Utilities/Timer.h"
#include "Utilities/Math.h"

#include "Producers/MagneticToolProducer.h"
#include "Producers/Configuration5DOF_FromFile.h"
#include "Producers/Configuration5DOF_Producer.h"
#include "Producers/ConstantPositionProducer.h"
#include "Producers/TransformedPositionProducer.h"
#include "Producers/TransformedConfiguration5DOF_Producer.h"
#include "Producers/SinglePerminantMagnetTool.h"
#include "Producers/TwoOmnimagnet_SingularDirectionProducer.h"

#include "Controls/DiscreteController.h"

#include "Vision/StereoCamera.h"
#include "Vision/UnderwaterColorTracker.h"
#include "Vision/UnderwaterOrthogonalTriangulator.h"

#include "CameraCalibration/StereoCalibration.h"




class OmnimagSetup {
public:

    // Omnimagnets and System
    MultipleOmnimagnetSetup systemSetup;
    fileLogger* fileLog;
    deviceInhibit* systemInhibit;
    autoInhibit* systemAutoInhibit;
    MultipleOmnimagnetSystem* omnimagSystem;

    OmnimagSetup();
    ~OmnimagSetup();

    void OFF();

    // Producers
    //TransformedPositionProducer* omniMag2Location;
    DirectionProducer* goalDirection;
    TransformedPositionProducer* toolLocation;
    MagneticToolProducer* toolProducer;
    PositionProducer* goalLocation;
    TransformedConfiguration5DOF_producer* goalPose;
    SinglePerminantMagnetTool* magneticTool;
    TwoOmnimagnet_SingularDirectionProducer* goodDirection;

    // Transforms
    HomogeneousTransform TrajectoryToWorld;
    HomogeneousTransform CameraToWorld;

    // Controller
    DiscreteVectorController* positionController;

    // trajectory
    Configuration5DOF_FromFile* trajectory_PositionProducer;


    // Analog Input/Output Cards
    //ArduinoSerialPosition* omni2Pos;


    // Vision
    PTGreyCamera2* cam0;
    PTGreyCamera2* cam1;
    StereoCamera* stereoCamera;
    StereoCalibration* stereoCal;
    UnderwaterColorTracker* colorTrackLeft;
    UnderwaterColorTracker* colorTrackRight;
    UnderwaterOrthogonalTriangulator* underwaterTriangulation;


    // MISC Sensors & Signals
    logicTimeStampedSignal* videoWriteSignal;

    analogVectorTimeStampedSignal* leftPixelLocation;
    analogVectorTimeStampedSignal* rightPixelLocation;

    analogVectorTimeStampedSignal* goal_LeftPixelLocation;
    analogVectorTimeStampedSignal* goal_RightPixelLocation;

    analogVectorTimeStampedSignal* desiredForce;
    AD_IO::analogSensor*  p_powerSignal;

};


#endif // OMNIMAGSETUP_H
