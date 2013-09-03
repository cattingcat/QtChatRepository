#ifndef REMOTESERVER_H
#define REMOTESERVER_H
#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtDebug>
#include "client.h"
#include <QList>

class RemoteServer: public QObject
{
    Q_OBJECT
private:
    QTcpSocket* _socket;
public:
    RemoteServer(QTcpSocket* socket, QObject* parent = 0):
        _socket(socket), QObject(parent){

    }
};

#endif // REMOTESERVER_H
