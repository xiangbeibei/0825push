#include "ControlCamera.h"
#include <QDebug>

using namespace cv;
ControlCamera::ControlCamera(int width, int height)
{
    this->width = width;
    this->height = height;
    this->isExit = false;

    this->cameraCapture = new cv::VideoCapture();
}

ControlCamera::~ControlCamera()
{
    if(cameraCapture != NULL)
        delete cameraCapture;
}

//启动相机
bool ControlCamera::startCamera()
{
    bool success = true;
    camerastatus = CAMERA_READY;
    if(!cameraCapture->isOpened())
        success = cameraCapture->open(0);

    if(success && !this->isRunning())
    {
        this->isExit = false;
        this->start();
    }
    return success;
}

//关闭相机
bool ControlCamera::stopCamera(int status)
{
    this->isExit = true;
    camerastatus = status;
    return this->isExit;
}
void ControlCamera::setCameraExposure(float CameraExposure)
{
    this->CameraExposure = CameraExposure;
}

//抓取一帧图像
cv::Mat ControlCamera::captureCamera()
{
    cv::Mat captureFrame;
    mutex.lock();
    captureFrame = cameraFrame.clone();
    mutex.unlock();
    return captureFrame;
}

//线程处理函数
void ControlCamera::run()
{
    while(true)
    {
        if(isExit)
        {
            cameraCapture->release();
            sendCameraStatus(camerastatus);
            break;
        }

        mutex.lock();
//        cameraCapture->read(cameraFrame);
        *cameraCapture >> cameraFrame;
        mutex.unlock();
        /*
         * 将一帧图像裁剪到对应的长、宽
         */
        if((cameraFrame.rows/9)==(cameraFrame.cols/16))
        {
            int frame_row = 0;//4:3宽
            int frame_col = 0;//4:3长
            int frame_x = 0;//截取起点横坐标
            int frame_y = 0;//截取起点纵坐标
            //计算截取区域
            frame_row = cameraFrame.rows / 3;
            frame_col = frame_row * 4;
            frame_x = (cameraFrame.cols-frame_col) / 2;

            cv::Rect cropRect(frame_x,frame_y,frame_col,frame_row);
            cameraFrame = cameraFrame(cropRect);
        }
        if(!isExit)
            emit sendFrame(MatToQImage(cameraFrame));
    }
}

//Opencv Mat 转换为Qimage
QImage ControlCamera::MatToQImage(cv::Mat mat)
{
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    else if(mat.type() == CV_8UC3)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
        return QImage();
}
