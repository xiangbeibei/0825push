#include "dSystemSetup.h"
#include "ui_dSystemSetup.h"

dSystemSetup::dSystemSetup(MainWindow *windows,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dSystemSetup)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint);
    this->setWindowIcon(QIcon(":/image/Image/icons8-name-tag-64.ico"));
    connect(ui->checkpushButton,SIGNAL(clicked(bool)),this,SLOT(onBtnCheck()));
    connect(ui->cancelpushButton,SIGNAL(clicked(bool)),this,SLOT(onBtnCancel()));
    connect(ui->cameraSetting,SIGNAL(clicked(bool)),this,SLOT(onBtnCamera()));
    connect(ui->imagePathSetting,SIGNAL(clicked(bool)),this,SLOT(onBtnImage()));
    connect(ui->readerSetting,SIGNAL(clicked(bool)),this,SLOT(onBtnReader()));
    setInitWindowValue();
    this->win = windows;
    SelectReader = new dReadSetting();  //自定义的dSelectReader类，新建SelectReader对象
    CameraSetting = new dCameraSetting(); //自定义的Dialog类，新建CameraSetting对象
    connect(CameraSetting,SIGNAL(send_CameraSettingData(float)),SLOT(handleCameraSetting(float)));
}

dSystemSetup::~dSystemSetup()
{
    delete ui;
    delete SelectReader;
    delete CameraSetting;
}
void dSystemSetup::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void dSystemSetup::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void dSystemSetup::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    move(x()+dx,y()+dy);
}
void dSystemSetup::handleCameraSetting(float CameraExposure)
{
    qDebug()<< CameraExposure;
    configmanager.CameraExposure = CameraExposure;
}
void dSystemSetup::setInitWindowValue()
{
    QFileInfo fi("./data/config.json");
    if(fi.isFile())
    {
        configmanager.InitConfigValues();
        if(configmanager.isPlaySound == 1)
        {
            ui->soundCheckBox->setCheckState(Qt::Checked);
        }
        else
        {
            ui->soundCheckBox->setCheckState(Qt::Unchecked);
        }
        ui->cleanCheckBox->setCheckState(Qt::Checked);

        ui->thresholdCheckBox->setCheckState(Qt::Checked);

        QString s = QString::number(configmanager.cleanTime,10);
        ui->cleanLineEdit->setText(s);
        QString t = QString::number(configmanager.threshold,10);
        ui->thresholdLineEdit->setText(t);
    }
}
void dSystemSetup::onBtnCamera()
{
    CameraSetting->setWindowFlags(Qt::Dialog| Qt::WindowMaximizeButtonHint
                                  |Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    CameraSetting->setWindowTitle(tr("系统设置"));
    CameraSetting->exec();
}
void dSystemSetup::onBtnCheck()
{

    if(ui->soundCheckBox->isChecked())
    {
        configmanager.isPlaySound =1;
        configmanager.SaveIsPlaySound(1);
    }
    else
    {
        configmanager.isPlaySound =0;
        configmanager.SaveIsPlaySound(0);

    }
    configmanager.cleanTime =  ui->cleanLineEdit->text().toInt();
    configmanager.threshold = ui->thresholdLineEdit->text().toInt();
    configmanager.SaveCleanTime(configmanager.cleanTime);
    configmanager.SaveThreshold(configmanager.threshold);
    configmanager.SaveImagePath(configmanager.imagePath);
    configmanager.SaveCameraExposure(configmanager.CameraExposure);
    win->ReInitValues(CONFIG_REFESH);
    close();

}
void dSystemSetup::onBtnImage()
{
    QString photo_dirname=QFileDialog::getExistingDirectory(this,"Backup Data",QDir::currentPath(),QFileDialog::DontUseNativeDialog);
    if(photo_dirname.isEmpty())
    {
        return;
    }
    configmanager.imagePath = photo_dirname;
    return;
}

void dSystemSetup::onBtnReader()
{
    SelectReader->refreshData();
    SelectReader->show();
}

void dSystemSetup::onBtnCancel()
{
    win->ReInitValues(CONFIG_STAY);
    close();
}
