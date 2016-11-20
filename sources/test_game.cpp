#include "test_game.h"
#include "game.h"
#include <cassert>

test_game::test_game()
{
    game g;
    auto a = g.get_move_cells({1,6});
    /*?????????*/auto b = g.get_attack_cells({1,6});
    assert(! g.move({0,0}, {2,5}));
}
