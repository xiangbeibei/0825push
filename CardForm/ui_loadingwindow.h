/********************************************************************************
** Form generated from reading UI file 'loadingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGWINDOW_H
#define UI_LOADINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingWindow
{
public:
    QLabel *loading_movie;
    QLabel *Loadingtext;

    void setupUi(QWidget *LoadingWindow)
    {
        if (LoadingWindow->objectName().isEmpty())
            LoadingWindow->setObjectName(QStringLiteral("LoadingWindow"));
        LoadingWindow->resize(780, 148);
        LoadingWindow->setStyleSheet(QStringLiteral("background-color:rgb(1,192,198)"));
        loading_movie = new QLabel(LoadingWindow);
        loading_movie->setObjectName(QStringLiteral("loading_movie"));
        loading_movie->setGeometry(QRect(50, 20, 95, 95));
        loading_movie->setScaledContents(true);
        Loadingtext = new QLabel(LoadingWindow);
        Loadingtext->setObjectName(QStringLiteral("Loadingtext"));
        Loadingtext->setGeometry(QRect(190, 30, 551, 71));
        Loadingtext->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold"));

        retranslateUi(LoadingWindow);

        QMetaObject::connectSlotsByName(LoadingWindow);
    } // setupUi

    void retranslateUi(QWidget *LoadingWindow)
    {
        LoadingWindow->setWindowTitle(QApplication::translate("LoadingWindow", "Form", 0));
        loading_movie->setText(QString());
        Loadingtext->setText(QApplication::translate("LoadingWindow", "\346\255\243\345\234\250\345\212\240\350\275\275\344\270\255\350\257\267\347\250\215\345\220\216... ...", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadingWindow: public Ui_LoadingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGWINDOW_H
