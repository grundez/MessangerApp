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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *grpClients;
    QListWidget *lstClients;
    QPushButton *btnDisconnectAll;
    QTabWidget *tbChats;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(876, 562);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(50,50,50);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        grpClients = new QGroupBox(centralwidget);
        grpClients->setObjectName("grpClients");
        grpClients->setGeometry(QRect(560, 10, 271, 491));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        grpClients->setFont(font);
        grpClients->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        lstClients = new QListWidget(grpClients);
        lstClients->setObjectName("lstClients");
        lstClients->setGeometry(QRect(20, 30, 231, 411));
        lstClients->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 100, 100);\n"
"border: 2px solid rgb(100, 100, 100);"));
        btnDisconnectAll = new QPushButton(grpClients);
        btnDisconnectAll->setObjectName("btnDisconnectAll");
        btnDisconnectAll->setGeometry(QRect(20, 450, 231, 31));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        btnDisconnectAll->setFont(font1);
        btnDisconnectAll->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgb(100, 100, 100); \n"
"border: 2px solid rgb(100, 100, 100);"));
        tbChats = new QTabWidget(centralwidget);
        tbChats->setObjectName("tbChats");
        tbChats->setGeometry(QRect(20, 8, 521, 491));
        tbChats->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(50,50,50);\n"
"border: rgb(50,50,50);"));
        tbChats->setTabsClosable(true);
        tbChats->setMovable(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 876, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Server", nullptr));
        grpClients->setTitle(QCoreApplication::translate("MainWindow", "Logs", nullptr));
        btnDisconnectAll->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\262\321\201\320\265\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
