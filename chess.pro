#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T19:24:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui_chess
TEMPLATE = app

INCLUDEPATH += chess/headers/
INCLUDEPATH += chess/
INCLUDEPATH += UI/headers/


SOURCES += main.cpp \
    UI/src/mainwindow.cpp \
    UI/src/myview.cpp \
    chess/src/test_game.cpp \
    chess/src/game.cpp \
    chess/src/field.cpp \
    chess/src/coordinates.cpp \
    chess/src/piece.cpp \
    chess/pieces/down_pawn.cpp \
    chess/src/player.cpp \
    chess/pieces/up_pawn.cpp \
    chess/pieces/knight.cpp \
    chess/pieces/bishop.cpp \
    chess/pieces/rook.cpp \
    chess/pieces/queen.cpp \
    chess/pieces/king.cpp

HEADERS  += UI/headers/mainwindow.h \
    UI/headers/myview.h \
    chess/headers/test_game.h \
    chess/headers/game.h \
    chess/headers/field.h \
    chess/headers/coordinates.h \
    chess/headers/piece.h \
    chess/pieces/down_pawn.h \
    chess/headers/player.h \
    chess/pieces/up_pawn.h \
    chess/pieces/knight.h \
    chess/pieces/bishop.h \
    chess/pieces/rook.h \
    chess/pieces/queen.h \
    chess/pieces/king.h \
    chess/headers/igame.h

FORMS    += UI/mainwindow.ui

RESOURCES += \
    images.qrc
