/********************************************************************************
** Form generated from reading UI file 'selectwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTWIDGET_H
#define UI_SELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectWidget
{
public:

    void setupUi(QWidget *selectWidget)
    {
        if (selectWidget->objectName().isEmpty())
            selectWidget->setObjectName(QStringLiteral("selectWidget"));
        selectWidget->resize(400, 300);

        retranslateUi(selectWidget);

        QMetaObject::connectSlotsByName(selectWidget);
    } // setupUi

    void retranslateUi(QWidget *selectWidget)
    {
        selectWidget->setWindowTitle(QApplication::translate("selectWidget", "selectWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class selectWidget: public Ui_selectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTWIDGET_H
