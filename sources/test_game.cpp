#include "test_game.h"
#include "game.h"
#include <cassert>

test_game::test_game()
{
    game g;
    auto a = g.get_move_cells({0,6});
    /*?????????*/auto b = g.get_attack_cells({0,6});
    a = g.get_move_cells({0,5});
    b = g.get_attack_cells({0,5});
    a = g.get_move_cells({3,5});
    assert(! g.move({0,0}, {2,5}));
}
