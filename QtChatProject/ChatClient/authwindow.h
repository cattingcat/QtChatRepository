#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

class AuthWindow: public QWidget{
    Q_OBJECT
private:
    QLineEdit* _host;
    QLineEdit* _port;
    QLineEdit* _login;

public:
    AuthWindow(){
        QHBoxLayout* layout = new QHBoxLayout;

        _host = new QLineEdit(this);
        _port = new QLineEdit(this);
        _login = new QLineEdit(this);
        QLabel* lhost = new QLabel("&Host", this);
        lhost->setBuddy(_host);
        QLabel* lport = new QLabel("&Port", this);
        lport->setBuddy(_port);
        QLabel* llogin = new QLabel("&Login", this);
        llogin->setBuddy(_login);

        QVBoxLayout* hostLayout = new QVBoxLayout;
        hostLayout->addWidget(lhost);
        hostLayout->addWidget(_host);
        QVBoxLayout* portLayout = new QVBoxLayout;
        portLayout->addWidget(lport);
        portLayout->addWidget(_port);
        QVBoxLayout* loginLayout = new QVBoxLayout;
        loginLayout->addWidget(llogin);
        loginLayout->addWidget(_login);

        layout->addLayout(hostLayout);
        layout->addLayout(portLayout);
        layout->addLayout(loginLayout);

        setLayout(layout);
    }

};

#endif // AUTHWINDOW_H
