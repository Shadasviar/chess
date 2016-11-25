#include "queen.h"

set<coordinates> queen::all_moves()
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

    for(uint8_t i(position.x()+1), j(position.y()+1); i < CELLS_NUM && j < CELLS_NUM; ++i, ++j){
        res.insert(coordinates(i,j));
    }
    for(int i(position.x()-1), j(position.y()-1); i >= 0 && j >= 0; --i, --j){
        res.insert(coordinates(i,j));
    }
    for(int i(position.x()-1), j(position.y()+1); i >= 0 && j < CELLS_NUM; --i, ++j){
        res.insert(coordinates(i,j));
    }
    for(int i(position.x()+1), j(position.y()-1); j >= 0 && i < CELLS_NUM; --j, ++i){
        res.insert(coordinates(i,j));
    }

    return res;
}

set<coordinates> queen::all_attacks()
{
    return all_moves();
}

queen::~queen()
{

}
