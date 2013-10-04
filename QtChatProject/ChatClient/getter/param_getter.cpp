#include "param_getter.h"
#include <QtNetwork/QTcpSocket>
#include <QStringList>
#include <QMap>

QMap<QString, QString> Getter::get_params(){
    QString host("/s/1o5g6k76mlhw3l7/text.txt?token_hash=AAEXKVnLJmFsl9-dp8KNog6vWaBcae2zIu_ockhkJRbi_g&amp;amp;amp;dl=1");
    QString get("GET " + host + " HTTP/1.1\r\n"\
                "Host: dl.dropboxusercontent.com\r\n"\
                "Accept: */*\r\n"\               
                "\r\n\r\n");

    QTcpSocket sock;
    sock.connectToHost("dl.dropboxusercontent.com", 80);

    sock.write(get.toLatin1());
    sock.waitForReadyRead();

    QByteArray arr = sock.read(2048);
    if(!arr.isNull() && !arr.isEmpty()){
        sock.close();
        arr = arr.remove(0, arr.indexOf("\r\n\r\n") + 2);
        QString data(arr);
        QStringList list = data.split("\r\n");
        list.removeAll("");
        QMap<QString, QString> map;
        for(QStringList::Iterator iter = list.begin(); iter != list.end(); ++iter){
            QStringList pair = (*iter).split(": ");
            map[pair[0].simplified()] = pair[1];
        }
        return map;
    } else {
        return QMap<QString, QString>();
    }
}
