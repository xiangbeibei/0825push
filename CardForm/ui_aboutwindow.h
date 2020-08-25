/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QPushButton *check;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QScrollBar *verticalScrollBar;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QScrollBar *verticalScrollBar_2;
    QLabel *logolabel;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QStringLiteral("AboutWindow"));
        AboutWindow->resize(400, 250);
        AboutWindow->setStyleSheet(QStringLiteral("background-color:rgb(1,192,198)"));
        check = new QPushButton(AboutWindow);
        check->setObjectName(QStringLiteral("check"));
        check->setGeometry(QRect(320, 220, 75, 24));
        check->setStyleSheet(QStringLiteral("border:3px solid white;background:rgb(1,192,198);color:white;font-size:15px;"));
        label = new QLabel(AboutWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 0, 250, 30));
        label->setStyleSheet(QStringLiteral("color:white"));
        label_2 = new QLabel(AboutWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 30, 250, 30));
        label_2->setStyleSheet(QStringLiteral("color:white"));
        label_4 = new QLabel(AboutWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 90, 250, 30));
        label_4->setStyleSheet(QStringLiteral("color:white"));
        verticalScrollBar = new QScrollBar(AboutWindow);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(370, 131, 19, 78));
        verticalScrollBar->setOrientation(Qt::Vertical);
        label_3 = new QLabel(AboutWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 60, 250, 30));
        label_3->setStyleSheet(QStringLiteral("color:white"));
        textBrowser = new QTextBrowser(AboutWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(160, 130, 230, 80));
        textBrowser->setStyleSheet(QStringLiteral("background-color:white"));
        verticalScrollBar_2 = new QScrollBar(AboutWindow);
        verticalScrollBar_2->setObjectName(QStringLiteral("verticalScrollBar_2"));
        verticalScrollBar_2->setGeometry(QRect(370, 131, 19, 78));
        verticalScrollBar_2->setOrientation(Qt::Vertical);
        logolabel = new QLabel(AboutWindow);
        logolabel->setObjectName(QStringLiteral("logolabel"));
        logolabel->setGeometry(QRect(10, 0, 140, 250));
        logolabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Image/company.png")));
        logolabel->setScaledContents(true);

        retranslateUi(AboutWindow);

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "\345\205\263\344\272\216\346\210\221\344\273\254", 0));
        check->setText(QApplication::translate("AboutWindow", "\347\241\256\345\256\232(&O)", 0));
        label->setText(QApplication::translate("AboutWindow", "\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232\346\231\272\350\203\275\344\272\272\350\257\201\346\240\270\351\252\214\347\263\273\347\273\237", 0));
        label_2->setText(QApplication::translate("AboutWindow", "\347\211\210\346\234\254\357\274\232V3.0", 0));
        label_4->setText(QApplication::translate("AboutWindow", "\347\211\210\346\235\203\346\211\200\346\234\211\357\274\214\344\273\277\347\233\227\345\277\205\347\251\266", 0));
        label_3->setText(QApplication::translate("AboutWindow", "\347\211\210\346\235\203\346\211\200\346\234\211\357\274\232\346\210\220\351\203\275\345\234\243\345\215\232\346\266\246\347\247\221\346\212\200\346\234\211\351\231\220\345\205\254\345\217\270", 0));
        textBrowser->setHtml(QApplication::translate("AboutWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\256\242\346\234\215\347\203\255\347\272\277\357\274\232028-85151810</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\224\265\345\255\220\351\202\256\347\256\261\357\274\232cdzhangfy@126.com</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inden"
                        "t:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\205\254\345\217\270\345\256\230\347\275\221\357\274\232www.sbrid.com</p></body></html>", 0));
        logolabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
