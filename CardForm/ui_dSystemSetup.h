/********************************************************************************
** Form generated from reading UI file 'dSystemSetup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSYSTEMSETUP_H
#define UI_DSYSTEMSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_dSystemSetup
{
public:
    QPushButton *checkpushButton;
    QPushButton *cancelpushButton;
    QLabel *label;
    QToolButton *cameraSetting;
    QToolButton *imagePathSetting;
    QToolButton *readerSetting;
    QCheckBox *soundCheckBox;
    QCheckBox *cleanCheckBox;
    QCheckBox *thresholdCheckBox;
    QLabel *label_2;
    QLineEdit *cleanLineEdit;
    QLabel *label_3;
    QLineEdit *thresholdLineEdit;
    QFrame *line;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;

    void setupUi(QDialog *dSystemSetup)
    {
        if (dSystemSetup->objectName().isEmpty())
            dSystemSetup->setObjectName(QStringLiteral("dSystemSetup"));
        dSystemSetup->resize(534, 305);
        dSystemSetup->setAutoFillBackground(false);
        dSystemSetup->setStyleSheet(QStringLiteral("background-color:rgb(1,192,198)"));
        checkpushButton = new QPushButton(dSystemSetup);
        checkpushButton->setObjectName(QStringLiteral("checkpushButton"));
        checkpushButton->setGeometry(QRect(340, 10, 80, 31));
        checkpushButton->setStyleSheet(QString::fromUtf8("font: 25px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;border:none"));
        checkpushButton->setAutoRepeat(true);
        checkpushButton->setFlat(true);
        cancelpushButton = new QPushButton(dSystemSetup);
        cancelpushButton->setObjectName(QStringLiteral("cancelpushButton"));
        cancelpushButton->setGeometry(QRect(430, 10, 80, 31));
        cancelpushButton->setStyleSheet(QString::fromUtf8("font: 25px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;border:none"));
        cancelpushButton->setAutoRepeat(true);
        cancelpushButton->setFlat(true);
        label = new QLabel(dSystemSetup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(24, 10, 108, 31));
        label->setStyleSheet(QString::fromUtf8("font: 25px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold"));
        cameraSetting = new QToolButton(dSystemSetup);
        cameraSetting->setObjectName(QStringLiteral("cameraSetting"));
        cameraSetting->setGeometry(QRect(80, 94, 149, 43));
        cameraSetting->setStyleSheet(QString::fromUtf8("border:2px solid white;background:rgb(1,192,198);color:white;font-size:22px;font-weight:bold\357\274\233"));
        imagePathSetting = new QToolButton(dSystemSetup);
        imagePathSetting->setObjectName(QStringLiteral("imagePathSetting"));
        imagePathSetting->setGeometry(QRect(80, 154, 149, 43));
        imagePathSetting->setStyleSheet(QString::fromUtf8("border:2px solid white;background:rgb(1,192,198);color:white;font-size:22px;font-weight:bold\357\274\233"));
        readerSetting = new QToolButton(dSystemSetup);
        readerSetting->setObjectName(QStringLiteral("readerSetting"));
        readerSetting->setGeometry(QRect(80, 214, 149, 43));
        readerSetting->setStyleSheet(QString::fromUtf8("border:2px solid white;background:rgb(1,192,198);color:white;font-size:22px;font-weight:bold\357\274\233"));
        soundCheckBox = new QCheckBox(dSystemSetup);
        soundCheckBox->setObjectName(QStringLiteral("soundCheckBox"));
        soundCheckBox->setGeometry(QRect(290, 94, 121, 31));
        soundCheckBox->setStyleSheet(QString::fromUtf8("font: 22px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;"));
        cleanCheckBox = new QCheckBox(dSystemSetup);
        cleanCheckBox->setObjectName(QStringLiteral("cleanCheckBox"));
        cleanCheckBox->setGeometry(QRect(290, 134, 211, 31));
        cleanCheckBox->setStyleSheet(QString::fromUtf8("font: 22px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold"));
        thresholdCheckBox = new QCheckBox(dSystemSetup);
        thresholdCheckBox->setObjectName(QStringLiteral("thresholdCheckBox"));
        thresholdCheckBox->setGeometry(QRect(290, 214, 121, 31));
        thresholdCheckBox->setStyleSheet(QString::fromUtf8("font: 22px\"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold"));
        label_2 = new QLabel(dSystemSetup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 174, 51, 31));
        label_2->setStyleSheet(QString::fromUtf8("font:22px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold"));
        cleanLineEdit = new QLineEdit(dSystemSetup);
        cleanLineEdit->setObjectName(QStringLiteral("cleanLineEdit"));
        cleanLineEdit->setGeometry(QRect(360, 181, 61, 21));
        cleanLineEdit->setStyleSheet(QStringLiteral("background-color:white"));
        label_3 = new QLabel(dSystemSetup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 174, 71, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 22px \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold"));
        thresholdLineEdit = new QLineEdit(dSystemSetup);
        thresholdLineEdit->setObjectName(QStringLiteral("thresholdLineEdit"));
        thresholdLineEdit->setGeometry(QRect(410, 220, 61, 21));
        thresholdLineEdit->setStyleSheet(QStringLiteral("background-color:white"));
        line = new QFrame(dSystemSetup);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 50, 534, 2));
        line->setStyleSheet(QStringLiteral("background-color:white;border-top: solid white; "));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(dSystemSetup);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(270, 70, 241, 211));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;border:2px solid white;"));
        cancelpushButton->raise();
        groupBox_3 = new QGroupBox(dSystemSetup);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 70, 241, 211));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white;font-weight:bold;border:2px solid white;"));
        groupBox_2->raise();
        groupBox_3->raise();
        checkpushButton->raise();
        cancelpushButton->raise();
        label->raise();
        cameraSetting->raise();
        imagePathSetting->raise();
        readerSetting->raise();
        soundCheckBox->raise();
        cleanCheckBox->raise();
        thresholdCheckBox->raise();
        label_2->raise();
        cleanLineEdit->raise();
        label_3->raise();
        thresholdLineEdit->raise();
        line->raise();

        retranslateUi(dSystemSetup);

        QMetaObject::connectSlotsByName(dSystemSetup);
    } // setupUi

    void retranslateUi(QDialog *dSystemSetup)
    {
        dSystemSetup->setWindowTitle(QApplication::translate("dSystemSetup", "Dialog", 0));
        checkpushButton->setText(QApplication::translate("dSystemSetup", "\347\241\256\350\256\244", 0));
        cancelpushButton->setText(QApplication::translate("dSystemSetup", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("dSystemSetup", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        cameraSetting->setText(QApplication::translate("dSystemSetup", "\346\221\204\345\203\217\345\244\264\350\256\276\347\275\256", 0));
        imagePathSetting->setText(QApplication::translate("dSystemSetup", "\345\233\276\347\211\207\350\267\257\345\276\204\350\256\276\347\275\256", 0));
        readerSetting->setText(QApplication::translate("dSystemSetup", "\351\230\205\350\257\273\345\231\250\350\256\276\347\275\256", 0));
        soundCheckBox->setText(QApplication::translate("dSystemSetup", "\350\257\255\351\237\263\346\217\220\347\244\272", 0));
        cleanCheckBox->setText(QApplication::translate("dSystemSetup", "\350\207\252\345\212\250\346\270\205\351\231\244\346\230\276\347\244\272\345\206\205\345\256\271", 0));
        thresholdCheckBox->setText(QApplication::translate("dSystemSetup", "\350\256\276\347\275\256\351\230\210\345\200\274", 0));
        label_2->setText(QApplication::translate("dSystemSetup", "\345\273\266\350\277\237", 0));
        label_3->setText(QApplication::translate("dSystemSetup", "\347\247\222\346\270\205\351\231\244", 0));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class dSystemSetup: public Ui_dSystemSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSYSTEMSETUP_H
