#-------------------------------------------------
#
# Project created by QtCreator 2018-02-13T10:40:23
#
#-------------------------------------------------

QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Introduction
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    newpatientdialog.cpp \
    patient.cpp \
    newstaffdialog.cpp \
    staff.cpp \
    staffitem.cpp \
    c_init_bd.cpp \
    ressourcetype.cpp \
    ressourceitem.cpp \
    schedule.cpp \
    timeline.cpp \
    AboutDialog.cpp \
    DBConnect.cpp \
    Login.cpp \
    MainWindow.cpp \
    MyDateItemDelegate.cpp \
    MySqlTableModel.cpp

HEADERS  += \
    newpatientdialog.h \
    patient.h \
    newstaffdialog.h \
    staff.h \
    staffitem.h \
    c_init_bd.h \
    ressourcetype.h \
    ressourceitem.h \
    schedule.h \
    timeline.h \
    AboutDialog.h \
    DBConnect.h \
    Login.h \
    MainWindow.h \
    MyDateItemDelegate.h \
    MySqlTableModel.h

FORMS    += \
    newpatientdialog.ui \
    newstaffdialog.ui \
    AboutDialog.ui \
    Login.ui \
    MainWindow.ui

RESOURCES += \
    resources.qrc
