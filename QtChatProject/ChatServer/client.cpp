#include "client.h"
#include "server.h"

Client::Client(Server* server, QTcpSocket* socket):
    QObject(server), _socket(socket), _auth(false){
    connect(_socket, SIGNAL(readyRead()), SLOT(processMessage()));

}

void Client::processMessage(){
    QByteArray arr = _socket->readAll();
    QTextStream ts(arr);
    QString message = ts.readAll();
    qDebug()<<"Client->processMessage: "<<message;
    if(_auth){
        emit messageReceived(message);
    } else {
        //TODO auth
        qDebug()<<"auth message: "<<message;
        QTextStream(_socket)<<"succes auth";
        _auth = true;
        emit authSuccess();
    }
}
void Client::sendMessage(const QString& message){
    QTextStream ts(_socket);
    ts<<message;
    ts.flush();
}
