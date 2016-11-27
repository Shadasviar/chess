#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"


class queen : public piece
{
public:
    queen(coordinates pos, player_color col):piece(pos, col){}

    set<coordinates> all_moves() override;
    set<coordinates> all_attacks() override;

    ~queen() override;
};

#endif // QUEEN_H
