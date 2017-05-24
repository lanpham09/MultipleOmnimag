#-------------------------------------------------
#
# Project created by QtCreator 2013-10-02T15:18:37
#
#-------------------------------------------------

QT       += core gui

TARGET = MultipleOmnimag
TEMPLATE = app
OBJECTS_DIR = ./BIN/
MOC_DIR = ./BIN/
QMAKE_CXXFLAGS	 += -g -Wall -std=c++0x
QT += opengl

CONFIG += debug

DEPENDPATH += 	../Sandbox/ \
                #/media/Telerobotics/code/Sandbox\

INCLUDEPATH += 	/usr/local/include/opencv\
                /usr/local/include/opencv2\
                /usr/include/flycapture\
                /usr/local/include\
                /usr/include\
                /usr/local/DAQ\
                /usr/local/include/usbhid\
                ../Sandbox/ \
                #/media/Telerobotics/code/Sandbox\

LIBS += -L/usr/local/DAQ\
        -L/usr/local/lib\
        -L/usr/lib\
        -L../OmnimagnetLibs/AD_IO_Lib \
        -L../OmnimagnetLibs/Math_Lib \
        -L../OmnimagnetLibs/Producer_Lib \
        -lopencv_imgproc\
        -lopencv_highgui\
        -lopencv_core\
        -lopencv_calib3d\
        -lopencv_video\
        -ls626\
        -ldc1394\
        -lflycapture\
        -lcomedi\
        -lmccusb\
        -lAD_IO\
        -lMath\
        -lProducer\


SOURCES += main.cpp\
        mainwindow.cpp\
        CameraCalibration/CheckerBoardPattern.cpp\
        CameraCalibration/MonoCalibration.cpp \
        CameraCalibration/StereoCalibration.cpp \
        Controls/DiscreteController.cpp\
        Controls/DiscreteFilter.cpp\
        Demos/Aligned_Position_Control_Demo.cpp\
        Demos/Single_Omnimag_Setup_Art.cpp\
        Demos/Demo.cpp\
        Devices/AMC_S16A8.cpp\
        Devices/Omnimagnet.cpp\
        Devices/Sensoray_626_Card.cpp\
        GUI/VideoDisplayWidget.cpp \
        GUI/Vector_Label.cpp \
        GUI/StereoVideoWindow.cpp \
        #GUI/PointSelectWindow.cpp \
        GUI/NumberWithUnits.cpp \
        GUI/InterfaceButtons.cpp \
        Utilities/KeyListener.cpp\
        Utilities/Magnetics.cpp\
        Utilities/Mutex.cpp\
        Utilities/precisionCalendar.cpp\
        Utilities/RingBufferIndex.cpp\
        Utilities/Thread.cpp\
        Utilities/Timer.cpp\
        Utilities/SerialPort.cpp\
        Vision/ColorTracker.cpp\
        Vision/MonoCamera.cpp\
        Vision/StereoCamera.cpp \
        Vision/UniversalTriangulator.cpp\
        Vision/UnderwaterColorTracker.cpp\
        Vision/UnderwaterOrthogonalTriangulator.cpp\
        Vision/VisionMethod.cpp \
        Devices/sensorayCardEmulator.cpp \
        Devices/PTGreyCamera2.cpp \
        Devices/MultipleOmnimagnetSystem.cpp \
        Devices/ArduinoSerialPosition.cpp \
        Devices/AMC_30A8.cpp \
        Devices/Advantech_PCI_1724U_ADIO.cpp \
        Devices/Advantech_PCI_1724U.cpp \
        Demos/Field_and_Force_Demo.cpp \
        OmnimagSetup.cpp \
        Vision/TriangulationMethod.cpp \
        Devices/MultipleOmnimagnetSetup.cpp\
        Utilities/Units/angleUnits.cpp






HEADERS  += mainwindow.h\
        CameraCalibration/CheckerBoardPattern.h \
        CameraCalibration/Patterns.h\
        CameraCalibration/MonoCalibration.h \
        CameraCalibration/StereoCalibration.h \
        Controls/controller.h\
        Controls/DiscreteController.h\
        Controls/DiscreteFilter.h\
        Demos/Aligned_Position_Control_Demo.h\
        Demos/Single_Omnimag_Setup_Art.h\
        Demos/Demo.h\
        Devices/AMC_S16A8.h\
        Devices/Omnimagnet.h\
        Devices/Sensoray_626_Card.h\
        GUI/VideoDisplayWidget.h \
        GUI/Vector_Label.h \
        GUI/StereoVideoWindow.h \
        #GUI/PointSelectWindow.h \
        GUI/NumberWithUnits.h \
        GUI/InterfaceButtons.h \
        Producers/Producers.h\
        Utilities/Filters.h\
        Utilities/KeyListener.h\
        Utilities/Magnetics.h\
        Utilities/Mutex.h\
        Utilities/precisionCalendar.h\
        Utilities/RingBufferIndex.h\
        Utilities/Thread.h\
        Utilities/ThreadCommunicator.h\
        Utilities/Timer.h\
        Utilities/utilities.h\
        Utilities/SerialPort.h\
        Vision/Camera.h\
        Vision/ColorTracker.h\
        Vision/MonoCamera.h\
        Vision/StereoCamera.h \
        Vision/TrackingMethod.h\
        Vision/TriangulationMethod.h\
        Vision/UniversalTriangulator.h \
        Vision/UnderwaterColorTracker.h\
        Vision/UnderwaterOrthogonalTriangulator.h \
        Vision/VisionMethod.h \
        Devices/sensorayCardEmulator.h \
        Devices/PTGreyCamera2.h \
        OmnimagSetup.h \
        Devices/MultipleOmnimagnetSystem.h \
        Devices/ArduinoSerialPosition.h \
        Devices/AMC_30A8.h \
        Devices/Advantech_PCI_1724U_ADIO.h \
        Devices/Advantech_PCI_1724U.h \
        Utilities/Units.h \
        Demos/Field_and_Force_Demo.h \
        Devices/MC_USB_TC.h \
        Devices/MultipleOmnimagnetSetup.h\\




FORMS    += mainwindow.ui \

OTHER_FILES += \
        AD_IO/Makefile \

