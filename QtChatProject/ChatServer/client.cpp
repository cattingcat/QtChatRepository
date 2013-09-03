#include "client.h"
#include "server.h"
#include "message.h"
#include <QStringList>

#define CMD(commad_name) m.containsCommand(QString((commad_name)))

Client::Client(Server* server, QTcpSocket* socket):
    QObject(server),_server(server), _socket(socket), _login(0) {
    connect(_socket, SIGNAL(readyRead()), SLOT(processMessage()));

}

void Client::processMessage(){
    QByteArray arr = _socket->readAll();
    Message m(arr);
    if(_login){
        if(CMD("bcast")){
            _server->sendBroadcast(QString().append(this->_login).append(QString("> ")).append(m.message()));
        } else if(CMD("private")) {
            // TODO moar command
            _server->sendBroadcast("private command called");
        } else {
            //qDebug()<<commands;
        }
    } else {
        if(CMD("auth")){
            this->_login = new QString(m.message());
            QTextStream(_socket)<<"[succes]";
            emit authSuccess();
        } else {
            // TODO disconnect
        }
    }
}
void Client::sendMessage(const QString& message){
    QTextStream ts(_socket);
    ts<<message;
    ts.flush();
}
