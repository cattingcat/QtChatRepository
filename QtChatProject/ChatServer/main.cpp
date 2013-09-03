#include "mainwindow.h"
#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server* s = new Server(2323);
    s->run();

   // MainWindow w;
    //w.show();
    
    return a.exec();
}
