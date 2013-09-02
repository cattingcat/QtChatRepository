#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include "client.h"

class MainWindow : public QWidget
{
    Q_OBJECT    
private:
    QPushButton* _sendButton;
    QPushButton* _connectButton;
    QListWidget* _list;
    Client* _client;
    QLineEdit* _input;

public:
    MainWindow(QWidget *parent = 0): QWidget(parent) {
        _sendButton = new QPushButton("send", this);
        _connectButton = new QPushButton("connect", this);
        _list = new QListWidget(this);
        _list->addItem("qweqwe");
        _client = new Client("localhost", 2323);
        _input = new QLineEdit(this);
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(_list);
        layout->addWidget(_sendButton);
        layout->addWidget(_connectButton);
        layout->addWidget(_input);
        QObject::connect(_sendButton, SIGNAL(clicked()), this, SLOT(send()));
        QObject::connect(_connectButton, SIGNAL(clicked()), this, SLOT(connectClient()));

        setLayout(layout);
    }

    ~MainWindow(){}

public slots:
    void send(){
        _client->sendMessage("[message]"+_input->text());
        _input->clear();
    }
    void connectClient(){
        bool b = _client->auth("login");
        if(b){
            _connectButton->hide();
            connect(_client, SIGNAL(messageReceive(QString)), SLOT(recv(QString)));
        } else {
            qDebug()<<"auth error";
        }
    }
    void recv(const QString& message){
        qDebug()<<message;
        QListWidgetItem* item = new QListWidgetItem(_list);
        item->setText(message);
        _list->addItem(item);
        update();
    }
};

#endif // MAINWINDOW_H