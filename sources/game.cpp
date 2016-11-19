#include "game.h"

game::game():current_player(players[piece::white])
{

}

bool game::move(const coordinates src, const coordinates dst)
{
    if(current_player.pieces.find(current_field.get_piece(src)) != current_player.pieces.end()
            && current_player.pieces.find(current_field.get_piece(dst)) == current_player.pieces.end())
    {
        return current_field.move(src, dst);
    }
    return false;
}
