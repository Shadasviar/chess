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
    bool current_player_is_under_check() override;
    virtual set<coordinates> get_pieces_of_player(const color) override;

    Igame::color get_current_player_color()override {return (current_player->color == piece::white)? white : black;}

protected:
    void switch_player(){current_player = (current_player->color == piece::white)
                ? &players[piece::black] : &players[piece::white];}

    bool attack(const coordinates, const coordinates);

    player players[PLAYERS_NUM] = {player(piece::white), player(piece::black)};
    player* current_player;
    field current_field;

private:
    piece::player_color to_player_color(const color);

    template<typename T>
    void INIT_CELL(coordinates cr, piece::player_color col){
        current_field.init_cell(cr, p_piece(new T(cr, col)));\
        players[col].pieces.insert(current_field.get_piece(cr));
    }
};

#endif // GAME_H
