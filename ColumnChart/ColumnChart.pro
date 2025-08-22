QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ColumnChart
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        qcustomplot.cpp

HEADERS += \
        mainwindow.h \
        qcustomplot.h

FORMS += \
        mainwindow.ui
