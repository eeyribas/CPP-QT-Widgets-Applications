QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicsMouseTracker
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        qgraphicsmouseevent.cpp

HEADERS += \
        mainwindow.h \
        qgraphicsmouseevent.h

FORMS += \
        mainwindow.ui
