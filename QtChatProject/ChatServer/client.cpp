#include "client.h"
#include "server.h"

Client::Client(Server* server, QTcpSocket* socket):
    QObject(server),_server(server), _socket(socket), _login(0) {
    connect(_socket, SIGNAL(readyRead()), SLOT(processMessage()));

}

void Client::processMessage(){
    QByteArray arr = _socket->readAll();
    QTextStream ts(arr);
    QString message = ts.readAll();
    qDebug()<<"Client->processMessage: "<<message;
    if(_login){
        //TODO process mesage command
        _server->sendBroadcast(message);
    } else {
        QString login = message.remove(0, 6);
        this->_login = new QString(login);
        qDebug()<<"auth from: " << login;
        QTextStream(_socket)<<"succes auth";
        emit authSuccess();
    }
}
void Client::sendMessage(const QString& message){
    QTextStream ts(_socket);
    ts<<message;
    ts.flush();
}
