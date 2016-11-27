#ifndef UP_PAWN_H
#define UP_PAWN_H
#include "piece.h"


class up_pawn : public piece
{
public:
    up_pawn(coordinates pos, player_color col):piece(pos, col){}

    set<coordinates> all_moves() override;
    set<coordinates> all_attacks() override;

    ~up_pawn() override;
};

#endif // UP_PAWN_H
