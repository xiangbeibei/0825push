#ifndef CARDREADER_H
#define CARDREADER_H
/*
 * 实现
 * 阅读器线程控制类
 * 阅读器接口类
 * 阅读器类
 */

#include <QThread>
#include <QString>
#include "termb.h"
#include <QImage>

#define READER_INIT 0
#define READER_ERROR       -1
#define READER_GETINFO      1
#define READER_SLEEP_TIME 400
#define READER_SUSPEND 105
#define READER_CLOSE 106
#define CARD_COMFIRM 104
#define CARD_STAY 200
#define CARD_LEAVE 201
#define NOMAL 1
#define ELSE 2
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
/*
 * 描述身份证信息
 */
class CardInfo
{
public:
    QString NATION_STR = QString("汉 蒙古 回 藏 维吾尔 苗 彝 壮 布依 朝鲜 满 侗 瑶 白 土家 哈尼 哈萨克 傣 黎 傈僳 佤 畲 高山 拉祜 水 东乡 纳西 景颇 柯尔克孜 土 达斡尔 仫佬 羌 布朗 撒拉 毛南 仡佬 锡伯 阿昌 普米 塔吉克 怒 乌孜别克 俄罗斯 鄂温克 德昂 保安 裕固 京 塔塔尔 独龙 鄂伦春 赫哲 门巴 珞巴 基诺");
    QStringList NATION_LIST;
    QString name;
    QString sex;
    QString nation;
    QString birYear;
    QString birMonth;
    QString birDay;
    QString birth;
    QString address;
    QString cardId;
    QString gov;
    QString periodStart;
    QString periodEnd;

    CardInfo();
    ~CardInfo();
    void AnalysisCardInfo(QString content);
};

/*
 * 阅读器接口类
 * 定义阅读器的行为
 */
class ReaderInterface
{
public:
    //初始化阅读器
    virtual bool InitDevice() = 0;
    //认证身份证
    virtual bool AuthenticateCard() = 0;
    //读取身份证信息
    virtual bool ReadContent() = 0;
    //关闭设备
    virtual void CloseDevice() = 0;
};

/*
 * 控制阅读器线程
 * 传递消息
 */
class ReaderControl : public QThread
{
    Q_OBJECT
public:
    ReaderControl(int readerName);
    ~ReaderControl();

    bool InitReader();
    void StartReaderThread();
    void CloseReader(int status);
    void setIsNext(bool isNext);

    bool IsNext();
    bool IsExit();
    void setReaderType(int ReaderType);

    CardInfo* get_Cardinfo();//获取身份证信息
    QImage get_Cardphoto();//获取身份证头像
signals:
    //发送消息到主界面，参数可随意更改
    void sendReaderMessage(int msg);
    void sendReadeStatus(int status);

private:
    bool isNext;//阅读器不响应
    bool isExit;//结束线程
    int readerType;//阅读器类型
    int cardStatus;
    int readerStatus;
    CardInfo *cardInfo;
    ReaderInterface *reader;
    void run();

};

/*
 * 子类
 * 继承 ReaderInterface
 */
class Reader_normal : public ReaderInterface
{
public:
    Reader_normal();
    ~Reader_normal();

    bool InitDevice();
    bool AuthenticateCard();
    bool ReadContent();
    void CloseDevice();
};

#endif // CARDREADER_H
