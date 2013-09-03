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
    Message(QByteArray message);
    bool containsCommand(QString command) const;
    QStringList* getCommandParameters(QString command) const;
    QString message() const;
};

#endif // MESSAGE_H
