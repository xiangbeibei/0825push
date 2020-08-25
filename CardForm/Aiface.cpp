#include "Aiface.h"


AiFace::AiFace()
{
    detectThread = new DetectThread(this);
    connect(detectThread,SIGNAL(sendDetectStatus(int)),SLOT(handleDetectResult(int)));
}

AiFace::~AiFace()
{
    delete detectThread;

}
//初始化人脸库
bool AiFace::InitAiFace()
{
    param.nMinFaceSize = 50;
    param.nRollAngle = 45;
    param.bOnlyDetect = true;
    int create_ret = THFI_Create(2, &param);
    if(create_ret != 2)
        return false;
    int EF_ret = EF_Init(2);
    if (EF_ret != 2)
    {
        return false;
    }
    return true;
}
//释放人脸库
void AiFace::ReleaseAiFace()
{
    EF_Release();
    THFI_Release();
}
//申请人脸库所需的空间
void AiFace::InitFeature()
{
    featureSize = EF_Size();
    cardFeature = new BYTE[featureSize];
    peopleFeature = new BYTE[featureSize];
    aifaceStatus = AIFACE_WAITING;
    this->start();
    simResult = 0.0;
}
//处理检测线程槽
void AiFace::handleDetectResult(int status)
{
    emit sendAiFaceResult(status);
}
//释放人脸库所需的空间
void AiFace::ReleaseFeature()
{
    if(peopleFeature)
        delete[]peopleFeature;
    if(cardFeature)
        delete[]cardFeature;
    aifaceStatus = AIFACE_CLOSE;
    msleep(100);
    simResult = 0.0;
}
//获取比对人脸
void AiFace::SetImage(cv::Mat card, cv::Mat people)
{
    cardImage = card;
    peopleImage = people;
    aifaceStatus = AIFACE_READY;
}
//线程函数，准备身份证件照特征
void AiFace::run()
{
    while(true)
    {
        if(aifaceStatus == AIFACE_CLOSE)
            return;
        if(aifaceStatus == AIFACE_WAITING)
        {
            msleep(100);
            continue;
        }
        if(aifaceStatus == AIFACE_READY)
        {
            int card_ret = PreCardFeature();
            int people_ret = PrePeopleFeature();
            if(card_ret == CARD_FEATURE_READY && people_ret == PEOPLE_FEATURE_READY)
            {
                emit sendAiFaceResult(AIFACE_FEATURE_READY);
            }
            else
            {
                emit sendAiFaceResult(AIFACE_NOFACE_ERROR);
            }
            aifaceStatus = AIFACE_WAITING;
        }
    }
}
//获取身份证头像特征
int AiFace::PreCardFeature()
{
    qDebug()<<"start card detect";
    memset(cardFeature,0,featureSize);
    if(cardImage.empty())
    {
        cardImage.release();
        return CARD_ERROR_NO_FACE;
    }
    int cardWidth = cardImage.cols;
    int cardHeight = cardImage.rows;
    THFI_FacePos ptfp[1];
    ptfp[0].dwReserved = (DWORD)new BYTE[512];
    int nFace = THFI_DetectFace(1,cardImage.data,24,cardWidth,cardHeight,ptfp,1);
    if(nFace > 0)
    {
        qDebug()<<"start card 1";
        int ret = EF_Extract(1,cardImage.data,cardWidth,cardHeight,3,(DWORD)&ptfp[0],cardFeature);
        if(ret !=1 )
        {
            memset(cardFeature,0,featureSize);
            delete[](BYTE*)ptfp[0].dwReserved;
            cardImage.release();
            return CARD_ERROR_NO_FACE;
        }
    }
    else
    {
        memset(cardFeature,0,featureSize);
        delete[](BYTE*)ptfp[0].dwReserved;
        cardImage.release();
        return CARD_ERROR_NO_FACE;
    }
    delete[](BYTE*)ptfp[0].dwReserved;
    cardImage.release();
    return CARD_FEATURE_READY;
}
//获取人脸特征
int AiFace::PrePeopleFeature()
{
    memset(peopleFeature,0,featureSize);
    cropFace.release();
    qDebug()<<"start people 1";
    if(peopleImage.empty())
    {
        peopleImage.release();
        return PEOPLE_ERROR_NO_FACE;
    }
    int peopleWidth = peopleImage.cols;
    int peopleHeight = peopleImage.rows;
    THFI_FacePos ptfp[1];
    ptfp[0].dwReserved = (DWORD)new BYTE[512];
    int nFace = THFI_DetectFace(0,peopleImage.data,24,peopleWidth,peopleHeight,ptfp,1);
    if(nFace > 0)
    {
        qDebug()<<"start people 2";
        int ret = EF_Extract(0,peopleImage.data,peopleWidth,peopleHeight,3,(DWORD)&ptfp[0],peopleFeature);
        if(ret !=1 )
        {
            memset(peopleFeature,0,featureSize);
            peopleImage.release();
            delete[](BYTE*)ptfp[0].dwReserved;
            return PEOPLE_ERROR_NO_FACE;
        }
        RECT rcFace = ptfp[0].rcFace;
        int width = rcFace.right - rcFace.left;
        int height = rcFace.bottom - rcFace.top;
        cv::Rect rect(rcFace.left, rcFace.top, width, height);
        cropFace = peopleImage(rect).clone();
    }
    else
    {
        memset(peopleFeature,0,featureSize);
        delete[](BYTE*)ptfp[0].dwReserved;
        peopleImage.release();
        return PEOPLE_ERROR_NO_FACE;
    }
    delete[](BYTE*)ptfp[0].dwReserved;
    peopleImage.release();
    return PEOPLE_FEATURE_READY;
}
//获取截取的人脸图像
cv::Mat AiFace::GetCropFace()
{
    return cropFace;
}
//获取相似度计算结果
float AiFace::GetsimResult()
{
    float result = EF_Compare(cardFeature,peopleFeature);
    memset(cardFeature,0,featureSize);
    memset(peopleFeature,0,featureSize);
    return result;
}

/*
 * 异步检测
 */
DetectThread::DetectThread(AiFace *aiface)
{
    this->aiface = aiface;
}
void DetectThread::run()
{
    emit sendDetectStatus(aiface->PrePeopleFeature());
}
