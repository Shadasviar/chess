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

    shared_ptr<piece>& get_piece(){return current_piece;}
    void move_piece_to(cell& dst);
    void set_position(coordinates c){place = c;}
    void set_color(piece::player_color col){color = col;}

private:
    coordinates place;
    piece::player_color color;
    shared_ptr<piece> current_piece = nullptr;
};

#endif // CELL_H
