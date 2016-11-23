#include "cell.h"

cell::cell()
{

}

void cell::move_piece_to(cell &dst)
{
    dst.get_piece() = current_piece;
    dst.get_piece()->move_to(dst.place);
    current_piece = nullptr;
}
