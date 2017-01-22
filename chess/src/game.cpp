#include "game.h"
#include <algorithm>
#include "pieces/down_pawn.h"
#include "pieces/up_pawn.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/rook.h"
#include "pieces/queen.h"
#include "pieces/king.h"

#define INIT_CELL(piece_type, coordinate, color) \
tmp.reset(new piece_type(coordinate, color));\
current_field.init_cell(coordinate, tmp);\
players[color].pieces.insert(current_field.get_piece(coordinate));


game::game():Igame(), current_player(&players[piece::white])
{
    shared_ptr<piece> tmp;

    for(size_t i(0); i < CELLS_NUM; ++i){
        INIT_CELL(up_pawn, coordinates(i,1), piece::black);
    }
    for(size_t i(0); i < CELLS_NUM; ++i){
        INIT_CELL(down_pawn, coordinates(i,6), piece::white);
    }

    INIT_CELL(rook, coordinates(0,7), piece::white);
    INIT_CELL(rook, coordinates(7,7), piece::white);
    INIT_CELL(rook, coordinates(0,0), piece::black);
    INIT_CELL(rook, coordinates(7,0), piece::black);

    INIT_CELL(knight, coordinates(1,7), piece::white);
    INIT_CELL(knight, coordinates(6,7), piece::white);
    INIT_CELL(knight, coordinates(6,0), piece::black);
    INIT_CELL(knight, coordinates(1,0), piece::black);

    INIT_CELL(bishop, coordinates(2,7), piece::white);
    INIT_CELL(bishop, coordinates(5,7), piece::white);
    INIT_CELL(bishop, coordinates(5,0), piece::black);
    INIT_CELL(bishop, coordinates(2,0), piece::black);

    INIT_CELL(queen, coordinates(3,7), piece::white);
    INIT_CELL(queen, coordinates(3,0), piece::black);

    INIT_CELL(king, coordinates(4,7), piece::white);
    players[piece::white].king = tmp;
    INIT_CELL(king, coordinates(4,0), piece::black);
    players[piece::black].king = tmp;
}


bool game::move(const coordinates src, const coordinates dst)
{
    if(current_player->pieces.count(current_field.get_piece(src)) > 0
            && current_player->pieces.count(current_field.get_piece(dst)) == 0)
    {
        if(get_attack_cells(src).count(dst) > 0){
            if(attack(src, dst)){
                switch_player();
                return true;
            }
            return false;
        }
        if(get_move_cells(src).count(dst) > 0){
            if(current_field.move(src, dst)){
                switch_player();
                return true;
            }
            return false;
        }
    }
    return false;
}


set<coordinates> game::get_move_cells(const coordinates src)
{
    return current_field.get_move_cells(src);
}


set<coordinates> game::get_attack_cells(const coordinates src)
{
    set<coordinates> result;
    if(current_field.get_piece(src) == nullptr) return result;
    auto tmp1 = current_field.get_attack_cells(src);
    auto tmp = players[current_field.get_piece(src)->owner_color()].pieces_coordinates();
    std::set_difference(tmp1.begin(), tmp1.end(), tmp.begin(), tmp.end(), std::inserter(result, result.end()));
    return result;
}


bool game::current_player_is_under_check()
{
    player* enemy = (current_player->color == piece::white) ? &players[piece::black] : &players[piece::white];
    for(shared_ptr<piece> p : enemy->pieces){
        if(current_field.get_attack_cells(p->get_position()).count(current_player->king->get_position()) > 0) return true;
    }
    return false;
}


set<coordinates> game::get_pieces_of_player(const Igame::color col)
{
    set<coordinates> result;
    for(auto p : players[to_player_color(col)].pieces){
        result.insert(p->get_position());
    }
    return result;
}


bool game::attack(const coordinates src, const coordinates dst)
{
    if(current_field.get_piece(dst)->owner_color() == piece::white){
        players[piece::white].pieces.erase(current_field.get_piece(dst));
    }else{
        players[piece::black].pieces.erase(current_field.get_piece(dst));
    }
    return current_field.move(src, dst);
}


piece::player_color game::to_player_color(const Igame::color c)
{
    return (c == white) ? piece::white : piece::black;
}
