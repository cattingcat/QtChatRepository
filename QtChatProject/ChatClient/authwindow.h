#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QtDebug>
#include <QPushButton>

class AuthWindow: public QDialog{
    Q_OBJECT
private:
    QLineEdit* _host;
    QLineEdit* _port;
    QLineEdit* _login;

    QString _shost;
    QString _sport;
    QString _slogin;

public:
    AuthWindow(){
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* inputLayout = new QHBoxLayout;

        _host = new QLineEdit("localhost", this);
        _port = new QLineEdit("2323", this);
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

        inputLayout->addLayout(hostLayout);
        inputLayout->addLayout(portLayout);
        inputLayout->addLayout(loginLayout);

        mainLayout->addLayout(inputLayout);

        QPushButton* startButton = new QPushButton("start");
        connect(startButton, SIGNAL(clicked()), SLOT(slot()));
        mainLayout->addWidget(startButton);

        setLayout(mainLayout);
    }

public slots:
    int exec(){
        QDialog::exec();
        _shost = _host->text();
        _sport = _port->text();
        _slogin = _login->text();
        if(_shost.isEmpty() || _sport.isEmpty() || _slogin.isEmpty())
            return 0;
        else
            return 1;
    }

    QString host(){
        return _shost;
    }

    uint port(){
        return _sport.toInt();
    }

    QString login(){
        return _slogin;
    }
private slots:
    void slot(){
        this->close();
    }

};

#endif // AUTHWINDOW_H
