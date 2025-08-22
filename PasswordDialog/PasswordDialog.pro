QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PasswordDialog
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        dialog.cpp

HEADERS += \
        mainwindow.h \
        dialog.h

FORMS += \
        mainwindow.ui \
        dialog.ui
