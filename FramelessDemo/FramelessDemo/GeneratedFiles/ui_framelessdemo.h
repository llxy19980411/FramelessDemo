/********************************************************************************
** Form generated from reading UI file 'framelessdemo.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMELESSDEMO_H
#define UI_FRAMELESSDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FramelessDemoClass
{
public:

    void setupUi(QWidget *FramelessDemoClass)
    {
        if (FramelessDemoClass->objectName().isEmpty())
            FramelessDemoClass->setObjectName(QStringLiteral("FramelessDemoClass"));
        FramelessDemoClass->resize(600, 400);

        retranslateUi(FramelessDemoClass);

        QMetaObject::connectSlotsByName(FramelessDemoClass);
    } // setupUi

    void retranslateUi(QWidget *FramelessDemoClass)
    {
        FramelessDemoClass->setWindowTitle(QApplication::translate("FramelessDemoClass", "FramelessDemo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FramelessDemoClass: public Ui_FramelessDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMELESSDEMO_H
