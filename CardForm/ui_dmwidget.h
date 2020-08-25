/********************************************************************************
** Form generated from reading UI file 'dmwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMWIDGET_H
#define UI_DMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DMWidget
{
public:

    void setupUi(QWidget *DMWidget)
    {
        if (DMWidget->objectName().isEmpty())
            DMWidget->setObjectName(QStringLiteral("DMWidget"));
        DMWidget->resize(400, 300);

        retranslateUi(DMWidget);

        QMetaObject::connectSlotsByName(DMWidget);
    } // setupUi

    void retranslateUi(QWidget *DMWidget)
    {
        DMWidget->setWindowTitle(QApplication::translate("DMWidget", "DMWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class DMWidget: public Ui_DMWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMWIDGET_H
