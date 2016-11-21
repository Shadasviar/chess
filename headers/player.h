#ifndef PLAYER_H
#define PLAYER_H
#include <set>
#include "piece.h"

using std::set;

constexpr uint8_t PLAYERS_NUM = 2;

class player
{
public:

    player(piece::player_color col = piece::white):color(col){}

    set<piece*> pieces;
    set<coordinates> pieces_coordinates() const;
    piece::player_color color;
};

#endif // PLAYER_H
