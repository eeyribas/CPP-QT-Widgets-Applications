QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPortSendReceive
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        serialport.cpp

HEADERS += \
        mainwindow.h \
        serialport.h

FORMS += \
        mainwindow.ui
