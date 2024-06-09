#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ServerManager.h>
#include <ClientChatWidget.h>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void newClientConnect(QTcpSocket *client);
    void clientDisconnect(QTcpSocket *client);
    void setClientName(QString prevName, QString name);
    void setClientStatus(ChatProtocol::Status status);

private slots:
    void on_tbChats_tabCloseRequested(int index);
    void on_btnDisconnectAll_clicked();

private: // поля
    Ui::MainWindow *ui;
    ServerManager *_server;

private: // методы
    void setupServer();
};
#endif // MAINWINDOW_H
