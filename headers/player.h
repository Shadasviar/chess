#ifndef PLAYER_H
#define PLAYER_H
#include <set>
#include "piece.h"

using std::set;

class player
{
public:

    player(piece::player_color col = piece::white):color(col){}

    set<piece*> pieces;
    piece::player_color color;
};

#endif // PLAYER_H
