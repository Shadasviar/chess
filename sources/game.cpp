#include "game.h"
#include <algorithm>
#include "pieces/down_pawn.h"

#define INIT_CELL(piece_type, coordinate, color) \
current_field.init_cell(coordinate, new piece_type(coordinate, color));\
players[color].pieces.insert(current_field.get_piece(coordinate));


game::game():current_player(players[piece::white])
{
    INIT_CELL(down_pawn, coordinates(0,6), piece::white);
    INIT_CELL(down_pawn, coordinates(1,5), piece::black);
    INIT_CELL(down_pawn, coordinates(0,5), piece::white);
}


bool game::move(const coordinates src, const coordinates dst)
{
    if(current_player.pieces.count(current_field.get_piece(src)) > 0
            && current_player.pieces.count(current_field.get_piece(dst)) == 0)
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
    auto tmp1 = current_field.get_attack_cells(src);
    auto tmp = current_player.pieces_coordinates();
    std::set_difference(tmp1.begin(), tmp1.end(), tmp.begin(), tmp.end(), std::inserter(result, result.end()));
    return result;
}


bool game::attack(const coordinates src, const coordinates dst)
{
    current_field.get_piece(src)->kill();
    if(current_field.get_piece(dst)->owner_color() == piece::white){
        players[piece::white].pieces.erase(current_field.get_piece(dst));
    }else{
        players[piece::black].pieces.erase(current_field.get_piece(dst));
    }
    return current_field.move(src, dst);
}
