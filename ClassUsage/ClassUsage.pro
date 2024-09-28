QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClassUsage
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        test.cpp

HEADERS += \
        mainwindow.h \
        test.h

FORMS += \
        mainwindow.ui
