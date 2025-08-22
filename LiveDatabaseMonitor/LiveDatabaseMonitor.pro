QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    thread.cpp

HEADERS += \
    mainwindow.h \
    thread.h

FORMS += \
    mainwindow.ui
