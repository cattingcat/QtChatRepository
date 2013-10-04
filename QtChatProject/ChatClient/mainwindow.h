#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "client.h"
#include <QTextStream>
#include <QDir>
#include <QtWidgets>
#include <QDateTime>


class ChatWidget : public QWidget
{
    Q_OBJECT    
private:
    QPushButton* _sendButton;
    QPushButton* _smileButton;

    QTextEdit* _chat;
    Client* _client;
    QLineEdit* _input;
    QString _login;

    QVBoxLayout* _messageListLayout;

public:
    ChatWidget(QString host, uint port, QString login, QWidget *parent = 0):
        QWidget(parent), _login(login) {
        _sendButton = new QPushButton("send", this);
        _smileButton = new QPushButton("smile", this);
        _client = new Client(host, port);
        _input = new QLineEdit(this);
        _chat = new QTextEdit(this);
        _chat->setReadOnly(true);

        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(_chat);

        QHBoxLayout* inputLayout = new QHBoxLayout;
        inputLayout->addWidget(_input);
        inputLayout->addWidget(_smileButton);
        inputLayout->addWidget(_sendButton);
        layout->addLayout(inputLayout);

        QObject::connect(_input, SIGNAL(returnPressed()), _sendButton, SIGNAL(clicked()));
        QObject::connect(_sendButton, SIGNAL(clicked()), this, SLOT(send()));

        QMenu* m = createSmileMenu();
        _smileButton->setMenu(m);

        setLayout(layout);
    }

    ~ChatWidget(){}

private:
    QMenu* createSmileMenu(){
        QDir dir(":/resource/img");
        QStringList files = dir.entryList();
        QMenu* res = new QMenu(this);
        foreach(QString s, files){
            QString filepath = dir.path() + QString("/") + s;
            QIcon icon(filepath);
            QAction* action = res->addAction(icon, s, this, SLOT(appendInput()));
            action->setData(filepath);
        }
        return res;
    }

public slots:    
    void send(){
        _client->sendMessage(_input->text());
        _input->clear();
    }

    void messageRecv(const QString& message){
        _chat->append(QDateTime::currentDateTime().time().toString() + QString(" ") + message);
        update();
    }

    void connectClient(){
        bool b = _client->auth(_login);
        if(b){
            connect(_client, SIGNAL(messageRecv(QString)), SLOT(messageRecv(QString)));
        } else {
            qDebug()<<"auth error";
        }
    }

private slots:
    void appendInput(){
        QAction* a = dynamic_cast<QAction*>(sender());
        QFile htmlFile(":resource/page.html");
        htmlFile.open(QIODevice::ReadOnly);
        QTextStream ts(&htmlFile);
        QString s = ts.readAll();
        qDebug() << s;
        QString filename = a->data().value<QString>();
        s = s.replace("@img@", filename);
        QString res;
        QTextStream ts2(&res);
        ts2<<_input->text()<<s;
        _input->setText(res);
    }
};

#endif // MAINWINDOW_H
