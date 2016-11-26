#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T19:24:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui_chess
TEMPLATE = app

INCLUDEPATH += headers/


SOURCES += sources/main.cpp \
    sources/mainwindow.cpp \
    sources/myview.cpp \
    sources/test_game.cpp \
    sources/game.cpp \
    sources/field.cpp \
    sources/coordinates.cpp \
    sources/cell.cpp \
    sources/piece.cpp \
    pieces/down_pawn.cpp \
    sources/player.cpp \
    pieces/up_pawn.cpp \
    pieces/knight.cpp \
    pieces/bishop.cpp \
    pieces/rook.cpp \
    pieces/queen.cpp \
    pieces/king.cpp

HEADERS  += headers/mainwindow.h \
    headers/myview.h \
    headers/test_game.h \
    headers/game.h \
    headers/field.h \
    headers/coordinates.h \
    headers/cell.h \
    headers/piece.h \
    pieces/down_pawn.h \
    headers/player.h \
    pieces/up_pawn.h \
    pieces/knight.h \
    pieces/bishop.h \
    pieces/rook.h \
    pieces/queen.h \
    pieces/king.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
