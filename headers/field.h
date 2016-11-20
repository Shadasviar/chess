#ifndef FIELD_H
#define FIELD_H
#include"coordinates.h"
#include "cell.h"
#include <set>
#include <tuple>
#include <array>
#include "player.h"

constexpr uint8_t CELLS_NUM = 8;

using std::set;
using std::tuple;
using std::array;
using sets_of_movement = tuple<set<coordinates>, set<coordinates>>;
using cell_table = array<array<cell, CELLS_NUM>, CELLS_NUM>;


class field
{
public:
    field();

    bool move(const coordinates src, const coordinates dst, player players[PLAYERS_NUM] );
    set<coordinates> get_move_cells(const coordinates src) const;
    set<coordinates> get_attack_cells(const coordinates src) const;
    piece* get_piece(coordinates src) const;

private:
    cell_table cells;
    void attack(const coordinates, const coordinates, player players[PLAYERS_NUM]);
    void move_to(const coordinates src, const coordinates dst);

    /*first set - cells before first piece on way, second - pieces which cut way*/
    sets_of_movement check_diagonales(const coordinates curr, const set<coordinates> mov) const;
    sets_of_movement check_lines(const coordinates curr, const set<coordinates> mov) const;
    cell& get_cell(coordinates c);
    cell_table get_cells() const;
};

#endif // FIELD_H
