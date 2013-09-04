#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QTcpSocket>
#include "authwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    //TODO
    AuthWindow aw;
    bool b = aw.exec();
    MainWindow* w;

    if(b){
        w = new MainWindow(aw.host(), aw.port(), aw.login());
        w->show();
    }
    
    return a.exec();
}
