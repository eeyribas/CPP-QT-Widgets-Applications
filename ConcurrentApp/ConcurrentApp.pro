QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConcurrentApp
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        job.cpp

HEADERS += \
        mainwindow.h \
        job.h

FORMS += \
        mainwindow.ui
