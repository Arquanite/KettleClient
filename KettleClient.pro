#-------------------------------------------------
#
# Project created by QtCreator 2017-12-09T20:08:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KettleClient
TEMPLATE = app

INCLUDEPATH += $$PWD/dialogs \
               $$PWD/utils \
               $$PWD/patterns \
               $$PWD/entities \
               $$PWD/patterns/state

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
        utils/main.cpp \
        dialogs/mainwindow.cpp \
    dialogs/aboutdialog.cpp \
    dialogs/logindialog.cpp \
    dialogs/providerdialog.cpp \
    dialogs/customerdialog.cpp \
    dialogs/employeedialog.cpp \
    dialogs/departmentdialog.cpp \
    dialogs/statedialog.cpp \
    dialogs/productdialog.cpp \
    dialogs/partdialog.cpp \
    dialogs/orderdialog.cpp \
    utils/waitingspinnerwidget.cpp \
    dialogs/waitingdialog.cpp \
    utils/randomjsonfactory.cpp \
    utils/randomaccesslist.cpp \
    patterns/jsonmodel.cpp \
    patterns/viewcontroller.cpp \
    patterns/credentials.cpp \
    patterns/filteringmodel.cpp \
    patterns/sortingstrategy.cpp \
    patterns/ascendingstrategy.cpp \
    patterns/descendingstrategy.cpp \
    entities/provider.cpp \
    entities/customer.cpp \
    entities/employee.cpp \
    entities/department.cpp \
    entities/part.cpp \
    entities/product.cpp \
    entities/state.cpp \
    entities/order.cpp \
    patterns/jsonable.cpp \
    utils/networkservice.cpp \
    utils/typeconverter.cpp \
    patterns/state/abstractstate.cpp \
    patterns/state/customerstate.cpp \
    patterns/state/departmentstate.cpp \
    patterns/state/employeestate.cpp \
    patterns/state/orderstate.cpp \
    patterns/state/partstate.cpp \
    patterns/state/productstate.cpp \
    patterns/state/providerstate.cpp \
    patterns/state/statestate.cpp \
    utils/stringvalidator.cpp

HEADERS += \
        dialogs/mainwindow.h \
    dialogs/aboutdialog.h \
    dialogs/logindialog.h \
    dialogs/providerdialog.h \
    dialogs/customerdialog.h \
    dialogs/employeedialog.h \
    dialogs/departmentdialog.h \
    dialogs/statedialog.h \
    dialogs/productdialog.h \
    dialogs/partdialog.h \
    dialogs/orderdialog.h \
    utils/waitingspinnerwidget.h \
    dialogs/waitingdialog.h \
    utils/randomjsonfactory.h \
    utils/randomaccesslist.h \
    patterns/jsonmodel.h \
    patterns/viewcontroller.h \
    patterns/credentials.h \
    patterns/filteringmodel.h \
    patterns/sortingstrategy.h \
    patterns/ascendingstrategy.h \
    patterns/descendingstrategy.h \
    entities/provider.h \
    entities/customer.h \
    entities/employee.h \
    entities/department.h \
    entities/part.h \
    entities/product.h \
    entities/state.h \
    entities/order.h \
    patterns/jsonable.h \
    utils/typeconverter.h \
    utils/networkservice.h \
    utils/entities.h \
    utils/states.h \
    patterns/state/abstractstate.h \
    patterns/state/customerstate.h \
    patterns/state/departmentstate.h \
    patterns/state/employeestate.h \
    patterns/state/orderstate.h \
    patterns/state/partstate.h \
    patterns/state/productstate.h \
    patterns/state/providerstate.h \
    patterns/state/statestate.h \
    utils/stringvalidator.h

FORMS += \
        dialogs/mainwindow.ui \
    dialogs/aboutdialog.ui \
    dialogs/logindialog.ui \
    dialogs/providerdialog.ui \
    dialogs/customerdialog.ui \
    dialogs/employeedialog.ui \
    dialogs/departmentdialog.ui \
    dialogs/statedialog.ui \
    dialogs/productdialog.ui \
    dialogs/partdialog.ui \
    dialogs/orderdialog.ui \
    dialogs/waitingdialog.ui
