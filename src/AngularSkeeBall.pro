#-------------------------------------------------
#
# Project created by QtCreator 2018-07-15T11:29:20
#
#-------------------------------------------------

QT       += core gui widgets svg multimedia xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AngularSeekBall
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


SOURCES += \
    GameMenuView.cpp \
    main.cpp \
    Game.cpp \
    MainWindow.cpp \
    LevelsMenu.cpp \
    Hole.cpp \
    LevelStart.cpp \
    Score.cpp \
    AnimateObject.cpp \
    Level.cpp \
    BigHole.cpp \
    MediumHole.cpp \
    SmallHole.cpp

HEADERS += \
    GameMenuView.h \
    Game.h \
    MainWindow.h \
    LevelsMenu.h \
    Hole.h \
    LevelStart.h \
    Score.h \
    AnimateObject.h \
    Level.h \
    BigHole.h \
    MediumHole.h \
    SmallHole.h

FORMS += \
    GameMenuView.ui \
    LevelsMenu.ui \
    Level.ui \
    LevelStart.ui \
    Level.ui

RESOURCES += \
    ../assets/assets.qrc

DISTFILES +=
