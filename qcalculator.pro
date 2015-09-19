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
    token.cpp \
    token_stream.cpp \
    calculator.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    token.h \
    token_stream.h

FORMS    += mainwindow.ui


CONFIG += c++11
