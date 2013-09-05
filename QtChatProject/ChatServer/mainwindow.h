#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtWidgets>
#include "server.h"
#include <QSystemTrayIcon>

class MainWindow : public QWidget
{
    Q_OBJECT
    Server* _server;
    QSystemTrayIcon* _trayIcon;

public:
    MainWindow(Server* server, QWidget *parent = 0) : QWidget(parent) {
        _server = server;
        _trayIcon = new QSystemTrayIcon(QIcon(":/res/icon.png"), this);
        QMenu* menu = new QMenu;
        menu->addAction("Show...", this, SLOT(show()));
        menu->addAction("Hide", this, SLOT(hide()));
        _trayIcon->setContextMenu(menu);
        _trayIcon->show();
    }

    ~MainWindow(){}
};

#endif // MAINWINDOW_H
