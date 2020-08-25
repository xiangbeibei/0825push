#ifndef CONTROLCAMERA_H
#define CONTROLCAMERA_H

#include <QThread>
#include <QImage>
#include <QMutex>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif

#define CAMERA_CLOSE 107
#define CAMERA_SUSPEND 108
#define CAMERA_READY 0
/*
 * 对摄像头采集的图像的处理
 * 摄像头获取的视频流有 4:3  16:9两种
 * 需要在中心区域截取4:3比例,然后显示或保存
 *
 * 因此使用Opencv不使用 QCamera
 */
class ControlCamera : public QThread
{
    Q_OBJECT
public:
    ControlCamera(int width,int height);
    ~ControlCamera();
    bool startCamera();
    bool stopCamera(int status);
    cv::Mat captureCamera();
    void setCameraExposure(float CameraExposure);

signals:
    void sendFrame(QImage frame);
    void sendCameraStatus(int status);

private:
    //线程是否退出
    bool isExit;
    QMutex mutex;
    int camerastatus;
    int width , height;
    cv::VideoCapture *cameraCapture;
    cv::Mat cameraFrame;//视频读入矩阵
    float CameraExposure;

    void run();
    QImage MatToQImage(cv::Mat mat);
};

#endif // CONTROLCAMERA_H
