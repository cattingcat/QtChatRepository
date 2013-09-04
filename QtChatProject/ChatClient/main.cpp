#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QTcpSocket>
#include "authwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AuthWindow aw;
    bool b = aw.exec();

    if(b){
        MainWindow* w = new MainWindow(aw.host(), aw.port(), aw.login());
        w->connectClient();
        w->show();
    } else {
        a.closeAllWindows();
        a.exit();
        return 0;
    }
    aw.close();
    return a.exec();
}
