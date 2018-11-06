/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *moveLeftBtn;
    QPushButton *moveRightBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(409, 464);
        moveLeftBtn = new QPushButton(Widget);
        moveLeftBtn->setObjectName(QStringLiteral("moveLeftBtn"));
        moveLeftBtn->setGeometry(QRect(240, 430, 80, 25));
        moveRightBtn = new QPushButton(Widget);
        moveRightBtn->setObjectName(QStringLiteral("moveRightBtn"));
        moveRightBtn->setGeometry(QRect(320, 430, 80, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        moveLeftBtn->setText(QApplication::translate("Widget", "<", Q_NULLPTR));
        moveRightBtn->setText(QApplication::translate("Widget", ">", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
