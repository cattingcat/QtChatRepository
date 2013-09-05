#-------------------------------------------------
#
# Project created by QtCreator 2013-08-31T19:35:21
#
#-------------------------------------------------

QT += core gui
QT += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatServer
TEMPLATE = app


SOURCES += main.cpp \
    client.cpp \
    server.cpp \
    remoteserver.cpp \
    message.cpp

HEADERS  += mainwindow.h \
    server.h \
    client.h \
    remoteserver.h \
    message.h

RESOURCES += \
    resource.qrc
