QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ODBCDatabaseControl
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        thread.cpp

HEADERS += \
        mainwindow.h \
        thread.h

FORMS += \
        mainwindow.ui
