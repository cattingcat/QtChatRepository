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
#include <QtNetwork/QTcpSocket>


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

        getHost();
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

    void getHost(){
        QTcpSocket sock;
        sock.connectToHost("dl.dropboxusercontent.com", 80);
        sock.write("GET /s/1o5g6k76mlhw3l7/text.txt?token_hash=AAEXKVnLJmFsl9-dp8KNog6vWaBcae2zIu_ockhkJRbi_g&amp;amp;amp;dl=1 HTTP/1.1\r\n"\
                   "Host: dl.dropboxusercontent.com\r\n"\
                   "Accept: */*\r\n"\
                   "User-Agent: Mozilla/4.0 (compatible; MSIE 5.0; Windows 98)\r\n"\
                   "\r\n\r\n");
        qDebug() << "GET";
        sock.waitForReadyRead();
        QByteArray arr = sock.read(1024);
        qDebug() << arr;
        // TODO
    }

};

#endif // AUTHWINDOW_H
