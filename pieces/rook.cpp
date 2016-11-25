#include "rook.h"

set<coordinates> rook::all_moves()
{
    set<coordinates> res;

    for(uint8_t i(0); i < CELLS_NUM; ++i){
        if(i == position.y()) continue;
        res.insert(coordinates(position.x(), i));
    }
    for(uint8_t i(0); i < CELLS_NUM; ++i){
        if(i == position.x()) continue;
        res.insert(coordinates(i, position.y()));
    }

    return res;
}

set<coordinates> rook::all_attacks()
{
    return all_moves();
}

rook::~rook()
{

}
