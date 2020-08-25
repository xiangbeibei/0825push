#include "loadingwindow.h"
#include "ui_loadingwindow.h"

LoadingWindow::LoadingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowIcon(QIcon(":/image/Image/icons8-name-tag-64.ico"));
    QMovie *movie = new QMovie(":/image/Image/loading.gif");
    ui->loading_movie->setMovie(movie);
    movie->start();
}
void LoadingWindow::setLoadingText(QString LoadingText)
{
    ui->Loadingtext->setText(LoadingText);
}
LoadingWindow::~LoadingWindow()
{
    delete ui;
}
