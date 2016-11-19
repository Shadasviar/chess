#include "down_pawn.h"

set<coordinates> down_pawn::all_moves()
{
    set<coordinates> res;
    if(is_first_step){
        res.insert(position + coordinates(2,0));
    }
    res.insert(position + coordinates(1,0));
    return res;
}

set<coordinates> down_pawn::all_attacks()
{
    set<coordinates> res;
    res.insert(position + coordinates(1,1));
    res.insert(position + coordinates(-1,1));
    return res;
}

down_pawn::~down_pawn()
{

}
