#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QThread>
#include <QString>

class Server;

class Client: public QObject{
    Q_OBJECT
private:
    QTcpSocket* _socket;
    QString* _login;
    Server* _server;

public:
    Client(Server* server, QTcpSocket* socket);
    void auth();

private slots:
    void processMessage();

public slots:
    void sendMessage(const QString& message);

signals:
    void authSuccess();
    void messageReceived(const QString& message);


};

#endif // CLIENT_H
