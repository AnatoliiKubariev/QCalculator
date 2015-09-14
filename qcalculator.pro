#-------------------------------------------------
#
# Project created by QtCreator 2015-09-09T10:23:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \

HEADERS  += mainwindow.h \
    calculator.h

FORMS    += mainwindow.ui


CONFIG += c++11
