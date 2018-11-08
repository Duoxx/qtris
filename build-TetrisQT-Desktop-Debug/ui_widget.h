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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdLevel;
    QSpacerItem *verticalSpacer;
    QPushButton *rotateBtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *moveLeftBtn;
    QPushButton *moveRightBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(409, 464);
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);
        lcdNumber->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(lcdNumber);

        lcdLevel = new QLCDNumber(Widget);
        lcdLevel->setObjectName(QStringLiteral("lcdLevel"));
        sizePolicy.setHeightForWidth(lcdLevel->sizePolicy().hasHeightForWidth());
        lcdLevel->setSizePolicy(sizePolicy);
        lcdLevel->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(lcdLevel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        rotateBtn = new QPushButton(Widget);
        rotateBtn->setObjectName(QStringLiteral("rotateBtn"));

        verticalLayout->addWidget(rotateBtn);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        moveLeftBtn = new QPushButton(Widget);
        moveLeftBtn->setObjectName(QStringLiteral("moveLeftBtn"));

        horizontalLayout->addWidget(moveLeftBtn);

        moveRightBtn = new QPushButton(Widget);
        moveRightBtn->setObjectName(QStringLiteral("moveRightBtn"));

        horizontalLayout->addWidget(moveRightBtn);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        rotateBtn->setText(QApplication::translate("Widget", "Rotate", Q_NULLPTR));
        moveLeftBtn->setText(QApplication::translate("Widget", "<", Q_NULLPTR));
        moveRightBtn->setText(QApplication::translate("Widget", ">", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
