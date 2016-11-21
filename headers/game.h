#ifndef GAME_H
#define GAME_H
#include <set>
#include "coordinates.h"
#include "field.h"
#include "player.h"

using std::set;


class game
{
public:
    game();

    bool move(const coordinates src, const coordinates dst);
    set<coordinates> get_move_cells(const coordinates src);
    set<coordinates> get_attack_cells(const coordinates src);

private:
    void switch_player(){current_player = (current_player.color == piece::white)
                ? players[piece::black] : players[piece::white];}

    player players[PLAYERS_NUM] = {player(piece::white), player(piece::black)};
    player& current_player;
    field current_field;
};

#endif // GAME_H
