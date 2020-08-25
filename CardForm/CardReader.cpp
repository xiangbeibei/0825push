#include "CardReader.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QStringList>

/*
 * 将读取的字符串拆分开
 */
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
CardInfo::CardInfo()
{
    NATION_LIST = NATION_STR.split(" ");
}

CardInfo::~CardInfo()
{
}

void CardInfo::AnalysisCardInfo(QString content)
{
    QFile *file_WZ = new QFile(content);
    if(!(file_WZ->open(QIODevice::ReadOnly|QIODevice::Text)))
    {
        qDebug()<<"信息文件打开失败";
    }
    QTextStream txt_stream(file_WZ);
    txt_stream.setCodec("UTF-16");
    QString read_allinfo = txt_stream.readAll();
    //姓名
    name=read_allinfo.mid(0,15);
    //性别
    QString sex_code=read_allinfo.mid(15,1);
    sex = sex_code == "1" ? "男" : "女";
    //民族
    QString nation_code = read_allinfo.mid(16,2);
    nation = NATION_LIST.at(nation_code.toInt()-1);
    //生日
    birYear = read_allinfo.mid(18,4);
    birMonth = read_allinfo.mid(22,2);
    birDay = read_allinfo.mid(24,2);
    birth = birYear + "/" + birMonth+"/" + birDay;
    //地址
    address = read_allinfo.mid(26,35);
    //身份证号
    cardId = read_allinfo.mid(61,18);
    //签发机关
    gov = read_allinfo.mid(79,15);
    //有效日期
    periodStart = read_allinfo.mid(94,8);
    periodEnd = read_allinfo.mid(102,8);
}


/************** 分割线 ****************/

/*
 * 控制阅读器行为
 * 线程
 */

//根据readerName 初始化对应实例
ReaderControl::ReaderControl(int readerName)
{   
    reader=new Reader_normal();
    readerType = readerName;
    isNext = true;
    isExit = false;
    cardInfo = new CardInfo();
}

ReaderControl::~ReaderControl()
{
    delete cardInfo;
    delete reader;
}

bool ReaderControl::InitReader()
{
    return reader->InitDevice();//初始化设备
}

void ReaderControl::StartReaderThread()
{
    isNext = true;
    isExit = false;
    readerStatus = READER_INIT;
    this->cardStatus = CARD_LEAVE;
    if(!this->isRunning())
        start();
}

QImage ReaderControl::get_Cardphoto()
{
    QImage id_pic;
    id_pic.load("data/WZ/zp.bmp");
    return id_pic;
}
/*
 * 返回cardinfo指针
 */
CardInfo* ReaderControl::get_Cardinfo()
{
    return cardInfo;
}
void ReaderControl::setReaderType(int ReaderType)
{
    this->cardStatus = CARD_LEAVE;
    this->readerType = ReaderType;
}
void ReaderControl::CloseReader(int status)
{
    isExit = true;
    readerStatus = status;
}

void ReaderControl::setIsNext(bool isNext)
{
    this->isNext = isNext;
}

//线程函数
void ReaderControl::run()
{
    while(true)
    {
        msleep(READER_SLEEP_TIME);
        if(!InitReader())
        {
            emit sendReaderMessage(READER_ERROR);
            return;
        }

        if(isExit)
            break;
        if(!isNext)
            continue;
        if(readerType == NOMAL)
        {
            if(reader->AuthenticateCard())
            {
                emit sendReaderMessage(CARD_COMFIRM);
                if(reader->ReadContent())
                {
                    cardInfo->AnalysisCardInfo("data/WZ/wz.txt");
                    emit sendReaderMessage(READER_GETINFO);
                }
            }
        }
        if(readerType == ELSE)
        {
            bool ret = reader->AuthenticateCard();
            if(ret && cardStatus == CARD_LEAVE)
            {
                emit sendReaderMessage(CARD_COMFIRM);
                if(reader->ReadContent())
                {
                    cardInfo->AnalysisCardInfo("data/WZ/wz.txt");
                    emit sendReaderMessage(READER_GETINFO);
                }
                cardStatus = CARD_STAY;
            }
            else if(!ret)
            {
                cardStatus = CARD_LEAVE;
            }
        }
    }
    //关闭设备
    reader->CloseDevice();
    emit sendReadeStatus(readerStatus);
}


/************** 分割线 ****************/


/*
 * 阅读器子类
 */
Reader_normal::Reader_normal()
{

}

Reader_normal::~Reader_normal()
{

}

bool Reader_normal::InitDevice()
{
    int port = 1001;
    int li_ret = InitComm(port);
    if(li_ret != 1)
        return false;
    return true;
}

bool Reader_normal::AuthenticateCard()
{
    int li_ret=Authenticate();
    qDebug()<< li_ret;
    if(li_ret != 1)
    {
        qDebug()<< "hhhhh";
        return false;
    }
        return true;
}

bool Reader_normal::ReadContent()
{
    char path[] = "data/WZ";
    int re = Read_Content_Path(path,1);
    if(re == 0 || re < 0)
        return false;
    return true;
}

void Reader_normal::CloseDevice()
{
    CloseComm();
}
