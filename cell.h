#ifndef CELL_H
#define CELL_H
#include "piece.h"


class cell
{
public:
    cell();
    cell(coordinates place, piece* _piece = nullptr):
        place(place), current_piece(_piece){}

    enum cell_color{cell_white, cell_black};

    coordinates place;
    cell_color color;
    piece* current_piece;
};

#endif // CELL_H
