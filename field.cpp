#include "field.h"
#include "pieces/down_pawn.h"

field::field()
{
    cells[0][0] = cell(coordinates(0,0), new down_pawn(coordinates(0,0),
                                                       piece::player_color::white));
}
