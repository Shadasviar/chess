#ifndef PIECE_H
#define PIECE_H
#include "coordinates.h"
#include <set>

using std::set;


class piece
{
public:

    enum player_color{white, black};

    piece(coordinates pos, player_color col):position(pos), team_color(col){}

    virtual set<coordinates> all_moves() = 0;
    virtual set<coordinates> all_attacks() = 0;

    coordinates get_position()const{return position;}
    player_color owner_color()const{return team_color;}
    void move_to(coordinates dst){position = dst;}

    virtual ~piece();

protected:
    coordinates position;
    player_color team_color;
};

#endif // PIECE_H
