#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"


class knight : public piece
{
public:
    knight(coordinates pos, player_color col):piece(pos, col){}

    set<coordinates> all_moves() override;
    set<coordinates> all_attacks() override;

    ~knight() override;

private:
    void add_cell(int a, int b, set<coordinates> &result);
};

#endif // KNIGHT_H
