#include "down_pawn.h"

set<coordinates> down_pawn::all_moves()
{
    set<coordinates> res;
    try{
        if(position.y() == 6){
            res.insert(position.add(0,-2));
        }
        res.insert(position.add(0,-1));
    }catch(std::out_of_range& ex){
        //catched - ok
    }

    return res;
}

set<coordinates> down_pawn::all_attacks()
{
    set<coordinates> res;
    try{
        res.insert(position.add(-1,-1));
    }catch(std::out_of_range& ex){
        //ok
    }

    try{
        res.insert(position.add(1,-1));
    }catch(std::out_of_range& ex){
        //ok
    }

    return res;
}

down_pawn::~down_pawn()
{

}
