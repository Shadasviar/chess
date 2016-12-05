#ifndef PLAYER_H
#define PLAYER_H
#include <set>
#include "piece.h"
#include <memory>

using std::shared_ptr;

using std::set;

constexpr uint8_t PLAYERS_NUM = 2;

class player
{
public:

    player(piece::player_color col = piece::white):color(col){}

    set<shared_ptr<piece> > pieces;
    set<coordinates> pieces_coordinates() const;
    shared_ptr<piece> king;
    piece::player_color color;
};

#endif // PLAYER_H
