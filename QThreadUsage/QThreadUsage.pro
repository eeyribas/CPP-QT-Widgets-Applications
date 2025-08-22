QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QThreadUsage
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        mythread.cpp

HEADERS += \
        mainwindow.h \
        mythread.h

FORMS += \
        mainwindow.ui
