#ifndef CLIENTCHATWIDGET_H
#define CLIENTCHATWIDGET_H

#include "ClientManager.h"
#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ClientChatWidget;
}

class ClientChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientChatWidget(QTcpSocket *client, QWidget *parent = nullptr);
    void disconnect();
    ~ClientChatWidget();

private slots:
    void on_btnSend_clicked();
    void clientDisconnected();
    void textMessageReceived(QString sender, QString message, QString receiver);
    void onTyping();
    void on_lnMessage_returnPressed();
    void onInitReceivingFile(QString clientName, QString fileName, qint64 fileSize);
    void onFileSaved(QString path);
    void on_lblOpenFolder_linkActivated(const QString &link);
    void onClientNameChanged(QString prevName, QString name);

signals:
    void clientNameChanged(QString prevName, QString name);
    void isTyping(QString message);
    void statusChanged(ChatProtocol::Status status);
    void textForOtherClients(QString message, QString receiver, QString sender);

private:
    Ui::ClientChatWidget *ui;
    ClientManager *_client;
    QDir dir;
};

#endif // CLIENTCHATWIDGET_H
