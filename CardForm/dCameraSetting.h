#ifndef dCameraSetting_H
#define dCameraSetting_H

#include <QDialog>
#include <QVariant>
#include <QString>

namespace Ui {
class dCameraSetting;
}

/*定义结构体CameraSettingData保存摄像头设置的数据*/
struct CameraSettingData
{
    QString CameraType;
    float CameraExposure;
    float CameraFocalLenth;
    bool CameraAutoExposure;
    bool CameraAutoFocus;
};
Q_DECLARE_METATYPE(CameraSettingData)


class dCameraSetting : public QDialog
{
    Q_OBJECT
public:
    /*设置变量，记录摄像头设置的各项数据*/
    QString CameraType;
    float CameraExposure;
    float CameraFocalLenth;
    bool CameraAutoExposure;
    bool CameraAutoFocus;

public:
    explicit dCameraSetting(QWidget *parent = 0);
    ~dCameraSetting();

signals:
    void send_CameraSettingData(float); //定义信号传递封装后的结构体参数给MainWindow"系统设置"

private slots:
    void setLineEditValue1(int value);
    void setLineEditValue2(int value);

    void sethorizontalSliderValue1(QString value);
    void sethorizontalSliderValue2(QString value);

    void on_pushButton_2_clicked();  //button“取消”

    void on_pushButton_clicked();  //button“确定”

    void on_checkBox_clicked();  //checkbutton“自动曝光”

    void on_checkBox_2_clicked();  //checkbutton“自动对焦”

    void on_comboBox_currentTextChanged(const QString &arg1);  //combobutton“选择摄像头”

private:
    Ui::dCameraSetting *ui;
};

#endif // dCameraSetting_H
