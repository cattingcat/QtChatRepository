#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QFile>
#include <QIODevice>
#include <QtDebug>

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QTextEdit* _edit;
    QLabel* _label;
    
public:
    MainWindow(QWidget *parent = 0): QWidget(parent){
        QVBoxLayout* layout = new QVBoxLayout;
        _edit = new QTextEdit;
        _label = new QLabel;


        QFile f(":/resource/page.html");
        f.open(QIODevice::ReadOnly);
        QString htmlCode = QTextStream(&f).readAll();
        f.close();


        QString s;
        QTextStream ts(&s);
        ts<<"Hello "<<htmlCode <<" foxxy!";
        _edit->append(s);
        //_edit->append("Hello ");
        //_edit->append(htmlCode);
        //_edit->append(" foxy!");


        layout->addWidget(_edit);
        layout->addWidget(_label);
        setLayout(layout);
    }

};

#endif // MAINWINDOW_H
