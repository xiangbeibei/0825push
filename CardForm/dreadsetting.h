#ifndef DREADSETTING_H
#define DREADSETTING_H

#include <QDialog>
#include "ConfigManager.h"
namespace Ui {
class dReadSetting;
}

class dReadSetting : public QDialog
{
    Q_OBJECT

public:
    explicit dReadSetting(QWidget *parent = 0);
    void refreshData();
    ~dReadSetting();

private:
    Ui::dReadSetting *ui;
    ConfigManager *configManager;

private slots:
    void onBtncheck();
};

#endif // DREADSETTING_H
