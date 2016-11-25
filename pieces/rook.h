#ifndef ROOK_H
#define ROOK_H
#include "piece.h"


class rook : public piece
{
public:
    rook(coordinates pos, player_color col):piece(pos, col){}

    set<coordinates> all_moves() override;
    set<coordinates> all_attacks() override;

    ~rook() override;
};

#endif // ROOK_H
