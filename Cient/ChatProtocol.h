#ifndef CHATPROTOCOL_H
#define CHATPROTOCOL_H

#include <QByteArray>
#include <QString>
#include <QStringList>

class ChatProtocol
{
public:
    ChatProtocol();
    enum MessageType{
        Text,
        isTyping,
        SetName,
        SetStatus,
        InitSendingFile,
        AcceptSendingFile,
        RejectSendingFile,
        SendFile,
        ClientName,
        ConnectionACK,
        NewClient,
        ClientDisconnected
    };

    enum Status{
        None,
        Available,
        Away,
        Busy
    };

    QByteArray textMessage(QString sender, QString message, QString receiver);
    QByteArray isTypingMessage();
    QByteArray setNameMessage(QString name);
    QByteArray setStatusMessage(Status status);
    QByteArray setInitSendingFileMessage(QString fileName);
    QByteArray setAcceptFileMessage();
    QByteArray setRejectFileMessage();
    QByteArray setFileMessage(QString fileName);

    void loadData(QByteArray data);

    QString message() const;

    QString name() const;

    Status status() const;

    MessageType type() const;

    QString fileName() const;

    qint64 fileSize() const;

    QByteArray fileData() const;

    QString receiver() const;

    QString clientName() const;

    QString prevName() const;

    QStringList clientsName() const;

    QString myName() const;

    QString sender() const;

private:
    QByteArray getData(MessageType type, QString data);
    MessageType _type;
    QString _message;
    QString _name;
    Status _status;
    QString _fileName;
    qint64 _fileSize;
    QByteArray _fileData;
    QString _receiver;
    QString _clientName;
    QString _prevName;
    QStringList _clientsName;
    QString _myName;
    QString _sender;

};

#endif // CHATPROTOCOL_H
