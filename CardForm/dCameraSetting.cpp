#include "dCameraSetting.h"
#include "ui_dCameraSetting.h"

#include <QLineEdit>
#include <QSlider>

#pragma execution_character_set("utf-8")

dCameraSetting::dCameraSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dCameraSetting)
{
    qRegisterMetaType<QVariant>("QVariant");
    /*给摄像头设置赋予初始值*/
    CameraType = "摄像头1";
    CameraExposure = 0;
    CameraFocalLenth = 0;
    CameraAutoExposure = false;
    CameraAutoFocus = false;

    ui->setupUi(this);
    ui->cameracomboBox->addItem("摄像头1");
    //设置滑动条控件1的最小值(-5)
    ui->horizontalSlider->setMinimum(0);
    //设置滑动条控件1的最大值(+5)
    ui->horizontalSlider->setMaximum(10);
    //设置滑动条控件1的初始值(0)
    ui->horizontalSlider->setValue(5);
    //信号和槽 当滑动条1的值发生改变时，即产生一个valueChanged(int)信号 设置QLineEdit控件1的显示文本
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(setLineEditValue1(int)));
    //信号和槽 当QLineEdit控件1的值发生改变时，即产生一个textChanged(QString)信号 设置滑动条1的显示文本
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(sethorizontalSliderValue1(QString)));

    //设置滑动条控件2的最小值(-5)
    ui->horizontalSlider_2->setMinimum(0);
    //设置滑动条控件2的最大值(+5)
    ui->horizontalSlider_2->setMaximum(10);
    //设置滑动条控件2的初始值(0)
    ui->horizontalSlider_2->setValue(5);
    //信号和槽 当滑动条2的值发生改变时，即产生一个valueChanged(int)信号 设置QLineEdit控件2的显示文本
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(setLineEditValue2(int)));
    //信号和槽 当QLineEdit控件2的值发生改变时，即产生一个textChanged(QString)信号 设置滑动条2的显示文本
    connect(ui->lineEdit_2, SIGNAL(textChanged(QString)), this, SLOT(sethorizontalSliderValue2(QString)));
    this->setWindowIcon(QIcon(":/image/Image/icons8-name-tag-64.ico"));
}

dCameraSetting::~dCameraSetting()
{
    delete ui;
}

/*滑动条1值变化时，设置QLineEdit控件1的显示文本*/
void dCameraSetting::setLineEditValue1(int)
{
    int pos = (ui->horizontalSlider->value())-5;
    QString str = QString("%1").arg(pos);
    ui->lineEdit->setText(str);
    CameraExposure = ((ui->horizontalSlider->value())-5)*10;   //将摄像头曝光度数据传入变量CameraExposure
}

/*滑动条2值变化时，设置QLineEdit控件2的显示文本*/
void dCameraSetting::setLineEditValue2(int)
{
    double pos = (ui->horizontalSlider_2->value())-5;
    QString str = QString("%1").arg(pos);
    ui->lineEdit_2->setText(str);
    CameraFocalLenth = (ui->horizontalSlider_2->value())-5;  //将摄像头曝光度数据传入变量CameraFocalLenth
}

/*定义槽；button“取消”；关闭摄像头设置界面*/
void dCameraSetting::on_pushButton_2_clicked()
{
    close();
}

/*QLineEdit控件1的显示文本变化时，设置滑动条1值*/
void dCameraSetting::sethorizontalSliderValue1(QString)
{
    QString str = ui->lineEdit->text();
    double pos = str.toDouble();
    ui->horizontalSlider->setValue(pos+5);
}

/*QLineEdit控件2的显示文本变化时，设置滑动条2值*/
void dCameraSetting::sethorizontalSliderValue2(QString)
{
    QString str = ui->lineEdit_2->text();
    double pos = str.toDouble();
    ui->horizontalSlider_2->setValue(pos+5);
}

/*定义槽，当点击checkbox“设置曝光度”后，判断其状态是否被选中，选中则CameraAutoExposure为true,否则为false*/
void dCameraSetting::on_checkBox_clicked()
{
    if(ui->checkBox->checkState() == Qt::Checked)
        CameraAutoExposure = true;
    else
        CameraAutoExposure = false;
}

/*定义槽，当点击checkbox_2“设置焦距”后，判断其状态是否被选中，选中则CameraAutoFocus为true,否则为false*/
void dCameraSetting::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->checkState() == Qt::Checked)
        CameraAutoFocus = true;
    else
        CameraAutoFocus = false;
}

/*定义槽，当下拉框comboBox的内容发生变化时，将当前所选值赋给CamerType*/
void dCameraSetting::on_comboBox_currentTextChanged(const QString &arg1)
{
    CameraType = ui->cameracomboBox->currentText();
}

//////////////////////////////////////////////////////////////
/*定义槽，button“确定”，调用槽函数send_CameraSettingData(QVariant)，
 * 将封装后的摄像头设置数据传递给MainWindow系统设置。关闭摄像头设置界面*/
void dCameraSetting::on_pushButton_clicked()
{
    //将摄像头设置数据结构体封装成一个QVariant
    //    CameraSettingData camera_setting_data;
    //    QVariant camera_setting_data_var;

    //摄像头设置完成后赋值
    CameraExposure = ((ui->horizontalSlider->value())-5)*10;
    if(CameraAutoExposure)
        CameraExposure = 0.0;
    //camera_setting_data.CameraAutoFocus = CameraAutoFocus;
    //camera_setting_data_var.setValue(camera_setting_data);
    emit send_CameraSettingData(CameraExposure);
    close();
}
