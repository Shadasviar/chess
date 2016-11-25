#ifndef KING_H
#define KING_H
#include "piece.h"


class king : public piece
{
public:
    king(coordinates pos, player_color col):piece(pos, col){}

    set<coordinates> all_moves() override;
    set<coordinates> all_attacks() override;

    ~king() override;
};

#endif // KING_H
