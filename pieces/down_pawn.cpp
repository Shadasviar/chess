#include "down_pawn.h"

set<coordinates> down_pawn::all_moves()
{
    set<coordinates> res;
    if(position.y() == 6){
        res.insert(position - coordinates(0,2));
    }
    res.insert(position - coordinates(0,1));
    return res;
}

set<coordinates> down_pawn::all_attacks()
{
    set<coordinates> res;
    res.insert(position + coordinates(1,0) - coordinates(0,1));
    res.insert(position - coordinates(1,1));
    return res;
}

down_pawn::~down_pawn()
{

}
