#-------------------------------------------------
#
# Project created by QtCreator 2017-12-09T20:08:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KettleClient
TEMPLATE = app

INCLUDEPATH += $$PWD/headers

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
        sources/main.cpp \
        sources/mainwindow.cpp \
    sources/aboutdialog.cpp \
    sources/logindialog.cpp \
    sources/providerdialog.cpp \
    sources/customerdialog.cpp \
    sources/employeedialog.cpp \
    sources/departmentdialog.cpp \
    sources/statedialog.cpp \
    sources/productdialog.cpp \
    sources/partdialog.cpp \
    sources/orderdialog.cpp \
    sources/waitingspinnerwidget.cpp \
    sources/waitingdialog.cpp \
    sources/randomjsonfactory.cpp \
    sources/randomaccesslist.cpp \
    sources/jsonmodel.cpp \
    sources/viewcontroller.cpp

HEADERS += \
        headers/mainwindow.h \
    headers/aboutdialog.h \
    headers/logindialog.h \
    headers/providerdialog.h \
    headers/customerdialog.h \
    headers/employeedialog.h \
    headers/departmentdialog.h \
    headers/statedialog.h \
    headers/productdialog.h \
    headers/partdialog.h \
    headers/orderdialog.h \
    headers/waitingspinnerwidget.h \
    headers/waitingdialog.h \
    headers/randomjsonfactory.h \
    headers/randomaccesslist.h \
    headers/jsonmodel.h \
    headers/viewcontroller.h

FORMS += \
        forms/mainwindow.ui \
    forms/aboutdialog.ui \
    forms/logindialog.ui \
    forms/providerdialog.ui \
    forms/customerdialog.ui \
    forms/employeedialog.ui \
    forms/departmentdialog.ui \
    forms/statedialog.ui \
    forms/productdialog.ui \
    forms/partdialog.ui \
    forms/orderdialog.ui \
    forms/waitingdialog.ui
