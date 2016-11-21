#include "game.h"

game::game():current_player(players[piece::white])
{

}

bool game::move(const coordinates src, const coordinates dst)
{
    if(current_player.pieces.count(current_field.get_piece(src)) > 0
            && current_player.pieces.count(current_field.get_piece(dst)) == 0)
    {
        if(current_field.move(src, dst, players)){
            switch_player();
            return true;
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
    return current_field.get_attack_cells(src);
}
