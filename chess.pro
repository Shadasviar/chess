TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += headers/

SOURCES += sources/main.cpp \
    sources/test_game.cpp \
    sources/game.cpp \
    sources/field.cpp \
    sources/coordinates.cpp \
    sources/cell.cpp \
    sources/piece.cpp \
    pieces/down_pawn.cpp \
    sources/player.cpp \
    pieces/up_pawn.cpp

HEADERS += \
    headers/test_game.h \
    headers/game.h \
    headers/field.h \
    headers/coordinates.h \
    headers/cell.h \
    headers/piece.h \
    pieces/down_pawn.h \
    headers/player.h \
    pieces/up_pawn.h

