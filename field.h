#ifndef FIELD_H
#define FIELD_H
#include"coordinates.h"
#include "cell.h"
#include <set>

using std::set;


class field
{
public:
    field();

    bool move(const coordinates src, const coordinates dst);
    set<coordinates> get_move_cells(const coordinates src);
    set<coordinates> get_attack_cells(const coordinates src);

private:
    cell cells[8][8];
};

#endif // FIELD_H
