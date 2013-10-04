#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QTcpSocket>
#include "authwindow.h"
#include "getter/param_getter.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AuthWindow aw;
    bool b = aw.exec();

    if(b){
        QString host = Getter::get_params()["chat_host"];
        ChatWidget* w = new ChatWidget(host, 2323, aw.login());
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
