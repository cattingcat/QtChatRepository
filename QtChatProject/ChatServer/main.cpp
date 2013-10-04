#include "mainwindow.h"
#include <QApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Server* s = new Server(2323);
    ChatWidget w(s);
    s->run();


    return a.exec();
}
