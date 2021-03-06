#include "player.h"

set<coordinates> player::pieces_coordinates() const
{
    set<coordinates> result;
    for(auto p : pieces){
        result.insert(p->get_position());
    }
    return result;
}
