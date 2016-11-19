TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test_game.cpp \
    game.cpp \
    field.cpp \
    coordinates.cpp \
    cell.cpp \
    piece.cpp \
    pieces/down_pawn.cpp

HEADERS += \
    test_game.h \
    game.h \
    field.h \
    coordinates.h \
    cell.h \
    piece.h \
    pieces/down_pawn.h

