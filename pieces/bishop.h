#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"


class bishop : public piece
{
public:
    bishop(coordinates pos, player_color col):piece(pos, col){}

    set<coordinates> all_moves() override;
    set<coordinates> all_attacks() override;

    ~bishop() override;
};

#endif // BISHOP_H
