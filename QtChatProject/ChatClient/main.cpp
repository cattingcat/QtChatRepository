#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QTcpSocket>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QTcpSocket* sock = new QTcpSocket;
    sock->connectToHost("localhost", 2323);

    sock->write(QString("[auth] hello").toUtf8());
    sock->waitForReadyRead();


    sock->write(QString("[message] hello").toUtf8());
    sock->flush();
    sock->write(QString("[message] hello").toUtf8());
    sock->flush();
    */

    MainWindow w;
    w.show();
    
    return a.exec();
}
