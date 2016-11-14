QT += core
QT -= gui
QT += serialport

CONFIG += c++11

TARGET = Andro2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
TEMPLATE= vcapp

SOURCES += \
    main.cpp \
    someclass.cpp \
    elm.cpp \
    serialdevice.cpp

HEADERS += \
    someclass.h \
    elm.h \
    serialdevice.h
