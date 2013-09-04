#-------------------------------------------------
#
# Project created by QtCreator 2013-08-31T19:37:17
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatClient
TEMPLATE = app


SOURCES += main.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    client.h \
    authwindow.h

RESOURCES += \
    Resource.qrc

OTHER_FILES += \
    page.html \
    img/6.jpg \
    img/5.jpg \
    img/4.png \
    img/3.jpg \
    img/2.jpg \
    img/1.jpg
