#include "up_pawn.h"

set<coordinates> up_pawn::all_moves()
{
    set<coordinates> res;
    try{
        if(position.y() == 1){
            res.insert(position.add(0,2));
        }
        res.insert(position.add(0,1));
    }catch(std::out_of_range& ex){
        //catched - ok
    }

    return res;
}


set<coordinates> up_pawn::all_attacks()
{
    set<coordinates> res;
    try{
        res.insert(position.add(-1,1));
    }catch(std::out_of_range& ex){
        //ok
    }

    try{
        res.insert(position.add(1,1));
    }catch(std::out_of_range& ex){
        //ok
    }

    return res;
}


up_pawn::~up_pawn()
{

}
