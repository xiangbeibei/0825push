#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTimer>
#include <QDateTime>
#include <QImage>
#include <QSound>
#include "CardReader.h"
#include "AboutWindow.h"
#include "ConfigManager.h"
#include "ControlCamera.h"
#include "dSystemSetup.h"
#include "loadingwindow.h"
#include "Aiface.h"
#include "dmwidget.h"
#include "database.h"

#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
class LoadingThread;
class InitAifaceThread;
class dSystemSetup;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void showCardInfo();//更新界面
    void checkDir();//检查数据目录
    int InitProcess();
    int InitAiprocess();
    void StopProcess();
    void StopAllProcess();
    void cleanUi();
    void InitObject();
    void WritetoDatabase();
    void ReInitValues(int status);
    cv::Mat QImage_to_cvMat(const QImage &image, bool inCloneImageData);
    QImage MatToQImage(cv::Mat mat);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    /*
    * 状态相关
    */
    static int PROCESS_CLOSE;
    static int PROCESS_STARTING;
    static int PROCESS_DEALING;
    static int PROCESS_ALL_RUNNING;
    static int PROCESS_READER_RUNNING;

    static int SUCCESS_ALL;
    static int ERROR_READER;
    static int ERROR_CAMERA;
    static int ERROR_USBKEY;
    static int ERROR_AIFACE;
    static int SUCCESS_READER;
    static int SUCCESS_GETINFO;
    static int ALL_NOT_INIT;
    static int AIFACE_INIT_SUCCESS;
    static int OTHERS_BUT_AIFACE;
    static int CAMERA_INIT;
    static int CAMERA_RUNNING;

    static int CAMERA_WIDTH;
    static int CAMERA_HEIGHT;

    int processStatus;//全局状态量
    int aifaceStatus;//人脸库状态量
    int compareStatus;//比对结果状态量
    int printStatus;//打印状态量
    int cameraStatus;//摄像头状态量
    int soundStatus;//是否播放声音
    bool dataManagerOpen;//判断数据管理模块是否启动
    int isPleySound;
    int timerMSecend;
    QString photoDirname;
    float threshold;//阈值
    Alldata onePeople;
    /*
    * 摄像机相关
    */
    QGraphicsScene *cameraScene;
    QGraphicsTextItem *cameraText;
    /*
     * 模块相关
     */
    AiFace *aifaceControl;
    ControlCamera *cameraControl;
    ReaderControl *readControl;
    ConfigManager *configManager;
    dSystemSetup *systemSetup;
    LoadingThread *loadThread;
    InitAifaceThread *initAiThread;
    LoadingWindow *loadWindow;
    database *dataBase;
    DMWidget *dataManager;
    /*
     * 定时器
     */
    QTimer *timer;
    /*
     * 界面图标
     */
    QPixmap PixOpen;
    QPixmap PixStop;
    QPixmap PixRight;
    QPixmap PixWrong;
    QPixmap PixIDpicture;
private:
    QPoint last;//智能指针
protected://重写鼠标事件，使窗口可移动
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    /*
 * 响应槽函数
 */
private slots:
    void onBtnCloseClick();
    void onBtnMinClick();
    void onBtnQuitClick();
    void onBtnOpenClick();
    void onBtnReadOnlyClick();
    void onBtnAboutClick();
    void onBtnSettingClick();
    void onBtnDatamanager();
    void onBtnPrintClick();

    void handleReader(int status);
    void handleReaderclose(int status);
    void handleCameraclose(int status);
    void handleInitObject(int status);
    void handleInitAiface(int status);
    void handleAiFaceStatus(int status);
    void handleDataManager(bool status);
    void handleFrame(QImage);
    void handletimer();

};
/*
 * 异步加载类
 */
class LoadingThread : public QThread
{
    Q_OBJECT
public:
    LoadingThread(MainWindow *win);

signals:
    void sendLoadingStatus(int status);

private:
    MainWindow *win;
    void run();
};

class InitAifaceThread : public QThread
{
    Q_OBJECT
public:
    InitAifaceThread(MainWindow *win);
signals:
    void sendAifaceStatus(int status);
private:
    MainWindow *win;
    void run();
};
#endif // MAINWINDOW_H
