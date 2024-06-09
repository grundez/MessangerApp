/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionExit;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pgLogin;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lnClientName;
    QPushButton *btnLogin;
    QWidget *pgMessanger;
    QPushButton *btnExit;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblStatus;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *lblDestination;
    QComboBox *cmbDestination;
    QListWidget *lstMessages;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lnMessage;
    QPushButton *btnSend;
    QPushButton *btnSendFile;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(610, 611);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(50,50,50);"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName("actionConnect");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        actionConnect->setFont(font);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 601, 561));
        pgLogin = new QWidget();
        pgLogin->setObjectName("pgLogin");
        widget = new QWidget(pgLogin);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(210, 240, 191, 52));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lnClientName = new QLineEdit(widget);
        lnClientName->setObjectName("lnClientName");
        lnClientName->setFont(font);
        lnClientName->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        verticalLayout->addWidget(lnClientName);

        btnLogin = new QPushButton(widget);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setFont(font);
        btnLogin->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(120,240,100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        verticalLayout->addWidget(btnLogin);

        stackedWidget->addWidget(pgLogin);
        pgMessanger = new QWidget();
        pgMessanger->setObjectName("pgMessanger");
        btnExit = new QPushButton(pgMessanger);
        btnExit->setObjectName("btnExit");
        btnExit->setGeometry(QRect(530, 22, 71, 21));
        btnExit->setFont(font);
        btnExit->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(240,120,100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));
        widget1 = new QWidget(pgMessanger);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 50, 591, 491));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lblStatus = new QLabel(widget1);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setFont(font);
        lblStatus->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));

        horizontalLayout_2->addWidget(lblStatus);

        comboBox = new QComboBox(widget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        horizontalLayout_2->addWidget(comboBox);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lblDestination = new QLabel(widget1);
        lblDestination->setObjectName("lblDestination");
        lblDestination->setMaximumSize(QSize(80, 16777215));
        lblDestination->setFont(font);
        lblDestination->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));

        horizontalLayout->addWidget(lblDestination);

        cmbDestination = new QComboBox(widget1);
        cmbDestination->addItem(QString());
        cmbDestination->addItem(QString());
        cmbDestination->setObjectName("cmbDestination");
        cmbDestination->setFont(font);
        cmbDestination->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        horizontalLayout->addWidget(cmbDestination);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        lstMessages = new QListWidget(widget1);
        lstMessages->setObjectName("lstMessages");
        lstMessages->setFont(font);
        lstMessages->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               "));

        verticalLayout_2->addWidget(lstMessages);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lnMessage = new QLineEdit(widget1);
        lnMessage->setObjectName("lnMessage");
        lnMessage->setFont(font);
        lnMessage->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        horizontalLayout_3->addWidget(lnMessage);

        btnSend = new QPushButton(widget1);
        btnSend->setObjectName("btnSend");
        btnSend->setFont(font);
        btnSend->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        horizontalLayout_3->addWidget(btnSend);

        btnSendFile = new QPushButton(widget1);
        btnSendFile->setObjectName("btnSendFile");
        btnSendFile->setMinimumSize(QSize(60, 0));
        btnSendFile->setMaximumSize(QSize(16777215, 16777215));
        btnSendFile->setFont(font);
        btnSendFile->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100);\n"
"border-radius: 9px;               \n"
"border: 2px solid rgb(100, 100, 100);"));

        horizontalLayout_3->addWidget(btnSendFile);


        verticalLayout_2->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(pgMessanger);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 610, 21));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        menuOptions->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionConnect);
        menuOptions->addSeparator();
        menuOptions->addAction(actionExit);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Client", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        lnClientName->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        btnExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        lblStatus->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Available", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Away", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Busy", nullptr));

        lblDestination->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\214", nullptr));
        cmbDestination->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        cmbDestination->setItemText(1, QCoreApplication::translate("MainWindow", "All", nullptr));

        lnMessage->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265...", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnSendFile->setText(QCoreApplication::translate("MainWindow", ">..", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
