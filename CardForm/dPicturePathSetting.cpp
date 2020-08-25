#include "dPicturePathSetting.h"
#include "ui_dPicturePathSetting.h"

dPicturePathSetting::dPicturePathSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dPicturePathSetting)
{
    ui->setupUi(this);
}

dPicturePathSetting::~dPicturePathSetting()
{
    delete ui;
}
