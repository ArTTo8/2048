#-------------------------------------------------
#
# Project created by QtCreator 2016-08-18T11:05:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp \
    grid.cpp

HEADERS  += mainwindow.h \
    cell.h \
    grid.h
