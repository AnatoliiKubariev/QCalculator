#-------------------------------------------------
#
# Project created by QtCreator 2015-09-15T23:27:15
#
#-------------------------------------------------

QT += widgets testlib

SOURCES = qcalculator.test.cpp \
    calculator.cpp \
    token.cpp \
    token_stream.cpp

CONFIG += c++11

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target
