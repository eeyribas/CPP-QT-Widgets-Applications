QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QThreadWithToolboxsInvoke
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        thread1.cpp \
        thread2.cpp

HEADERS += \
        mainwindow.h \
        thread1.h \
        thread2.h

FORMS += \
        mainwindow.ui
