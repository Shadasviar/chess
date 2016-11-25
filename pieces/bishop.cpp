#include "bishop.h"

set<coordinates> bishop::all_moves()
{
    set<coordinates> res;
    try{
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
    }catch(std::out_of_range& ex){
        //catched - ok
    }

    return res;
}

set<coordinates> bishop::all_attacks()
{
    return all_moves();
}

bishop::~bishop()
{

}
