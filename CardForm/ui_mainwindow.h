/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QGraphicsView *cameraView;
    QGroupBox *groupBox;
    QLabel *cardPicture;
    QLabel *peoplePicture;
    QLabel *resultPicture;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *smallpicture;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QToolButton *startToolButton;
    QToolButton *readToolButton;
    QToolButton *dataToolButton;
    QToolButton *settingToolButton;
    QToolButton *printToolButton;
    QToolButton *aboutToolButton;
    QToolButton *quitToolButton;
    QToolButton *MintoolButton;
    QToolButton *closetoolButton;
    QLabel *smallname;
    QLabel *smallgender;
    QLabel *smallnation;
    QLabel *smallyear;
    QLabel *smallmonth;
    QLabel *smallday;
    QLabel *smalladdress;
    QLabel *smallid;
    QLabel *smalloffice;
    QLabel *smallvalid;
    QLabel *labReaderState;
    QLabel *resultText;
    QLabel *resultNum;
    QFrame *line;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1235, 670);
        MainWindow->setStyleSheet(QStringLiteral("background-color:rgb(1,196,198)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 12, 474, 42));
        label->setStyleSheet(QString::fromUtf8("font: 27.75pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        cameraView = new QGraphicsView(centralWidget);
        cameraView->setObjectName(QStringLiteral("cameraView"));
        cameraView->setGeometry(QRect(10, 77, 671, 491));
        cameraView->setStyleSheet(QStringLiteral("background-color:white"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(686, 78, 538, 281));
        groupBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;border:3px solid white;border-radius:10px"));
        groupBox->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        cardPicture = new QLabel(centralWidget);
        cardPicture->setObjectName(QStringLiteral("cardPicture"));
        cardPicture->setGeometry(QRect(710, 98, 170, 210));
        cardPicture->setStyleSheet(QStringLiteral("background-color:white"));
        cardPicture->setAlignment(Qt::AlignCenter);
        peoplePicture = new QLabel(centralWidget);
        peoplePicture->setObjectName(QStringLiteral("peoplePicture"));
        peoplePicture->setGeometry(QRect(1027, 98, 170, 210));
        peoplePicture->setStyleSheet(QStringLiteral("background-color:white"));
        peoplePicture->setAlignment(Qt::AlignCenter);
        resultPicture = new QLabel(centralWidget);
        resultPicture->setObjectName(QStringLiteral("resultPicture"));
        resultPicture->setGeometry(QRect(898, 113, 107, 98));
        resultPicture->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(737, 318, 122, 23));
        label_2->setStyleSheet(QString::fromUtf8("font: 20px\"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1055, 318, 122, 23));
        label_3->setStyleSheet(QString::fromUtf8("font: 20px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        smallpicture = new QLabel(centralWidget);
        smallpicture->setObjectName(QStringLiteral("smallpicture"));
        smallpicture->setGeometry(QRect(950, 413, 121, 141));
        smallpicture->setStyleSheet(QStringLiteral("background-color:white"));
        smallpicture->setPixmap(QPixmap(QString::fromUtf8(":/image/Image/boss.png")));
        smallpicture->setScaledContents(true);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1121, 463, 91, 121));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/image/Image/Finger.png")));
        label_6->setScaledContents(true);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(688, 373, 411, 291));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;border:3px solid white;border-radius:10px"));
        groupBox_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 391, 221));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image/Image/ReadCard.png")));
        label_4->setScaledContents(true);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1108, 373, 114, 291));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;border:3px solid white;border-radius:10px"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1117, 633, 101, 23));
        label_7->setStyleSheet(QString::fromUtf8("font: 20px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        startToolButton = new QToolButton(centralWidget);
        startToolButton->setObjectName(QStringLiteral("startToolButton"));
        startToolButton->setGeometry(QRect(13, 573, 95, 91));
        startToolButton->setStyleSheet(QStringLiteral("border:3px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold;border-radius:10px"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/Image/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        startToolButton->setIcon(icon);
        startToolButton->setIconSize(QSize(60, 62));
        startToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        readToolButton = new QToolButton(centralWidget);
        readToolButton->setObjectName(QStringLiteral("readToolButton"));
        readToolButton->setGeometry(QRect(108, 573, 95, 91));
        readToolButton->setStyleSheet(QStringLiteral("border:3px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold;border-radius:10px"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/Image/readButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        readToolButton->setIcon(icon1);
        readToolButton->setIconSize(QSize(60, 60));
        readToolButton->setAutoRepeat(true);
        readToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        dataToolButton = new QToolButton(centralWidget);
        dataToolButton->setObjectName(QStringLiteral("dataToolButton"));
        dataToolButton->setGeometry(QRect(203, 573, 95, 91));
        dataToolButton->setStyleSheet(QStringLiteral("border:3px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold;border-radius:10px"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/Image/DataManage.png"), QSize(), QIcon::Normal, QIcon::Off);
        dataToolButton->setIcon(icon2);
        dataToolButton->setIconSize(QSize(60, 60));
        dataToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        settingToolButton = new QToolButton(centralWidget);
        settingToolButton->setObjectName(QStringLiteral("settingToolButton"));
        settingToolButton->setGeometry(QRect(298, 573, 95, 91));
        settingToolButton->setStyleSheet(QStringLiteral("border:3px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold;border-radius:10px"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/Image/SysSetup.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingToolButton->setIcon(icon3);
        settingToolButton->setIconSize(QSize(60, 60));
        settingToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        printToolButton = new QToolButton(centralWidget);
        printToolButton->setObjectName(QStringLiteral("printToolButton"));
        printToolButton->setGeometry(QRect(393, 573, 95, 91));
        printToolButton->setStyleSheet(QStringLiteral("border:3px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold;border-radius:10px"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/Image/Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printToolButton->setIcon(icon4);
        printToolButton->setIconSize(QSize(60, 60));
        printToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        aboutToolButton = new QToolButton(centralWidget);
        aboutToolButton->setObjectName(QStringLiteral("aboutToolButton"));
        aboutToolButton->setGeometry(QRect(488, 573, 95, 91));
        aboutToolButton->setStyleSheet(QStringLiteral("border:3px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold;border-radius:10px"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/Image/About.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutToolButton->setIcon(icon5);
        aboutToolButton->setIconSize(QSize(60, 62));
        aboutToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        quitToolButton = new QToolButton(centralWidget);
        quitToolButton->setObjectName(QStringLiteral("quitToolButton"));
        quitToolButton->setGeometry(QRect(583, 573, 95, 91));
        quitToolButton->setStyleSheet(QStringLiteral("border:3px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold;border-radius:10px"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/Image/Quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitToolButton->setIcon(icon6);
        quitToolButton->setIconSize(QSize(60, 65));
        quitToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MintoolButton = new QToolButton(centralWidget);
        MintoolButton->setObjectName(QStringLiteral("MintoolButton"));
        MintoolButton->setGeometry(QRect(1155, 0, 40, 40));
        MintoolButton->setStyleSheet(QStringLiteral("border:2px solid white;border-radius:5px"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/Image/Min.png"), QSize(), QIcon::Normal, QIcon::Off);
        MintoolButton->setIcon(icon7);
        MintoolButton->setIconSize(QSize(64, 64));
        MintoolButton->setAutoRaise(true);
        closetoolButton = new QToolButton(centralWidget);
        closetoolButton->setObjectName(QStringLiteral("closetoolButton"));
        closetoolButton->setGeometry(QRect(1195, 0, 40, 40));
        closetoolButton->setStyleSheet(QStringLiteral("border:2px solid white;border-radius:5px"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/Image/Close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closetoolButton->setIcon(icon8);
        closetoolButton->setIconSize(QSize(64, 64));
        closetoolButton->setAutoRaise(true);
        smallname = new QLabel(centralWidget);
        smallname->setObjectName(QStringLiteral("smallname"));
        smallname->setGeometry(QRect(760, 413, 61, 21));
        smallname->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smallgender = new QLabel(centralWidget);
        smallgender->setObjectName(QStringLiteral("smallgender"));
        smallgender->setGeometry(QRect(760, 439, 21, 18));
        smallgender->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smallnation = new QLabel(centralWidget);
        smallnation->setObjectName(QStringLiteral("smallnation"));
        smallnation->setGeometry(QRect(830, 439, 121, 18));
        smallnation->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smallyear = new QLabel(centralWidget);
        smallyear->setObjectName(QStringLiteral("smallyear"));
        smallyear->setGeometry(QRect(750, 467, 41, 21));
        smallyear->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smallmonth = new QLabel(centralWidget);
        smallmonth->setObjectName(QStringLiteral("smallmonth"));
        smallmonth->setGeometry(QRect(817, 467, 21, 21));
        smallmonth->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smallday = new QLabel(centralWidget);
        smallday->setObjectName(QStringLiteral("smallday"));
        smallday->setGeometry(QRect(857, 467, 21, 21));
        smallday->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smalladdress = new QLabel(centralWidget);
        smalladdress->setObjectName(QStringLiteral("smalladdress"));
        smalladdress->setGeometry(QRect(760, 486, 181, 41));
        smalladdress->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smalladdress->setWordWrap(true);
        smallid = new QLabel(centralWidget);
        smallid->setObjectName(QStringLiteral("smallid"));
        smallid->setGeometry(QRect(810, 543, 131, 21));
        smallid->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smallid->setWordWrap(true);
        smalloffice = new QLabel(centralWidget);
        smalloffice->setObjectName(QStringLiteral("smalloffice"));
        smalloffice->setGeometry(QRect(790, 569, 161, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        smalloffice->setFont(font);
        smalloffice->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        smallvalid = new QLabel(centralWidget);
        smallvalid->setObjectName(QStringLiteral("smallvalid"));
        smallvalid->setGeometry(QRect(790, 593, 161, 18));
        smallvalid->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";background:transparent"));
        labReaderState = new QLabel(centralWidget);
        labReaderState->setObjectName(QStringLiteral("labReaderState"));
        labReaderState->setGeometry(QRect(700, 633, 391, 23));
        labReaderState->setStyleSheet(QString::fromUtf8("font:20px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        resultText = new QLabel(centralWidget);
        resultText->setObjectName(QStringLiteral("resultText"));
        resultText->setGeometry(QRect(891, 318, 122, 23));
        resultText->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        resultText->setAlignment(Qt::AlignCenter);
        resultNum = new QLabel(centralWidget);
        resultNum->setObjectName(QStringLiteral("resultNum"));
        resultNum->setGeometry(QRect(890, 233, 122, 61));
        resultNum->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        resultNum->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 60, 1251, 3));
        line->setStyleSheet(QStringLiteral("background-color:white;border-top: solid white; "));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(886, 70, 131, 21));
        label_5->setStyleSheet(QString::fromUtf8("font:20px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        label_5->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(840, 363, 121, 21));
        label_8->setStyleSheet(QString::fromUtf8("font:20px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1120, 363, 91, 21));
        label_9->setStyleSheet(QString::fromUtf8("font:20px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        label_9->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        groupBox_2->raise();
        groupBox_3->raise();
        label->raise();
        cameraView->raise();
        groupBox->raise();
        cardPicture->raise();
        peoplePicture->raise();
        resultPicture->raise();
        label_2->raise();
        label_3->raise();
        smallpicture->raise();
        label_6->raise();
        label_7->raise();
        startToolButton->raise();
        readToolButton->raise();
        dataToolButton->raise();
        settingToolButton->raise();
        printToolButton->raise();
        aboutToolButton->raise();
        quitToolButton->raise();
        MintoolButton->raise();
        closetoolButton->raise();
        smallname->raise();
        smallgender->raise();
        smallnation->raise();
        smallyear->raise();
        smallmonth->raise();
        smallday->raise();
        smalladdress->raise();
        smallid->raise();
        smalloffice->raise();
        smallvalid->raise();
        labReaderState->raise();
        resultText->raise();
        resultNum->raise();
        line->raise();
        label_5->raise();
        label_8->raise();
        label_9->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1235, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CardForm", 0));
        label->setText(QApplication::translate("MainWindow", "\346\231\272 \350\203\275 \344\272\272 \350\257\201 \346\240\270 \351\252\214 \347\263\273 \347\273\237", 0));
        groupBox->setTitle(QString());
        cardPicture->setText(QString());
        peoplePicture->setText(QString());
        resultPicture->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "[\350\272\253\344\273\275\350\257\201\345\244\264\345\203\217]", 0));
        label_3->setText(QApplication::translate("MainWindow", "[\344\272\272\350\204\270\351\207\207\351\233\206\345\233\276]", 0));
        smallpicture->setText(QString());
        label_6->setText(QString());
        groupBox_2->setTitle(QString());
        label_4->setText(QString());
        groupBox_3->setTitle(QString());
        label_7->setText(QApplication::translate("MainWindow", "[\346\214\207\347\272\271\346\257\224\345\257\271]", 0));
        startToolButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\257\224\345\257\271", 0));
        readToolButton->setText(QApplication::translate("MainWindow", "\350\257\273\350\272\253\344\273\275\350\257\201", 0));
        dataToolButton->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\347\256\241\347\220\206", 0));
        settingToolButton->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        printToolButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\345\207\255\350\257\201", 0));
        aboutToolButton->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\210\221\344\273\254", 0));
        quitToolButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
        MintoolButton->setText(QApplication::translate("MainWindow", "...", 0));
        closetoolButton->setText(QApplication::translate("MainWindow", "...", 0));
        smallname->setText(QString());
        smallgender->setText(QString());
        smallnation->setText(QString());
        smallyear->setText(QString());
        smallmonth->setText(QString());
        smallday->setText(QString());
        smalladdress->setText(QString());
        smallid->setText(QString());
        smalloffice->setText(QString());
        smallvalid->setText(QString());
        labReaderState->setText(QApplication::translate("MainWindow", "[\346\234\252\345\220\257\345\212\250... ...]", 0));
        resultText->setText(QString());
        resultNum->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\346\257\224\345\257\271\344\277\241\346\201\257", 0));
        label_8->setText(QApplication::translate("MainWindow", "\350\272\253\344\273\275\350\257\201\344\277\241\346\201\257", 0));
        label_9->setText(QApplication::translate("MainWindow", "\346\214\207\347\272\271\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
