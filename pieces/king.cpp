#include "king.h"

set<coordinates> king::all_moves()
{
    set<coordinates> res;

    auto foo = [&](int x, int y){
        try{
            res.insert(position.add(x,y));
        }catch(std::out_of_range&){/*ok*/};
    };

    foo(-1,-1);
    foo(0,-1);
    foo(1,-1);
    foo(-1,0);
    foo(0,1);
    foo(1,1);
    foo(1,0);
    foo(-1,1);

    return res;
}

set<coordinates> king::all_attacks()
{
    return all_moves();
}

king::~king()
{

}
