#ifndef IGAME_H
#define IGAME_H
#include <set>
#include "coordinates.h"


/*________INTERFACE_____________________*/

using std::set;


class Igame
{
public:

    enum color{white, black};

    Igame(){}
    virtual bool move(const coordinates src, const coordinates dst) = 0;
    virtual set<coordinates> get_move_cells(const coordinates src) = 0;
    virtual set<coordinates> get_attack_cells(const coordinates src) = 0;
    virtual set<coordinates> get_pieces_of_player(const color) = 0;
    virtual bool current_player_is_under_check() =0;

    virtual color get_current_player_color() = 0;

    virtual ~Igame() {}
};

#endif // IGAME_H
