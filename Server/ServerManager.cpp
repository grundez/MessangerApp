#include "ServerManager.h"

ServerManager::ServerManager(ushort port, QObject *parent)
    : QObject{parent}
{
    setupServer(port);
}

void ServerManager::notifyOtherClients(QString prevName, QString name)
{
    auto message = _protocol.setClientNameMessage(prevName, name);
    foreach (auto cl, _clients) {
        auto clientName = cl->property("clientName").toString();
        if (clientName != name) {
            cl->write(message);
        }
    }
}

void ServerManager::onTextForOtherClients(QString message, QString receiver, QString sender)
{
    auto msg = _protocol.textMessage(sender, message, receiver);
    if (receiver == "All") {
        foreach (auto cl, _clients) {
            auto clientName = cl->property("clientName").toString();
            if (clientName != sender) {
                cl->write(msg);
            }
        }
    } else {
        foreach (auto cl, _clients) {
            auto clientName = cl->property("clientName").toString();
            if (clientName == receiver) {
                cl->write(msg);
                return;
            }
        }
    }
}

void ServerManager::newClientConnection()
{
    auto client = _server->nextPendingConnection();

    auto id = _clients.count() + 1;
    auto clientName = QString("Client %1").arg(id);
    client->setProperty("id", id);
    client->setProperty("clientName", clientName);

    connect(client, &QTcpSocket::disconnected, this, &ServerManager::slotClientDisconnected);
    emit newClientConnected(client);

    if(id>1){
        auto message = _protocol.setConnectionACKMessage(clientName, _clients.keys());
        client->write(message);

        auto newClientMessage = _protocol.setNewClientMessage(clientName);
        foreach (auto cl, _clients){
            cl->write(newClientMessage);
        }
    }
    _clients[clientName] = client;
}

void ServerManager::slotClientDisconnected()
{
    auto client = qobject_cast<QTcpSocket*>(sender());
    //int id = client->property("id").toInt();
    auto clientName = client->property("clientName").toString();
    _clients.remove(clientName);
    auto message = _protocol.setClinetDisconnectedMessage(clientName);
    foreach(auto cl, _clients){
        cl->write(message);
    }

    emit clientDisconnected(client);
}

QMap<QString, QTcpSocket *> ServerManager::clients() const
{
    return _clients;
}

void ServerManager::setupServer(ushort port)
{
    _server = new QTcpServer(this);
    connect(_server, &QTcpServer::newConnection, this, &ServerManager::newClientConnection);
    _server->listen(QHostAddress::Any, port);
}
