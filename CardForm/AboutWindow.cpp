#include "AboutWindow.h"
#include "ui_aboutwindow.h"
#include <QPainter>

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/Image/icons8-name-tag-64.ico"));
    pixLogo=QPixmap(":/image/Image/company.png");
    pixLogo=pixLogo.scaled(140,250, Qt::KeepAspectRatio);
    ui->logolabel->setPixmap(pixLogo);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}


void AboutWindow::on_check_clicked()
{
    close();
}
