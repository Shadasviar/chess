#ifndef CELL_H
#define CELL_H
#include "piece.h"
#include <memory>

using std::shared_ptr;


class cell
{
public:
    cell();
    cell(coordinates place, piece* _piece = nullptr):
        place(place), current_piece(_piece){}

    enum cell_color{cell_white, cell_black};
    shared_ptr<piece>& get_piece(){return current_piece;}
    void move_piece_to(cell dst);

private:
    coordinates place;
    cell_color color;
    shared_ptr<piece> current_piece = nullptr;
};

#endif // CELL_H
