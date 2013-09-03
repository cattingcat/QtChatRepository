#include "message.h"
#include <QString>
#include <QStringList>

Message::Message(QString message, QString commands):
    QObject(), _message(message) {
    _comms = commands.split(", ");

}

bool Message::containsCommand(QString command){
    foreach(QString c, _comms){
        if(c.contains(command))
            return true;
    }
    return false;
}

QStringList* Message::getCommandParameters(QString command){
    foreach(QString c, _comms){
        if(c.contains(command)){
            QStringList l = c.split(' ');
            l.removeAt(0);
            return new QStringList(l);
        }
    }
    return 0;
}
