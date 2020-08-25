/********************************************************************************
** Form generated from reading UI file 'dPicturePathSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPICTUREPATHSETTING_H
#define UI_DPICTUREPATHSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_dPicturePathSetting
{
public:

    void setupUi(QDialog *dPicturePathSetting)
    {
        if (dPicturePathSetting->objectName().isEmpty())
            dPicturePathSetting->setObjectName(QStringLiteral("dPicturePathSetting"));
        dPicturePathSetting->resize(400, 300);

        retranslateUi(dPicturePathSetting);

        QMetaObject::connectSlotsByName(dPicturePathSetting);
    } // setupUi

    void retranslateUi(QDialog *dPicturePathSetting)
    {
        dPicturePathSetting->setWindowTitle(QApplication::translate("dPicturePathSetting", "dPicturePathSetting", 0));
    } // retranslateUi

};

namespace Ui {
    class dPicturePathSetting: public Ui_dPicturePathSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPICTUREPATHSETTING_H
