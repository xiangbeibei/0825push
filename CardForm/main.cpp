#include "Mainwindow.h"
#include <QApplication>
#include <Windows.h>
#include <QMessageBox>
bool checkOne()
{
    HANDLE m_hMutex  =  CreateMutex(NULL, FALSE,  L"CardForm" );
    if  (GetLastError()  ==  ERROR_ALREADY_EXISTS)  {
        CloseHandle(m_hMutex);
        m_hMutex  =  NULL;
        return  false;
    }
    else
        return true;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!checkOne()) {
        QMessageBox::information(NULL,"错误","请勿重复启动程序");
        return 0;
    }
    MainWindow w;
    w.show();

    return a.exec();
}
