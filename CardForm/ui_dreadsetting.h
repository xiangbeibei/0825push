/********************************************************************************
** Form generated from reading UI file 'dreadsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DREADSETTING_H
#define UI_DREADSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_dReadSetting
{
public:
    QLabel *label;
    QLabel *defaultlabel;
    QLabel *label_3;
    QCheckBox *defaultcheckBox;
    QComboBox *readercomboBox;
    QToolButton *checktoolButton;
    QToolButton *canceltoolButton_2;
    QGroupBox *groupBox;

    void setupUi(QDialog *dReadSetting)
    {
        if (dReadSetting->objectName().isEmpty())
            dReadSetting->setObjectName(QStringLiteral("dReadSetting"));
        dReadSetting->resize(421, 157);
        dReadSetting->setStyleSheet(QStringLiteral("background-color:rgb(1,192,198)"));
        label = new QLabel(dReadSetting);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 121, 21));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white"));
        defaultlabel = new QLabel(dReadSetting);
        defaultlabel->setObjectName(QStringLiteral("defaultlabel"));
        defaultlabel->setGeometry(QRect(190, 20, 191, 21));
        defaultlabel->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white"));
        label_3 = new QLabel(dReadSetting);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 60, 121, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white"));
        defaultcheckBox = new QCheckBox(dReadSetting);
        defaultcheckBox->setObjectName(QStringLiteral("defaultcheckBox"));
        defaultcheckBox->setGeometry(QRect(40, 100, 141, 16));
        defaultcheckBox->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";color:white"));
        readercomboBox = new QComboBox(dReadSetting);
        readercomboBox->setObjectName(QStringLiteral("readercomboBox"));
        readercomboBox->setGeometry(QRect(190, 60, 191, 21));
        checktoolButton = new QToolButton(dReadSetting);
        checktoolButton->setObjectName(QStringLiteral("checktoolButton"));
        checktoolButton->setGeometry(QRect(220, 100, 71, 31));
        checktoolButton->setStyleSheet(QStringLiteral("border:2px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold"));
        canceltoolButton_2 = new QToolButton(dReadSetting);
        canceltoolButton_2->setObjectName(QStringLiteral("canceltoolButton_2"));
        canceltoolButton_2->setGeometry(QRect(310, 100, 71, 31));
        canceltoolButton_2->setStyleSheet(QStringLiteral("border:2px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold"));
        groupBox = new QGroupBox(dReadSetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(5, 5, 411, 146));
        groupBox->setStyleSheet(QStringLiteral("border:2px solid white;background:rgb(1,192,198);color:white;font-size:15px;font-weight:bold"));
        groupBox->raise();
        label->raise();
        defaultlabel->raise();
        label_3->raise();
        defaultcheckBox->raise();
        readercomboBox->raise();
        checktoolButton->raise();
        canceltoolButton_2->raise();

        retranslateUi(dReadSetting);

        QMetaObject::connectSlotsByName(dReadSetting);
    } // setupUi

    void retranslateUi(QDialog *dReadSetting)
    {
        dReadSetting->setWindowTitle(QApplication::translate("dReadSetting", "Dialog", 0));
        label->setText(QApplication::translate("dReadSetting", "\351\273\230\350\256\244\351\230\205\350\257\273\345\231\250\345\236\213\345\217\267\357\274\232", 0));
        defaultlabel->setText(QString());
        label_3->setText(QApplication::translate("dReadSetting", "\346\224\257\346\214\201\351\230\205\350\257\273\345\231\250\345\236\213\345\217\267\357\274\232", 0));
        defaultcheckBox->setText(QApplication::translate("dReadSetting", "\350\256\276\347\275\256\344\270\272\351\273\230\350\256\244\351\230\205\350\257\273\345\231\250", 0));
        checktoolButton->setText(QApplication::translate("dReadSetting", "\347\241\256\345\256\232", 0));
        canceltoolButton_2->setText(QApplication::translate("dReadSetting", "\345\217\226\346\266\210", 0));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class dReadSetting: public Ui_dReadSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DREADSETTING_H
