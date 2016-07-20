#-------------------------------------------------
#
# Project created by QtCreator 2016-07-20T05:35:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Exercicio_Ordenacao
TEMPLATE = app


SOURCES += main.cpp\
        telaprincipal.cpp \
    bubblesort.cpp \
    insertionsort.cpp \
    mergesort.cpp \
    countingsort.cpp

HEADERS  += telaprincipal.h \
    bubblesort.h \
    insertionsort.h \
    mergesort.h \
    countingsort.h

FORMS    += telaprincipal.ui
