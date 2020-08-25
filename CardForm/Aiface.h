#ifndef AIFACE_H
#define AIFACE_H

#include <QObject>
#include <QImage>
#include <QThread>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "THFaceImage_i.h"
#include "THFeature_i.h"

#define AIFACE_IS_RUNNING  11
#define CARD_ERROR_NO_FACE 12
#define PEOPLE_ERROR_NO_FACE 13
#define CARD_FEATURE_READY 14
#define PEOPLE_FEATURE_READY 15
#define AIFACE_INIT 16
#define AIFACE_SUCCESS 17
#define AIFACE_NOFACE_ERROR 18
#define AIFACE_CLOSE 101
#define AIFACE_WAITING 102
#define AIFACE_READY 100
#define AIFACE_FEATURE_READY 103

class DetectThread;
class AiFace : public QThread
{
    Q_OBJECT
public:
    AiFace();
    ~AiFace();
    bool InitAiFace();
    void InitFeature();
    void ReleaseFeature();
    void ReleaseAiFace();
    void SetImage(cv::Mat card,cv::Mat people);
    int PrePeopleFeature();
    int PreCardFeature();
    cv::Mat GetCropFace();
    float GetsimResult();
    QImage MatToQImage(cv::Mat mat);
signals:
    void sendAiFaceResult(int status);
private slots:
    void handleDetectResult(int status);
private:
    int aifaceStatus;
    THFI_Param param;
    BYTE* cardFeature;
    BYTE* peopleFeature;
    int featureSize;
    cv::Mat cardImage;
    cv::Mat peopleImage;
    cv::Mat cropFace;
    DetectThread *detectThread;
    float simResult;
    void run();

};
class DetectThread : public QThread
{
    Q_OBJECT
public:
    DetectThread(AiFace *aiface);
signals:
    void sendDetectStatus(int status);
private:
    AiFace *aiface;
    void run();
};
#endif // AIFACE_H
