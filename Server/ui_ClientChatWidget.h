/********************************************************************************
** Form generated from reading UI file 'ClientChatWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTCHATWIDGET_H
#define UI_CLIENTCHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientChatWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *lstMessages;
    QWidget *wdgSend;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lnMessage;
    QPushButton *btnSend;
    QLabel *lblOpenFolder;

    void setupUi(QWidget *ClientChatWidget)
    {
        if (ClientChatWidget->objectName().isEmpty())
            ClientChatWidget->setObjectName("ClientChatWidget");
        ClientChatWidget->resize(656, 438);
        ClientChatWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(50,50,50);"));
        verticalLayout = new QVBoxLayout(ClientChatWidget);
        verticalLayout->setObjectName("verticalLayout");
        lstMessages = new QListWidget(ClientChatWidget);
        lstMessages->setObjectName("lstMessages");
        lstMessages->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        verticalLayout->addWidget(lstMessages);

        wdgSend = new QWidget(ClientChatWidget);
        wdgSend->setObjectName("wdgSend");
        horizontalLayout = new QHBoxLayout(wdgSend);
        horizontalLayout->setObjectName("horizontalLayout");
        lnMessage = new QLineEdit(wdgSend);
        lnMessage->setObjectName("lnMessage");
        lnMessage->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        horizontalLayout->addWidget(lnMessage);

        btnSend = new QPushButton(wdgSend);
        btnSend->setObjectName("btnSend");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        btnSend->setFont(font);
        btnSend->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        horizontalLayout->addWidget(btnSend);

        lblOpenFolder = new QLabel(wdgSend);
        lblOpenFolder->setObjectName("lblOpenFolder");

        horizontalLayout->addWidget(lblOpenFolder);


        verticalLayout->addWidget(wdgSend);


        retranslateUi(ClientChatWidget);

        QMetaObject::connectSlotsByName(ClientChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientChatWidget)
    {
        ClientChatWidget->setWindowTitle(QCoreApplication::translate("ClientChatWidget", "Form", nullptr));
        btnSend->setText(QCoreApplication::translate("ClientChatWidget", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        lblOpenFolder->setText(QCoreApplication::translate("ClientChatWidget", "<html><head/><body><p><a href=\"#\"><span style=\" text-decoration: underline; color:#007af4;\">File</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientChatWidget: public Ui_ClientChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTCHATWIDGET_H
