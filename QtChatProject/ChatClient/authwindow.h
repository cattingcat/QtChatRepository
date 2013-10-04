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
    QLineEdit* _login;
    QString _slogin;

public:
    AuthWindow(){
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* inputLayout = new QHBoxLayout;

        _login = new QLineEdit(this);
        QLabel* llogin = new QLabel("&Login", this);
        llogin->setBuddy(_login);

        QVBoxLayout* loginLayout = new QVBoxLayout;
        loginLayout->addWidget(llogin);
        loginLayout->addWidget(_login);

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
        _slogin = _login->text();
        if(_slogin.isEmpty())
            return 0;
        else
            return 1;
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
