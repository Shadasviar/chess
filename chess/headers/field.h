#ifndef FIELD_H
#define FIELD_H
#include"coordinates.h"
#include <set>
#include <tuple>
#include <map>
#include <memory>
#include <array>
#include "piece.h"

using std::set;
using std::tuple;
using std::map;
using std::array;
using std::shared_ptr;

using sets_of_movement = tuple<set<coordinates>, set<coordinates>>;
using cell_table = map<coordinates, shared_ptr<piece> >;
using p_piece = shared_ptr<piece>;


class field
{
public:
    field();

    bool move(const coordinates src, const coordinates dst);
    set<coordinates> get_move_cells(const coordinates src) const;
    set<coordinates> get_attack_cells(const coordinates src) const;
    p_piece get_piece(coordinates src) const;
    void init_cell(coordinates c, p_piece p);

private:
    cell_table cells;
    
    /*first set - cells before first piece on way, second - pieces which cut way*/
    sets_of_movement check_diagonales(const coordinates curr, const set<coordinates> mov) const;
    sets_of_movement check_lines(const coordinates curr, const set<coordinates> mov) const;
    sets_of_movement check_horse(const coordinates curr, const set<coordinates> mov) const;
    sets_of_movement check_one_line(sets_of_movement, bool(*)(int &, int &), array<int, 2>, void(*)(int&, int&)) const;
};

#endif // FIELD_H
