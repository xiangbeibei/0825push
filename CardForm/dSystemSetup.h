#ifndef DSYSTEMSETUP_H
#define DSYSTEMSETUP_H

#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include<QMouseEvent>
#include "ConfigManager.h"
#include "dreadsetting.h"
#include "dCameraSetting.h"
#include "Mainwindow.h"
#define CONFIG_REFESH 105
#define CONFIG_STAY 106

class MainWindow;
namespace Ui {
class dSystemSetup;
}

class dSystemSetup : public QDialog
{
    Q_OBJECT

public:
    explicit dSystemSetup(MainWindow *windows,QWidget *parent = 0);
    ~dSystemSetup();

private:
    Ui::dSystemSetup *ui;
    ConfigManager configmanager;
    void setInitWindowValue();
    dReadSetting *SelectReader;
    dCameraSetting *CameraSetting;
    MainWindow *win;
    QPoint last;
private slots:
    void onBtnCheck();
    void onBtnCancel();
    void onBtnCamera();
    void onBtnImage();
    void onBtnReader();
    void handleCameraSetting(float CameraExposure);
signals:
    void sendConfigMessage(int Status);
protected://重写鼠标事件，使窗口可移动
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // DSYSTEMSETUP_H
