#include "test_game.h"
#include "game.h"
#include <cassert>

test_game::test_game()
{
    game g;
    assert(! g.move({0,0}, {2,10}));
}
