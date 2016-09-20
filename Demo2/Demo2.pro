#-------------------------------------------------
#
# Project created by QtCreator 2016-09-17T02:14:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo2
TEMPLATE = app
DESTDIR = ../bin
UI_DIR = .

CONFIG(release, debug|release) {
        TARGET = smark-demo
        OBJECTS_DIR = ../build/smark-demo/release
        MOC_DIR = ../build/smark-demo/release
}

SOURCES += main.cpp\
        mainwindow.cpp \
    openbrmanager.cpp \
    imageloader.cpp

HEADERS  += mainwindow.h \
    openbrmanager.h \
    imageloader.h

LIBS += /usr/local/lib/libopenbr.so
LIBS += /usr/local/lib/libopencv_core.so.2.4

FORMS    += mainwindow.ui
