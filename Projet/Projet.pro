#-------------------------------------------------
#
# Project created by QtCreator 2018-02-13T10:40:23
#
#-------------------------------------------------

QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoMuchWoWApp
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    c_init_bd.cpp \
    AboutDialog.cpp \
    DBConnect.cpp \
    Login.cpp \
    MainWindow.cpp \
    MyDateItemDelegate.cpp \
    MySqlTableModel.cpp \
    NewCustomerDialog.cpp \
    NewStaffDialog.cpp \
    Customer.cpp \
    Schedule.cpp \
    Staff.cpp \
    StaffItem.cpp \
    Timeline.cpp \
    TreeItem.cpp \
    ResourceType.cpp \
    TreeModel.cpp \
    MyDateSortFilterProxyModel.cpp

HEADERS  += \
    c_init_bd.h \
    AboutDialog.h \
    DBConnect.h \
    Login.h \
    MainWindow.h \
    MyDateItemDelegate.h \
    MySqlTableModel.h \
    NewCustomerDialog.h \
    NewStaffDialog.h \
    Customer.h \
    Schedule.h \
    Staff.h \
    StaffItem.h \
    Timeline.h \
    TreeItem.h \
    ResourceType.h \
    TreeModel.h \
    MyDateSortFilterProxyModel.h

FORMS    += \
    AboutDialog.ui \
    Login.ui \
    MainWindow.ui \
    NewCustomerDialog.ui \
    NewStaffDialog.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    app.rc \
    app.ico \
    app.icns

RC_FILE = app.rc
ICON = app.icns
