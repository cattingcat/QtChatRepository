#include "server.h"


Server::Server(uint port): _port(port) {
    _server = new QTcpServer(this);
    _clients = new QList<Client*>;
    connect(_server, SIGNAL(newConnection()), SLOT(processConnection()));
}

void Server::run(){
    _server->listen(QHostAddress::Any, _port);
}

void Server::processConnection(){
    QTcpSocket* clientSock = _server->nextPendingConnection();
    Client* client  = new Client(this, clientSock);
    this->connect(client, SIGNAL(authSuccess()), SLOT(clientAuthenticated()));

}

void Server::clientAuthenticated(){
    Client* c = dynamic_cast<Client*>(sender());
    _clients->append(c);
}

void Server::sendBroadcast(const QString& message){
    for(QList<Client*>::Iterator iter = _clients->begin(); iter != _clients->end(); ++iter){
        (*iter)->sendMessage(message);
    }
}

void Server::clientDisconnected(){
    Client* c = dynamic_cast<Client*>(sender());
    _clients->removeOne(c);
}


