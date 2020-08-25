#include "Mainwindow.h"
#include "ui_mainwindow.h"
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
#define SHARE_FILE_PATH "process.share"
int MainWindow::PROCESS_CLOSE = -1;//程序关闭
int MainWindow::PROCESS_DEALING = -2;//程序处理信息中
int MainWindow::PROCESS_STARTING = 0;//程序正在启动
int MainWindow::PROCESS_READER_RUNNING = 1;//仅阅读器在运行
int MainWindow::PROCESS_ALL_RUNNING = 2;//阅读器和摄像头都在运行

int MainWindow::CAMERA_WIDTH = 591;//摄像头画面宽
int MainWindow::CAMERA_HEIGHT = 443;//摄像头画面高

int MainWindow::SUCCESS_ALL =0;  //各模块初始化均成功
int MainWindow::ERROR_READER = 1;//阅读器初始化错误
int MainWindow::ERROR_CAMERA = 2;//相机初始化错误
int MainWindow::ERROR_USBKEY = 3;//加密狗初始化错误
int MainWindow::ERROR_AIFACE = 4;//人脸库初始化错误
int MainWindow::SUCCESS_READER= 5;//阅读器初始化成功
int MainWindow::SUCCESS_GETINFO= 6;//成功读取身份证信息
int MainWindow::ALL_NOT_INIT = 7;//所有模块还未初始化
int MainWindow::AIFACE_INIT_SUCCESS = 8;//人脸库完成初始化
int MainWindow::OTHERS_BUT_AIFACE = 9;//除了人脸库都完成了初始化
int MainWindow::CAMERA_INIT = 10;
int MainWindow::CAMERA_RUNNING = 11;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->hide();
    ui->statusBar->hide();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowIcon(QIcon(":/image/Image/icons8-name-tag-64.ico"));

    PixOpen=QPixmap(":/image/Image/Open.png");
    PixOpen=PixOpen.scaled(70,70, Qt::KeepAspectRatio);
    PixStop= QPixmap(":/image/Image/Stop.png");
    PixStop=PixStop.scaled(70,70, Qt::KeepAspectRatio);
    PixRight=QPixmap(":/image/Image/Right.png");
    PixRight = PixRight.scaled(107, 98, Qt::KeepAspectRatio);
    PixWrong= QPixmap(":/image/Image/Wrong.png");
    PixWrong = PixWrong.scaled(107, 98, Qt::KeepAspectRatio);
    PixIDpicture = QPixmap(":/image/Image/boss.png");
    PixIDpicture = PixIDpicture.scaled(121,141,Qt::KeepAspectRatio);

    connect(ui->closetoolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnCloseClick()));
    connect(ui->MintoolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnMinClick()));
    connect(ui->quitToolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnQuitClick()));
    connect(ui->startToolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnOpenClick()));
    connect(ui->readToolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnReadOnlyClick()));
    connect(ui->aboutToolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnAboutClick()));
    connect(ui->settingToolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnSettingClick()));
    connect(ui->dataToolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnDatamanager()));
    connect(ui->printToolButton,SIGNAL(clicked(bool)),this,SLOT(onBtnPrintClick()));
    this->show();

    InitObject();
}
void MainWindow::InitObject()
{
    processStatus = PROCESS_CLOSE;
    aifaceStatus = ALL_NOT_INIT;
    dataManagerOpen = false;
    compareStatus = AIFACE_INIT;
    printStatus = AIFACE_INIT;
    cameraStatus = CAMERA_INIT;
    checkDir();

    cameraControl = new ControlCamera(671,491);
    cameraScene = new QGraphicsScene(2,2,ui->cameraView->width()-2,ui->cameraView->height()-2,ui->cameraView);
    ui->cameraView->setScene(cameraScene);

    dataManager=new DMWidget();
    dataBase = database::Get_database();

    configManager = new ConfigManager();
    configManager->InitConfigValues();
    threshold = configManager->threshold;
    soundStatus = configManager->isPlaySound;
    photoDirname = configManager->imagePath;
    timer = new QTimer;
    timer->setInterval(configManager->cleanTime * 1000);
    timer->start();

    systemSetup = new dSystemSetup(this);

    loadThread = new LoadingThread(this);
    initAiThread = new InitAifaceThread(this);
    loadWindow = new LoadingWindow();

    aifaceControl = new AiFace();
    initAiThread->start();
    readControl = new ReaderControl(configManager->readerName);
    configManager->SaveCurrentReader(configManager->readerName);
    connect(readControl,SIGNAL(sendReaderMessage(int)),this,SLOT(handleReader(int)));
    connect(readControl,SIGNAL(sendReadeStatus(int)),this,SLOT(handleReaderclose(int)));
    connect(loadThread,SIGNAL(sendLoadingStatus(int)),this,SLOT(handleInitObject(int)));
    connect(initAiThread,SIGNAL(sendAifaceStatus(int)),this,SLOT(handleInitAiface(int)));
    connect(cameraControl,SIGNAL(sendFrame(QImage)),this,SLOT(handleFrame(QImage)));
    connect(cameraControl,SIGNAL(sendCameraStatus(int)),this,SLOT(handleCameraclose(int)));
    connect(aifaceControl,SIGNAL(sendAiFaceResult(int)),this,SLOT(handleAiFaceStatus(int)));
    connect(timer,SIGNAL(timeout()),this,SLOT(handletimer()));
    connect(dataManager,SIGNAL(exitsignal(bool)),this,SLOT(handleDataManager(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete configManager;
    delete readControl;
    delete systemSetup;
    delete cameraControl;
    delete loadThread;
    delete dataManager;
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    move(x()+dx,y()+dy);
}
/*
 * 模块响应槽
 */
//数据管理模块响应槽
void MainWindow::handleDataManager(bool status)
{
    dataManagerOpen = status;
}
//视频流响应槽
void MainWindow::handleFrame(QImage cameraFrame)
{
    cameraScene->clear();
    if(processStatus == PROCESS_CLOSE)
        return;
    if(cameraStatus == CAMERA_INIT)
    {
        cameraStatus = CAMERA_RUNNING;
        ui->startToolButton->setEnabled(true);
    }
    cameraFrame =cameraFrame.scaled(ui->cameraView->width(), ui->cameraView->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    cameraScene->addPixmap(QPixmap::fromImage(cameraFrame));
    if(processStatus == PROCESS_ALL_RUNNING)
    {
        QPen penline;
        penline.setColor(Qt::green);
        penline.setWidth(2);
        cameraScene->addLine(185,50,420,50,penline);
        cameraScene->addLine(185,50,185,380,penline);
        cameraScene->addLine(420,50,420,380,penline);
        cameraScene->addLine(185,380,420,380,penline);
    }
    if(processStatus == PROCESS_DEALING)
    {
        QFont font;
        font.setPixelSize(35);
        QGraphicsTextItem *cameraText = new QGraphicsTextItem("正在处理!");
        cameraText->setDefaultTextColor(Qt::green);
        cameraText->setFont(font);
        cameraText->setPos(220,20);
        cameraScene->addItem(cameraText);
        ui->cameraView->show();
        return;
    }

    if(compareStatus == AIFACE_NOFACE_ERROR)
    {
        QFont font;
        font.setPixelSize(24);
        QGraphicsTextItem *cameraText = new QGraphicsTextItem("未发现人脸，请调整后重试!");
        cameraText->setDefaultTextColor(Qt::green);
        cameraText->setFont(font);
        cameraText->setPos(160,10);
        cameraScene->addItem(cameraText);
    }
    ui->cameraView->show();
}
//AIFace结果响应槽
void MainWindow::handleAiFaceStatus(int status)
{
    switch (status) {
    case AIFACE_NOFACE_ERROR:
    {
        compareStatus = AIFACE_NOFACE_ERROR;
        ui->labReaderState->setText("[未发现人脸，请调整姿态后重试!]");
        if(soundStatus == 1)
            QSound::play(":/music/music/Noface.wav");
    }break;
    case AIFACE_FEATURE_READY:
    {
        WritetoDatabase();
        printStatus = AIFACE_SUCCESS;
    }break;
    default:
        break;
    }
    timer->start();
    processStatus = PROCESS_ALL_RUNNING;
    readControl->setIsNext(true);
}
//阅读器模块响应槽
void MainWindow::handleReader(int status)
{
    compareStatus = AIFACE_INIT;
    if(dataManagerOpen)
        return;
    switch (status) {
    case CARD_COMFIRM:
    {
        if(processStatus == PROCESS_READER_RUNNING)
            ui->labReaderState->setText("[正在处理... ...]");
    }break;
    case READER_ERROR:
    {
        if(processStatus == PROCESS_ALL_RUNNING)
        {
            cameraControl->stopCamera(CAMERA_SUSPEND);
            aifaceControl->ReleaseFeature();
            printStatus = AIFACE_INIT;
            ui->labReaderState->setText(tr("[错误，请连接并安装好阅读器]"));
            QMessageBox CardReadmessage(QMessageBox::Critical,tr("身份证阅读器出错"),tr("阅读器出现错误，请确认型号和连接状态"),QMessageBox::Ok);
            CardReadmessage.setButtonText(QMessageBox::Ok,tr("确定"));
            if(CardReadmessage.exec()==QMessageBox::Ok)
            {
                ui->labReaderState->setText("[未启动... ...]");
                CardReadmessage.close();
            }

            cameraScene->clear();
            cleanUi();
            ui->startToolButton->setText(tr("开始比对"));
            ui->startToolButton->setIcon(QIcon(PixOpen));
            cameraStatus = CAMERA_INIT;
            ui->startToolButton->setEnabled(true);
            ui->readToolButton->setText(tr("读身份证"));
            ui->readToolButton->setEnabled(true);
            processStatus = PROCESS_CLOSE;
        }
        if(processStatus == PROCESS_READER_RUNNING)
        {
            readControl->CloseReader(READER_SUSPEND);
            ui->labReaderState->setText(tr("[错误，请连接并安装好阅读器]"));
            QMessageBox CardReadmessage(QMessageBox::Critical,tr("身份证阅读器出错"),tr("阅读器出现错误，请确认型号和连接状态"),QMessageBox::Ok);
            CardReadmessage.setButtonText(QMessageBox::Ok,tr("确定"));
            if(CardReadmessage.exec()==QMessageBox::Ok)
            {
                ui->labReaderState->setText("[未启动... ...]");
                CardReadmessage.close();
            }
            cleanUi();
            ui->readToolButton->setText(tr("读身份证"));
            ui->readToolButton->setEnabled(true);
            processStatus = PROCESS_CLOSE;
        }
    }break;
    case READER_GETINFO:
    {
        int status = processStatus;
        timer->stop();
        showCardInfo();
        if(status == PROCESS_ALL_RUNNING)
        {
            readControl->setIsNext(false);
            processStatus = PROCESS_DEALING;
            ui->labReaderState->setText("[正在处理... ...]");
            cv::Mat cardImage = cv::imread("data/WZ/zp.bmp");
            cv::Mat peopleImage = cameraControl->captureCamera();
            aifaceControl->SetImage(cardImage,peopleImage);
            cardImage.release();
            peopleImage.release();
            return;
        }
        ui->labReaderState->setText("[身份证信息读取成功... ...]");
        QDateTime time = QDateTime::currentDateTime();
        CardInfo cardinfo = *(readControl->get_Cardinfo());
        QString datedir = photoDirname+ "/photo/"+time.toString("yyyy-MM-dd")+"/";
        QString idpath = datedir + "idphoto"+"/";
        QDir iddir;
        if(!iddir.exists(idpath))
            iddir.mkpath(idpath);
        QString idphoto_filename = idpath + cardinfo.cardId + ".bmp";
        QFile::copy("./data/WZ/zp.bmp",idphoto_filename);
        onePeople.Result = "未比对";
        onePeople.Time = time.toString("yyyy/MM/dd hh:mm:ss");
        onePeople.Name = cardinfo.name;
        onePeople.ID = cardinfo.cardId;
        onePeople.Gender = cardinfo.sex;
        onePeople.Nation = cardinfo.nation;
        onePeople.Birthtime = cardinfo.birth;
        onePeople.Home = cardinfo.address;
        onePeople.Office = cardinfo.gov;
        onePeople.ValidTime = cardinfo.periodStart + "-" + cardinfo.periodEnd;
        onePeople.idimage = idphoto_filename;
        onePeople.faceimage = "";
        dataBase->insertstructdata(onePeople);
        printStatus = CARD_COMFIRM;
        timer->start();
    }
        break;
    default:
        break;
    }
}
//关闭摄像头
void MainWindow::handleCameraclose(int status)
{
    if(status == CAMERA_CLOSE)
    {
        qDebug()<<"close camera11";
        cleanUi();
        readControl->CloseReader(READER_CLOSE);
    }
    else if (status == CAMERA_SUSPEND)
    {
        qDebug()<<"close camera11";
        cleanUi();
        readControl->CloseReader(READER_SUSPEND);
    }
}
//关闭阅读器
void MainWindow::handleReaderclose(int status)
{
    if(status == READER_CLOSE)
    {
        qDebug()<<"close reader";
        cleanUi();
        this->close();
    }
    else if(status == READER_SUSPEND)
    {
//        7-21-test
//        ui->closetoolButton->setEnabled(true);
//        ui->quitToolButton->setEnabled(true);
        cleanUi();
    }
}
//计时器响应槽
void MainWindow::handletimer()
{
    timer->stop();
    cleanUi();
    if(processStatus == PROCESS_ALL_RUNNING || processStatus == PROCESS_READER_RUNNING)
        ui->labReaderState->setText("[请放置身份证... ...]");
    timer->start();
}
//人脸库初始化模块响应槽
void MainWindow::handleInitAiface(int status)
{
    if(aifaceStatus == ALL_NOT_INIT)
    {
        aifaceStatus = AIFACE_INIT_SUCCESS;
    }
    else if(aifaceStatus == OTHERS_BUT_AIFACE)
    {
        aifaceStatus = AIFACE_INIT_SUCCESS;
        loadWindow->close();
    }
    if(status == ERROR_AIFACE)
    {
        this->close();
        QMessageBox::information(NULL,"错误","人脸库初始化失败，请重新启动软件");
    }
}
//除人脸库初始化模块响应槽
void MainWindow::handleInitObject(int status)
{
    if(aifaceStatus == ALL_NOT_INIT)
        aifaceStatus = OTHERS_BUT_AIFACE;
    else if(aifaceStatus == AIFACE_INIT_SUCCESS)
    {
        qDebug()<< "init success";
        aifaceStatus = AIFACE_INIT_SUCCESS;
        loadWindow->close();
    }
    int loadStatus = PROCESS_ALL_RUNNING;
    if(status == ERROR_READER)
    {
        ui->labReaderState->setText(tr("[启动失败，请连接并安装好阅读器]"));
        QMessageBox::information(NULL,"错误","阅读器初始化失败，请确认连接状态");
        loadStatus = PROCESS_CLOSE;
    }
    if(status == ERROR_CAMERA)
    {
        ui->labReaderState->setText(tr("[启动失败，摄像头初始化错误]"));
        QMessageBox::information(NULL,"错误","摄像头初始化失败，请确认连接状态");
        loadStatus = PROCESS_CLOSE;
    }

    processStatus = loadStatus;
    if(loadStatus == PROCESS_ALL_RUNNING)
    {
        ui->labReaderState->setText(tr("[请放置身份证... ...]"));
        ui->readToolButton->setText("正在运行");
        ui->readToolButton->setEnabled(false);
        return;
    }
    ui->labReaderState->setText("[未启动... ...]");
    ui->startToolButton->setIcon(QIcon(PixOpen));
    ui->startToolButton->setText("开始比对");
    cameraStatus = CAMERA_INIT;
    ui->startToolButton->setEnabled(true);
}

/*
 * 按钮响应槽
 */
//启动完整程序
void MainWindow::onBtnOpenClick()
{
    int status = processStatus;
    if(status == PROCESS_DEALING
            ||status == PROCESS_STARTING)
    {
        qDebug()<< processStatus;
        return;
    }
    if(status == PROCESS_CLOSE
            ||status == PROCESS_READER_RUNNING)
    {
        //显示程序正在启动请等待
        processStatus = PROCESS_STARTING;
        ui->startToolButton->setEnabled(false);
        cameraStatus = CAMERA_INIT;
        loadThread->start();
        loadWindow->show();
        ui->startToolButton->setIcon(QIcon(PixStop));
        ui->startToolButton->setText(tr("停止比对"));
        ui->labReaderState->setText(tr("[正在启动... ...]"));
    }
    else
    {
        ui->startToolButton->setEnabled(false);
        StopProcess();
    }
    qDebug()<< processStatus;
}
//启动读身份证程序
void MainWindow::onBtnReadOnlyClick()
{
    if(processStatus == PROCESS_CLOSE)
    {
        if(!readControl->InitReader())
        {
            QMessageBox::information(NULL,"错误","阅读器初始化失败，请确认连接状态");
            return;
        }
        readControl->StartReaderThread();
        processStatus = PROCESS_READER_RUNNING;
        ui->readToolButton->setText(tr("关闭读卡"));
        ui->labReaderState->setText(tr("[请放置身份证... ...]"));
    }
    else
    {
        readControl->CloseReader(READER_SUSPEND);
        ui->readToolButton->setText(tr("读身份证"));
        ui->labReaderState->setText("[未启动... ...]");
        processStatus = PROCESS_CLOSE;
    }
}
//点击右上角退出按钮
void MainWindow::onBtnCloseClick()
{
    if(processStatus == PROCESS_DEALING
            || processStatus == PROCESS_STARTING)
    {
        QMessageBox messageBox(QMessageBox::Critical,tr("程序正在处理"),tr("程序正在处理任务，请稍候再试"),QMessageBox::Ok);
        messageBox.setButtonText(QMessageBox::Ok,tr("确定"));
        if(messageBox.exec()==QMessageBox::Ok)
        {
            messageBox.close();
        }
        return;
    }
    if(processStatus == PROCESS_CLOSE)
    {
        cleanUi();
        this->close();
    }
    if(processStatus == PROCESS_READER_RUNNING)
    {
        readControl->CloseReader(READER_CLOSE);
    }
    StopAllProcess();
}
//点击最小化按钮
void MainWindow::onBtnMinClick()
{
    this->showMinimized();
}
//点击打印
void MainWindow::onBtnPrintClick()
{
    if(printStatus != AIFACE_SUCCESS && printStatus != CARD_COMFIRM)
    {
        QMessageBox::information(this,"提示","没有可供打印的凭证！");
        return;
    }
    PrintManager printManager;
    printManager.CreateHTML(onePeople);
    printManager.PrintDocument();
    printStatus = AIFACE_INIT;
}
//点击退出按钮
void MainWindow::onBtnQuitClick()
{
    if(processStatus == PROCESS_DEALING
            || processStatus == PROCESS_STARTING)
    {
        QMessageBox messageBox(QMessageBox::Critical,tr("程序正在处理"),tr("程序正在处理任务，请稍候再试"),QMessageBox::Ok);
        messageBox.setButtonText(QMessageBox::Ok,tr("确定"));
        if(messageBox.exec()==QMessageBox::Ok)
        {
            messageBox.close();
        }
        return;
    }
    if(processStatus == PROCESS_CLOSE)
    {
        cleanUi();
        this->close();
    }
    if(processStatus == PROCESS_READER_RUNNING)
    {
        readControl->CloseReader(READER_CLOSE);
    }
    StopAllProcess();
}
//关于按钮
void MainWindow::onBtnAboutClick()
{
    AboutWindow *dAboutWindow = new AboutWindow;
    dAboutWindow->setWindowFlags(Qt::WindowCloseButtonHint);
    dAboutWindow->exec();
}
//系统设置按钮
void MainWindow::onBtnSettingClick()
{
    dataManagerOpen=true;
    configManager->IsConfigExist();
    systemSetup->exec();
}
//数据管理按钮
void MainWindow::onBtnDatamanager()
{
    if(processStatus == PROCESS_DEALING
            || processStatus == PROCESS_STARTING)
    {
        QMessageBox messageBox(QMessageBox::Critical,tr("程序正在处理"),tr("程序正在处理任务，请稍候再试"),QMessageBox::Ok);
        messageBox.setButtonText(QMessageBox::Ok,tr("确定"));
        if(messageBox.exec()==QMessageBox::Ok)
        {
            messageBox.close();
        }
        return;
    }
    dataManager->updateall();
    dataManagerOpen=true;

    dataManager->show();
    dataManager->tableviewinit();
}
/*
 * 工具函数
 */
//初始化除人脸库外的模块
int MainWindow::InitProcess()
{
    if(!readControl->InitReader())
        return ERROR_READER;

    readControl->StartReaderThread();
    if(!cameraControl->startCamera())
        return ERROR_CAMERA;
    aifaceControl->InitFeature();
    return SUCCESS_ALL;
}
//初始化人脸库
int MainWindow::InitAiprocess()
{
    bool ret = aifaceControl->InitAiFace();
    if(ret)
        return AIFACE_INIT_SUCCESS;
    else
        return ERROR_AIFACE;
}
//关闭所有模块
void MainWindow::StopProcess()
{
    processStatus = PROCESS_CLOSE;
    compareStatus = AIFACE_INIT;
    aifaceControl->ReleaseFeature();
    cameraControl->stopCamera(CAMERA_SUSPEND);

    cleanUi();
    cameraScene->clear();
    ui->readToolButton->setText(tr("读身份证"));
    ui->readToolButton->setEnabled(true);
    cameraStatus = CAMERA_INIT;
    ui->startToolButton->setEnabled(true);
    ui->startToolButton->setIcon(QIcon(PixOpen));
    ui->startToolButton->setText(tr("开始比对"));
    ui->labReaderState->setText(tr("[未启动… …]"));
}
//关闭所有进程
void MainWindow::StopAllProcess()
{
    if(processStatus == PROCESS_READER_RUNNING)
    {
        if(aifaceStatus == AIFACE_INIT_SUCCESS)
            aifaceControl->ReleaseAiFace();
        processStatus = PROCESS_CLOSE;
        cleanUi();
        cameraScene->clear();
        cameraStatus = CAMERA_INIT;
        return;
    }
    compareStatus = AIFACE_INIT;
    if(processStatus != PROCESS_CLOSE)
        aifaceControl->ReleaseFeature();
    aifaceControl->ReleaseAiFace();
    processStatus = PROCESS_CLOSE;
    cameraControl->stopCamera(CAMERA_CLOSE);
    cleanUi();
    cameraScene->clear();
    cameraStatus = CAMERA_INIT;
}
//显示读卡信息
void MainWindow::showCardInfo()
{
    CardInfo cardinfo = *(readControl->get_Cardinfo());
    ui->smallname->setText(cardinfo.name);
    ui->smallgender->setText(cardinfo.sex);
    ui->smallnation->setText(cardinfo.nation);
    ui->smallyear->setText(cardinfo.birYear);
    ui->smallmonth->setText(cardinfo.birMonth);
    ui->smallday->setText(cardinfo.birDay);
    ui->smalladdress->setText(cardinfo.address);
    ui->smalloffice->setText(cardinfo.gov);
    ui->smallid->setText(cardinfo.cardId);
    QString Expirydate=cardinfo.periodStart+"-"+cardinfo.periodEnd;
    ui->smallvalid->setText(Expirydate);
    ui->cardPicture->setAlignment(Qt::AlignCenter);
    QImage idPicture = readControl->get_Cardphoto();
    idPicture = idPicture.scaled(153,189,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->cardPicture->setPixmap(QPixmap::fromImage(idPicture));
    QImage smallCardImage = readControl->get_Cardphoto();
    smallCardImage = smallCardImage.scaled(102,126,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->smallpicture->setPixmap(QPixmap::fromImage(smallCardImage));
}
//检查目录完整
void MainWindow::checkDir()
{
    QDir dataDir;
    QDir cardDir;
    QDir photoDir;
    QString dataPath = "data/";
    QString photoPath = "data/photo/";
    QString cardPath = "data/WZ/";

    if(!dataDir.exists(dataPath))
        dataDir.mkpath(dataPath);
    if(!cardDir.exists(cardPath))
        cardDir.mkpath(cardPath);
    if(!photoDir.exists(photoPath))
        photoDir.mkpath(photoPath);
}
//
void MainWindow::ReInitValues(int status)
{
    timer->stop();
    if(status == CONFIG_REFESH)
    {
        configManager->IsConfigExist();
        QThread::msleep(100);
        soundStatus = configManager->isPlaySound;
        timerMSecend = configManager->cleanTime;
        threshold = configManager->threshold;
        photoDirname = configManager->imagePath;
        timer->setInterval(timerMSecend * 1000);
        cameraControl->setCameraExposure(configManager->CameraExposure);
        qDebug()<<configManager->CameraExposure;
        readControl->setReaderType(configManager->currentreader);
    }
    dataManagerOpen = false;
    timer->start();
}
//清除画面上所有信息
void MainWindow::cleanUi()
{
    ui->smallname->clear();
    ui->smallgender->clear();
    ui->smallnation->clear();
    ui->smallyear->clear();
    ui->smallmonth->clear();
    ui->smallday->clear();
    ui->smalladdress->clear();
    ui->smallid->clear();
    ui->smalloffice->clear();
    ui->smallvalid->clear();
    ui->smallpicture->setPixmap(PixIDpicture);
    ui->peoplePicture->clear();
    ui->resultText->clear();
    ui->resultPicture->clear();
    ui->resultNum->clear();
    ui->cardPicture->clear();
}
//写一条记录到数据库中
void MainWindow::WritetoDatabase()
{
    QImage cropFace = MatToQImage(aifaceControl->GetCropFace());
    cropFace = cropFace.scaled(170,210);
    ui->peoplePicture->setPixmap(QPixmap::fromImage(cropFace));
    float resultsim = aifaceControl->GetsimResult();
    qDebug() << "相似度: " << resultsim;
    float result = sqrt(resultsim)*100;
    qDebug() << "相似度: " << result;
    QString matchResult;
    if(result < threshold)
    {
        matchResult = "不匹配";
        if(soundStatus == 1)
            QSound::play(":/music/music/Fail.wav");
        ui->resultPicture->setPixmap(PixWrong);
        ui->resultText->setText(tr(" [不匹配]"));
        ui->labReaderState->setText(tr("[验证失败... ...]"));
        ui->resultNum->clear();
    }
    else
    {
        matchResult = "匹配";
        if(soundStatus == 1)
            QSound::play(":/music/music/Success.wav");
        ui->resultPicture->setPixmap(PixRight);
        QString showStr = tr("[匹配]");
        QString showNum = QString::number((int)result,10) + "%";
        ui->resultNum->setText(showNum);
        ui->resultText->setText(showStr);
        ui->labReaderState->setText(tr("[验证通过... ...]"));
    }
    QDateTime time = QDateTime::currentDateTime();
    QString datedir = photoDirname + "/photo/"+time.toString("yyyy-MM-dd")+"/";
    QString idpath = datedir + "idphoto"+"/";
    QString cropdirname = datedir+"cropphoto"+"/";
    QDir iddir;
    QDir cropdir;
    if(!iddir.exists(idpath))
        iddir.mkpath(idpath);
    if(!cropdir.exists(cropdirname))
        cropdir.mkpath(cropdirname);
    CardInfo cardinfo = *(readControl->get_Cardinfo());
    QString idphoto_filename=idpath + cardinfo.cardId + ".bmp";
    QFile::copy("./data/WZ/zp.bmp",idphoto_filename);
    QString crop_filename = cardinfo.cardId + "_crop_" + time.toString("hhmmss")+".jpg";
    QString cropphoto_filepath = cropdirname + crop_filename;
    cropFace.save(cropphoto_filepath);
    onePeople.Result = matchResult;
    onePeople.Time = time.toString("yyyy/MM/dd hh:mm:ss");
    onePeople.Name = cardinfo.name;
    onePeople.ID = cardinfo.cardId;
    onePeople.Gender = cardinfo.sex;
    onePeople.Nation = cardinfo.nation;
    onePeople.Birthtime = cardinfo.birth;
    onePeople.Home = cardinfo.address;
    onePeople.Office = cardinfo.gov;
    onePeople.ValidTime = cardinfo.periodStart + "-" + cardinfo.periodEnd;
    onePeople.idimage = idphoto_filename;
    onePeople.faceimage = cropphoto_filepath;
    dataBase->insertstructdata(onePeople);
}
//QImage转Mat
cv::Mat MainWindow::QImage_to_cvMat(const QImage &image, bool inCloneImageData)
{
    switch (image.format())
    {
    // 8-bit, 4 channel
    case QImage::Format_RGB32:
    {
        cv::Mat mat(image.height(),image.width(), CV_8UC4, const_cast<uchar*>(image.bits()), image.bytesPerLine() );
        return (inCloneImageData ? mat.clone() : mat);
    }
        // 8-bit, 3 channel
    case QImage::Format_RGB888:
    {
        if (!inCloneImageData ) {
            qWarning() << "ASM::QImageToCvMat() - Conversion requires cloning since we use a temporary QImage";
        }
        QImage swapped = image.rgbSwapped();
        return cv::Mat( swapped.height(), swapped.width(), CV_8UC3, const_cast<uchar*>(swapped.bits()), swapped.bytesPerLine() ).clone();
    }
        // 8-bit, 1 channel
    case QImage::Format_Indexed8:
    {
        cv::Mat  mat( image.height(), image.width(), CV_8UC1, const_cast<uchar*>(image.bits()), image.bytesPerLine() );

        return (inCloneImageData ? mat.clone() : mat);
    }
    default:
        qDebug("Image format is not supported: depth=%d and %d format\n", image.depth(), image.format());
        break;
    }
    return cv::Mat();
}
//Mat转QImage
QImage MainWindow::MatToQImage(cv::Mat mat)
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

/*
 * 异步加载类
 */
//异步初始化除aiface外的模块
LoadingThread::LoadingThread(MainWindow *win)
{
    this->win = win;
}

void LoadingThread::run()
{
    emit sendLoadingStatus(win->InitProcess());
}
//异步初始化aiface模块
InitAifaceThread::InitAifaceThread(MainWindow *win)
{
    this->win = win;
}
void InitAifaceThread::run()
{
    emit sendAifaceStatus(win->InitAiprocess());
}

