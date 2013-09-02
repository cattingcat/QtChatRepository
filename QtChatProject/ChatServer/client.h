#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QThread>
#include <QString>

class AuthThread;
class Server;

class Client: public QObject{
    Q_OBJECT
private:
    QTcpSocket* _socket;
    QString* _login;

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


    friend class AuthThread;
};

#endif // CLIENT_H
