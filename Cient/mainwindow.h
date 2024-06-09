#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ClientManager.h"
#include "ChatItemWidget.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_actionConnect_triggered();
    void dataRecieved(QString message);


    void on_btnSend_clicked();
    void on_actionExit_triggered();
    void on_lnClientName_editingFinished();
    void on_lnMessage_returnPressed();
    void on_comboBox_currentIndexChanged(int index);
    void onTyping();
    void on_btnSendFile_clicked();
    void onRejectReceivingFile();
    void onInitReceivingFile(QString clientName, QString fileName, qint64 fileSize);
    void on_lnMessage_textChanged(const QString &arg1);

    void onConnectionACK(QString myName, QStringList clientsName);
    void onNewClientConnectedToServer(QString clientName);
    void onClientNameChanged(QString prevName, QString clientName);
    void onClientDisconnected(QString clientName);

    void on_cmbDestination_currentIndexChanged(int index);
    void on_btnLogin_clicked();
    void on_btnExit_clicked();
    void on_lnClientName_returnPressed();

    void saveMessage(QString sender, QString receiver, QString message);
    void loadMessages();
    void clearMessagesTable();

private:
    Ui::MainWindow *ui;
    ClientManager *_client;

    void setupClient();
    void setupDatabase();
};
#endif // MAINWINDOW_H
