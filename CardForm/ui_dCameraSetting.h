/********************************************************************************
** Form generated from reading UI file 'dCameraSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCAMERASETTING_H
#define UI_DCAMERASETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_dCameraSetting
{
public:
    QCheckBox *checkBox;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QCheckBox *checkBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QComboBox *cameracomboBox;

    void setupUi(QDialog *dCameraSetting)
    {
        if (dCameraSetting->objectName().isEmpty())
            dCameraSetting->setObjectName(QStringLiteral("dCameraSetting"));
        dCameraSetting->resize(500, 300);
        dCameraSetting->setStyleSheet(QStringLiteral("background-color:rgb(1,192,198)"));
        checkBox = new QCheckBox(dCameraSetting);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setGeometry(QRect(90, 180, 111, 25));
        checkBox->setStyleSheet(QStringLiteral(""));
        horizontalSlider_2 = new QSlider(dCameraSetting);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(200, 140, 160, 22));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(dCameraSetting);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 240, 80, 40));
        label = new QLabel(dCameraSetting);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 20, 200, 50));
        label->setStyleSheet(QStringLiteral("font-color:white;"));
        label->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(dCameraSetting);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(200, 110, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        checkBox_2 = new QCheckBox(dCameraSetting);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(230, 180, 111, 25));
        checkBox_2->setMouseTracking(true);
        checkBox_2->setTristate(false);
        label_3 = new QLabel(dCameraSetting);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(89, 110, 101, 25));
        label_4 = new QLabel(dCameraSetting);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(89, 140, 101, 25));
        pushButton = new QPushButton(dCameraSetting);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 240, 80, 40));
        label_2 = new QLabel(dCameraSetting);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(129, 70, 111, 25));
        label_2->setStyleSheet(QStringLiteral("font-color:white"));
        lineEdit = new QLineEdit(dCameraSetting);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(370, 110, 30, 25));
        lineEdit->setStyleSheet(QStringLiteral("background-color:white"));
        lineEdit_2 = new QLineEdit(dCameraSetting);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(370, 140, 30, 25));
        lineEdit_2->setStyleSheet(QStringLiteral("background-color:white"));
        cameracomboBox = new QComboBox(dCameraSetting);
        cameracomboBox->setObjectName(QStringLiteral("cameracomboBox"));
        cameracomboBox->setGeometry(QRect(240, 70, 111, 22));

        retranslateUi(dCameraSetting);

        QMetaObject::connectSlotsByName(dCameraSetting);
    } // setupUi

    void retranslateUi(QDialog *dCameraSetting)
    {
        dCameraSetting->setWindowTitle(QApplication::translate("dCameraSetting", "Dialog", 0));
        checkBox->setText(QApplication::translate("dCameraSetting", "\350\207\252\345\212\250\346\233\235\345\205\211", 0));
        pushButton_2->setText(QApplication::translate("dCameraSetting", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("dCameraSetting", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">\350\256\276\347\275\256\346\221\204\345\203\217\345\244\264\345\217\202\346\225\260</span></p></body></html>", 0));
        checkBox_2->setText(QApplication::translate("dCameraSetting", "\350\207\252\345\212\250\345\257\271\347\204\246", 0));
        label_3->setText(QApplication::translate("dCameraSetting", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">\350\256\276\347\275\256\346\233\235\345\205\211\345\272\246\357\274\232</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("dCameraSetting", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">\350\256\276\347\275\256\347\204\246\350\267\235\357\274\232</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("dCameraSetting", "\347\241\256\345\256\232", 0));
        label_2->setText(QApplication::translate("dCameraSetting", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">\351\200\211\346\213\251\346\221\204\345\203\217\345\244\264\357\274\232</span></p></body></html>", 0));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dCameraSetting: public Ui_dCameraSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCAMERASETTING_H
