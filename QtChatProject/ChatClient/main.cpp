#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QTcpSocket>
#include "authwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    //TODO
    AuthWindow w;
    w.show();
    
    return a.exec();
}
