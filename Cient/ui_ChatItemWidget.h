/********************************************************************************
** Form generated from reading UI file 'ChatItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATITEMWIDGET_H
#define UI_CHATITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatItemWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblMessage;
    QLabel *lblTime;

    void setupUi(QWidget *ChatItemWidget)
    {
        if (ChatItemWidget->objectName().isEmpty())
            ChatItemWidget->setObjectName("ChatItemWidget");
        ChatItemWidget->resize(482, 100);
        verticalLayout = new QVBoxLayout(ChatItemWidget);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(ChatItemWidget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("border-radius: 25px;\n"
"border: 2px;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lblMessage = new QLabel(widget);
        lblMessage->setObjectName("lblMessage");
        lblMessage->setMinimumSize(QSize(0, 0));
        lblMessage->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        lblMessage->setFont(font);

        verticalLayout_2->addWidget(lblMessage);

        lblTime = new QLabel(widget);
        lblTime->setObjectName("lblTime");
        lblTime->setMinimumSize(QSize(0, 0));
        lblTime->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(lblTime);


        verticalLayout->addWidget(widget);


        retranslateUi(ChatItemWidget);

        QMetaObject::connectSlotsByName(ChatItemWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatItemWidget)
    {
        ChatItemWidget->setWindowTitle(QCoreApplication::translate("ChatItemWidget", "Form", nullptr));
        lblMessage->setText(QCoreApplication::translate("ChatItemWidget", "Message", nullptr));
        lblTime->setText(QCoreApplication::translate("ChatItemWidget", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatItemWidget: public Ui_ChatItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATITEMWIDGET_H
