#include "knight.h"


set<coordinates> knight::all_moves()
{
    set<coordinates> result;
    add_cell(-1,2, result);
    add_cell(-2,1, result);
    add_cell(-1,-2, result);
    add_cell(-2,-1, result);
    add_cell(1,2, result);
    add_cell(2,1, result);
    add_cell(1,-2, result);
    add_cell(2,-1, result);
    return result;
}


set<coordinates> knight::all_attacks()
{
    return all_moves();
}


void knight::add_cell(int a, int b, set<coordinates>& result)
{
    try{
        result.insert(position.add(a,b));
    }
    catch(std::out_of_range&){/*ok*/}
}


knight::~knight(){

}
