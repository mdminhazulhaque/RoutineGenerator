QT       += core gui widgets
CONFIG += c++11
TARGET = RoutineGenerator
TEMPLATE = app
SOURCES += main.cpp\
        mainwindow.cpp \
    routine.cpp \
    routineitem.cpp
HEADERS  += mainwindow.h \
    routine.h \
    routineitem.h
FORMS    += mainwindow.ui
