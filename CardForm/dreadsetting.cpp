#include "dreadsetting.h"
#include "ui_dreadsetting.h"
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
dReadSetting::dReadSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dReadSetting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowIcon(QIcon(":/image/Image/icons8-name-tag-64.ico"));
    ui->readercomboBox->addItem("普通阅读器");
    ui->readercomboBox->addItem("其他阅读器");
    configManager = new ConfigManager();
    refreshData();
    connect(ui->canceltoolButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->checktoolButton,SIGNAL(clicked(bool)),this,SLOT(onBtncheck()));
}

dReadSetting::~dReadSetting()
{
    delete ui;
    delete configManager;
}
void dReadSetting::onBtncheck()
{
    QString current = ui->readercomboBox->currentText();
    if(current == "普通阅读器" )
    {
        configManager->SaveCurrentReader(1);
        if(ui->defaultcheckBox->isChecked())
        {
            configManager->SaveReaderName(1);
        }
    }
    else if(current == "其他阅读器")
    {
        configManager->SaveCurrentReader(2);
        if(ui->defaultcheckBox->isChecked())
        {
            configManager->SaveReaderName(2);
        }
    }
    close();
}
void dReadSetting::refreshData()
{
    qDebug()<< configManager->readerName;
    if(configManager->readerName == 1)
    {
        ui->defaultlabel->setText("普通阅读器");
    }
    else if(configManager->readerName == 2)
    {
        ui->defaultlabel->setText("其他阅读器");
    }
}
