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
        mainwindow.cpp \
    aboutdialog.cpp \
    logindialog.cpp \
    providerdialog.cpp \
    customerdialog.cpp \
    employeedialog.cpp \
    departmentdialog.cpp \
    statedialog.cpp \
    productdialog.cpp \
    partdialog.cpp \
    orderdialog.cpp

HEADERS += \
        mainwindow.h \
    aboutdialog.h \
    logindialog.h \
    providerdialog.h \
    customerdialog.h \
    employeedialog.h \
    departmentdialog.h \
    statedialog.h \
    productdialog.h \
    partdialog.h \
    orderdialog.h

FORMS += \
        mainwindow.ui \
    aboutdialog.ui \
    logindialog.ui \
    providerdialog.ui \
    customerdialog.ui \
    employeedialog.ui \
    departmentdialog.ui \
    statedialog.ui \
    productdialog.ui \
    partdialog.ui \
    orderdialog.ui
