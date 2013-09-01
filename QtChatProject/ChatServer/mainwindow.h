#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtWidgets>
#include <QtNetwork/QTcpServer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    
public:
    MainWindow(QWidget *parent = 0) : QMainWindow(parent) {
    }

    ~MainWindow(){}
};

#endif // MAINWINDOW_H
