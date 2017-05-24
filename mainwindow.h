#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector2D>
#include <QCloseEvent>

#include "OmnimagSetup.h"

#include "Demos/Field_and_Force_Demo.h"
#include "Producers/TransformedConfiguration5DOF_Producer.h"
#include "Producers/ConstantPositionProducer.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <sstream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void clean();

protected:
        void closeEvent(QCloseEvent *event);

    signals:
        void globalExitSender();

public slots:
    void updateDisplayValues();
    void startWeightCalibrationMode();
    void startTrajectoryMode();
    void startDataLogging();
    void startVideoRecording();

    void plusXMoment1();
    void plusYMoment1();
    void plusZMoment1();
    void plusXMoment2();
    void plusYMoment2();
    void plusZMoment2();

    void inhibit();
    void ROI();
    void camReset();
    void setWeight(double);

    void setColorMinLeft(int val);
    void setColorMaxLeft(int val);
    void setColorMinRight(int val);
    void setColorMaxRight(int val);
    void setFilterStDev( double val);

    void updateRightPoint();
    void updateLeftPoint();

    void updateDemoProperties();

    void changeGoalDirection();
    void changeGoalPosition();

private:
    Ui::MainWindow *ui;

    QTimer *update_timer;
    QTimer *goal_timer;

    OmnimagSetup*   thisSetup;

    Field_and_Force_Demo* thisDemo;

    ConstantPositionProducer* constPosition;

    enum MODE{WEIGHT, TRAJECTORY, NOTSET} mode;

    cv::VideoWriter* video_recorderRT;
    cv::VideoWriter* video_recorderLFT;
    cv::Mat capture_image_one; // Left Camera Image
    cv::Mat capture_image_two; // Right Camera Image

    cv::Mat display_image_one;
    cv::Mat display_image_two;
    cv::Size displaySize;

    cv::Mat capture_image_oneFilter; // Left Camera Image
    cv::Mat capture_image_twoFilter; // Right Camera Im

};

#endif // MAINWINDOW_H
