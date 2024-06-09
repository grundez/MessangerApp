#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "ChatProtocol.h"
#include <QObject>
#include <QTcpSocket>
#include <QDir>

class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QHostAddress ip = QHostAddress::LocalHost, ushort port = 4500, QObject *parent = nullptr);
    explicit ClientManager(QTcpSocket *client, QObject *parent = nullptr);

    void connectToServer();
    void disconnectFromServer();
    void sendMessage(QString message);
    void sendName(QString name);
    void sendStatus(ChatProtocol::Status status);
    QString name() const;
    void sendIsTyping();

    void sendInitSendingFile(QString fileName);
    void sendAcceptFile();
    void sendRejectFile();

signals:
    void connected();
    void disconnected();
    //void dataRecieved(QByteArray data);
    void textMessageReceived(QString sender, QString message, QString receiver);
    void isTyping();
    void serverDisconnected();
    void nameChanged(QString prevName, QString name);
    void statusChanged(ChatProtocol::Status status);
    void rejectReceivingFile();
    void initReceivingFile(QString clientName, QString fileName, qint64 fileSize);
    void fileSaved(QString path);

private slots:
    void readyRead();

private:
    QTcpSocket *_socket;
    QHostAddress _ip;
    ushort _port;
    ChatProtocol _protocol;
    QString _tmpFileName;

private:
    void setupClient();
    void sendFile();
    void saveFile();
};

#endif // CLIENTMANAGER_H
