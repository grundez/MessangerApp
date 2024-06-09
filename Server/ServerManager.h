#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "ChatProtocol.h"

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(ushort port = 4500,
                           QObject *parent = nullptr);
    void notifyOtherClients(QString prevName, QString name);

    QMap<QString, QTcpSocket *> clients() const;

public slots:
    void onTextForOtherClients(QString message, QString receiver, QString sender);

private slots:
    void newClientConnection();
    void slotClientDisconnected();

signals:
    void newClientConnected(QTcpSocket* client);
    void clientDisconnected(QTcpSocket* client);

private: // поля
    QTcpServer *_server;
    QMap<QString, QTcpSocket*> _clients;
    ChatProtocol _protocol;

private: // методы
    void setupServer(ushort port);

};

#endif // SERVERMANAGER_H
