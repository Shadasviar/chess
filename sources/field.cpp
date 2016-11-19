#include "field.h"
#include "pieces/down_pawn.h"

field::field()
{
    cells[0][0] = cell(coordinates(0,0), new down_pawn(coordinates(0,0),
                                                       piece::player_color::white));
}


bool field::move(const coordinates src, const coordinates dst)
{
    if(get_attack_cells(src).find(dst) != get_attack_cells(src).end()){
        attack(src, dst);
        return true;
    }
    if(get_move_cells(src).find(dst) != get_move_cells(src).end()){
        move_to(src, dst);
        return true;
    }
    return false;
}


/*TODO:*/
set<coordinates> field::get_move_cells(const coordinates src)
{
    return set<coordinates>();
}


/*TODO:*/
set<coordinates> field::get_attack_cells(const coordinates src)
{
    return set<coordinates>();
}


piece *field::get_piece(coordinates src)
{
    return cells[src.x()][src.y()].get_piece();
}


void field::attack(coordinates, coordinates)
{
    /*remove piece of opponent, count points etc, free cell*/
    /*move_to(src, dst)*/
}


void field::move_to(coordinates, coordinates)
{
    /*move pointer of piece to dst cell, free src cell*/
}
