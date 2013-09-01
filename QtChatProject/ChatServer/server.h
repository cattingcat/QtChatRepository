#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtDebug>
#include "client.h"
#include <QList>

class Server: public QObject{
    Q_OBJECT
private:
    QTcpServer* _server;
    uint _port;
    QList<Client*>* _clients;

public:
    Server(uint port);
    void run();

private slots:
    void processConnection();
    void clientAuthenticated();
    void sendBroadcast(const QString& message);
};

#endif // SERVER_H
