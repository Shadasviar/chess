#ifndef DOWN_PAWN_H
#define DOWN_PAWN_H
#include "piece.h"


class down_pawn : public piece
{
public:
    down_pawn(coordinates pos, player_color col):piece(pos, col){}

    set<coordinates> all_moves() override;
    set<coordinates> all_attacks() override;

    ~down_pawn() override;

};

#endif // DOWN_PAWN_H
