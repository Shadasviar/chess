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
};

#endif // KNIGHT_H
