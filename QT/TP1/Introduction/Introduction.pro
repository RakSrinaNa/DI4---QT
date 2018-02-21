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
        mainwindow.cpp \
    login.cpp \
    newpatientdialog.cpp \
    patient.cpp \
    aproposdialog.cpp \
    newstaffdialog.cpp \
    staff.cpp \
    staffitem.cpp \
    c_init_bd.cpp \
    dbconnect.cpp

HEADERS  += mainwindow.h \
    login.h \
    newpatientdialog.h \
    patient.h \
    aproposdialog.h \
    newstaffdialog.h \
    staff.h \
    staffitem.h \
    c_init_bd.h \
    dbconnect.h

FORMS    += mainwindow.ui \
    login.ui \
    newpatientdialog.ui \
    aproposdialog.ui \
    newstaffdialog.ui

RESOURCES += \
    resources.qrc
