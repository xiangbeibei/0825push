#-------------------------------------------------
#
# Project created by QtCreator 2019-04-19T12:21:24
#
#-------------------------------------------------
QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"

win32 {
    QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
    QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01

    DEFINES += _ATL_XP_TARGETING
    QMAKE_CFLAGS += /D _USING_V110_SDK71
    QMAKE_CXXFLAGS += /D _USING_V110_SDK71
    LIBS *= -L”%ProgramFiles(x86)%/Microsoft SDKs/Windows/7.1A/Lib”
    INCLUDEPATH += “%ProgramFiles(x86)%/Microsoft SDKs/Windows/7.1A/Include”
    #QMAKE_TARGET_OS = xp
}

UI_DIR = ../CardForm

QT       += core gui
QT       +=multimedia
QT       +=multimediawidgets
QT       +=sql
QT       +=axcontainer
QT       +=printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
LIBS += $$PWD/Libs/Opencv/lib/opencv_world310.lib
LIBS += $$PWD/Libs/THFace/lib/THFeature.lib
LIBS += $$PWD/Libs/THFace/lib/THFaceImage.lib
LIBS += $$PWD/Libs/CardReader/termb.lib
LIBS += $$PWD/Libs/zip/quazip/quazip.lib

INCLUDEPATH += Libs/Opencv/include
INCLUDEPATH += Libs/THFace/include
INCLUDEPATH += Libs/CardReader/include
INCLUDEPATH += Libs/zip/quazip
INCLUDEPATH += Libs/zip/zlib
TARGET = CardForm
TEMPLATE = app
RC_FILE += app.rc
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        Mainwindow.cpp \
    selectwidget.cpp \
    CardReader.cpp \
    ControlCamera.cpp \
    dSystemSetup.cpp \
    ConfigManager.cpp \
    dCameraSetting.cpp \
    dPicturePathSetting.cpp \
    AboutWindow.cpp \
    loadingwindow.cpp \
    Aiface.cpp \
    dmwidget.cpp \
    PrintManager.cpp \
    database.cpp \
    dreadsetting.cpp \
    ConfigManager.cpp \
    dSystemSetup.cpp

HEADERS  += Mainwindow.h \
    selectwidget.h \
    CardReader.h \
    ControlCamera.h \
    dSystemSetup.h \
    ConfigManager.h \
    dPicturePathSetting.h \
    AboutWindow.h \
    dCameraSetting.h \
    loadingwindow.h \
    Aiface.h \
    dmwidget.h \
    PrintManager.h \
    database.h \
    dreadsetting.h \
    ConfigManager.h \
    dSystemSetup.h

FORMS    += mainwindow.ui \
    selectwidget.ui \
    dPicturePathSetting.ui \
    dSystemSetup.ui \
    aboutwindow.ui \
    dCameraSetting.ui \
    loadingwindow.ui \
    dmwidget.ui \
    dreadsetting.ui \
    dSystemSetup.ui

RESOURCES += \
    image.qrc \
    music.qrc

DISTFILES += \
    CardForm.pro.user \
    logo.ico \
    app.rc
