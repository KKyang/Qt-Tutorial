#-------------------------------------------------
#
# Project created by QtCreator 2014-08-23T11:29:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gray-histogram-resize
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog/dialogimageresize.cpp \
    dialog/dialoghistogram.cpp \
    dialog/dialogblur.cpp \
    dialog/dialogadjust64.cpp

HEADERS  += mainwindow.h \
    dialog/dialogimageresize.h \
    dialog/dialoghistogram.h \
    dialog/dialogblur.h \
    dialog/dialogadjust64.h

FORMS    += mainwindow.ui \
    dialog/dialogimageresize.ui \
    dialog/dialoghistogram.ui \
    dialog/dialogblur.ui \
    dialog/dialogadjust64.ui

INCLUDEPATH += D:/Database/NTU/MSVC/myCV/mycv_core\


contains(QMAKE_TARGET.arch, x86):{
    debug{
        LIBS += D:/Database/NTU/MSVC/myCV/Debug/mycv_core.lib\
    }

    release{
        LIBS += D:/Database/NTU/MSVC/myCV/Release/mycv_core.lib\
    }
}

contains(QMAKE_TARGET.arch, x86_64):{
    debug{
        LIBS += D:/Database/NTU/MSVC/myCV/x64/Debug/mycv_core.lib\
    }

    release{
        LIBS += D:/Database/NTU/MSVC/myCV/x64/Release/mycv_core.lib\
    }
}
