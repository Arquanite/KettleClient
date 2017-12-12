#-------------------------------------------------
#
# Project created by QtCreator 2017-12-09T20:08:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KettleClient
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

isEmpty(PREFIX) {
    PREFIX = /usr/local
}

target.path = $$PREFIX/bin
INSTALLS += target

shortcutfiles.files = res/kettleclient.desktop
shortcutfiles.path = $$PREFIX/share/applications/
INSTALLS += shortcutfiles

iconfile.files = res/kettleclient.png
iconfile.path = $$PREFIX/share/icons/hicolor/256x256/apps/
INSTALLS += iconfile


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui
