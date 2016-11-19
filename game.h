#ifndef GAME_H
#define GAME_H
#include <set>
#include "coordinates.h"
#include "field.h"

using std::set;

class player{
public:
    set<piece*> pieces;
};


class game
{
public:
    game();

    bool move(const coordinates src, const coordinates dst);
    set<coordinates> get_move_cells(const coordinates src);
    set<coordinates> get_attack_cells(const coordinates src);

private:
    field current_field;
    player players[2];
};

#endif // GAME_H
