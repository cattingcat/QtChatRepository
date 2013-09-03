#include "message.h"
#include <QString>
#include <QStringList>
#include <QTextStream>

Message::Message(QString message, QString commands):
    QObject(), _message(message) {
    _comms = commands.split(", ");
}

Message::Message(QByteArray ba):
    QObject(){
    QTextStream ts(ba);
    QString message = ts.readAll();
    int iof = message.indexOf(']');
    QString commands = message.left(iof);
    commands = commands.right(commands.length() - 1);
    message = message.right(message.length() - iof - 1);
    _message = message;
    _comms = commands.split(", ");
}

bool Message::containsCommand(QString command) const {
    foreach(QString c, _comms){
        if(c.contains(command)){
            return true;
        }
    }
    return false;
}

QStringList* Message::getCommandParameters(QString command) const {
    foreach(QString c, _comms){
        if(c.contains(command)){
            QStringList l = c.split(' ');
            l.removeAt(0);
            return new QStringList(l);
        }
    }
    return 0;
}

QString Message::message() const {
    return _message;
}
