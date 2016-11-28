#ifndef GAME_H
#define GAME_H
#include <set>
#include "coordinates.h"
#include "field.h"
#include "player.h"
#include "igame.h"

using std::set;


class game : public Igame
{
public:
    game();

    bool move(const coordinates src, const coordinates dst) override;
    set<coordinates> get_move_cells(const coordinates src) override;
    set<coordinates> get_attack_cells(const coordinates src) override;

    Igame::color get_current_player_color()override {return (current_player->color == piece::white)? white : black;}

private:
    void switch_player(){current_player = (current_player->color == piece::white)
                ? &players[piece::black] : &players[piece::white];}

    bool attack(const coordinates, const coordinates);

    player players[PLAYERS_NUM] = {player(piece::white), player(piece::black)};
    player* current_player;
    field current_field;
};

#endif // GAME_H
