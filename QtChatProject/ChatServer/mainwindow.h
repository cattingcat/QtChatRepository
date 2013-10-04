#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtWidgets>
#include "server.h"
#include <QSystemTrayIcon>

class ChatWidget : public QMainWindow
{
    Q_OBJECT
    Server* _server;
    QSystemTrayIcon* _trayIcon;

public:
    ChatWidget(Server* server, QWidget *parent = 0) : QMainWindow(parent) {
        _server = server;
        _trayIcon = new QSystemTrayIcon(QIcon(":/res/icon.png"), this);
        QMenu* menu = new QMenu;
        menu->addAction("Show...", this, SLOT(show()));
        menu->addAction("Hide", this, SLOT(hide()));
        _trayIcon->setContextMenu(menu);
        _trayIcon->show();

        QDockWidget* dw = new QDockWidget("dock", this);
        dw->setWidget(new QLabel("hello dock"));
        addDockWidget(Qt::RightDockWidgetArea, dw);
    }

    ~ChatWidget(){}
};

#endif // MAINWINDOW_H
