#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T16:54:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = PPM
TEMPLATE = app

LIBS    += -ljack

#-------------------------------------------------
# Root folder
#-------------------------------------------------
SOURCES         += main.cpp

OTHER_FILES     += README.md

#-------------------------------------------------
# Module: Gui
#-------------------------------------------------
SOURCES +=  gui/twndmain.cpp \
            gui/tdlgtoolsjackd.cpp

HEADERS  += gui/twndmain.h \
            gui/tdlgtoolsjackd.h \

FORMS    += gui/twndmain.ui \
            gui/tdlgtoolsjackd.ui

#-------------------------------------------------
# Module: JackD
#-------------------------------------------------
SOURCES +=  jackd/tjackdadapter.cpp

HEADERS  += jackd/tjackdadapter.h
