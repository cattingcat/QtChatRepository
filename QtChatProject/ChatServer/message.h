#ifndef MESSAGE_H
#define MESSAGE_H
#include <QObject>
#include <QStringList>
#include <QString>


class Message: public QObject
{
    Q_OBJECT
private:
    QStringList _comms;
    QString _message;
public:
    Message(QString message, QString commends);
    bool containsCommand(QString command);
    QStringList* getCommandParameters(QString command);
};

#endif // MESSAGE_H
