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

SOURCES += about/*.cpp \
	customer/*.cpp \
	database/*.cpp \
	login/*.cpp \
	main/*.cpp \
	scheduler/*.cpp \
	staff/*.cpp \
	main.cpp

HEADERS  += about/*.h \
	customer/*.h \
	database/*.h \
	login/*.h \
	main/*.cpp \
	scheduler/*.h \
	staff/*.h

FORMS    += about/*.ui \
	customer/*.ui \
	database/*.ui \
	login/*.ui \
	main/*.ui \
	scheduler/*.ui \
	staff/*.ui

RESOURCES += resources.qrc
