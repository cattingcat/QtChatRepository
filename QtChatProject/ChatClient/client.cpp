#include "client.h"

Client::Client(QString host, uint port, QObject* parent): QObject(parent){
    _socket = new QTcpSocket;
    _socket->connectToHost(host, port);
}

bool Client::auth(const QString& login){
    QTextStream ss(_socket);
    ss<<"[auth]"<<login;
    ss.flush();
    bool b = _socket->waitForReadyRead();
    if(b){
        QString answer = ss.readAll();

        qDebug()<<"server say: " << answer;
        _login = login;
        connect(_socket, SIGNAL(readyRead()), SLOT(dataRead()));
    } else {
        qDebug()<<"auth problem";
    }
    return b;
}

void Client::dataRead(){
    QTextStream ss(_socket);
    QString message =  ss.readAll();
    emit messageRecv(message);
}


void Client::sendMessage(const QString& message){
    QTextStream ss(_socket);
    // TODO delete [bcast]
    ss<<"[bcast]"<<message;
    ss.flush();
}
