QT += core gui

greatherThan(QT_MAJOR_VERSION,4):QT += widgets

# komentarz

TARGET = test
TEMPLATE = app

SOURCES +=main.cpp\
mainwindom.cpp

HEADERS += mainwindow.h

FORMS += mainwindow.ui
