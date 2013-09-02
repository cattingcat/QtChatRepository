#include "client.h"
#include "server.h"
#include <QStringList>


Client::Client(Server* server, QTcpSocket* socket):
    QObject(server),_server(server), _socket(socket), _login(0) {
    connect(_socket, SIGNAL(readyRead()), SLOT(processMessage()));

}

void Client::processMessage(){
    QByteArray arr = _socket->readAll();
    QTextStream ts(arr);
    QString message = ts.readAll();
    if(_login){
        //TODO process mesage command
        QString commands = message.left(message.indexOf(']'));
        commands = commands.right(commands.length()-1);

        QStringList l = commands.split(',');
        if(l.contains(QString("bcast"))){
            _server->sendBroadcast(message);
        } else {
            qDebug()<<commands;
        }

    } else {
        QString login = message.remove(0, 6);
        this->_login = new QString(login);
        QTextStream(_socket)<<"[succes]";
        emit authSuccess();
    }
}
void Client::sendMessage(const QString& message){
    QTextStream ts(_socket);
    ts<<message;
    ts.flush();
}
