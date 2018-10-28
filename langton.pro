#-------------------------------------------------
#
# Project created by QtCreator 2018-10-27T21:06:41
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = langton
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    langtonant.cpp \
    qpixmapdrawer.cpp \
    langtonant_worker.cpp \
    langtonanthexa.cpp

HEADERS += \
        mainwindow.h \
    langtonant.h \
    qpixmapdrawer.h \
    langtonant_worker.h \
    langtonanthexa.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
