QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MouseDrivenVisualizer
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        mousemovefunction.cpp

HEADERS += \
        mainwindow.h \
        mousemovefunction.h

FORMS += \
        mainwindow.ui
