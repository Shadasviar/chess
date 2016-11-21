#include "field.h"
#include "pieces/down_pawn.h"
#include <algorithm>

#define INIT_CELL(piece_obj, c, col) cell(c, new piece_obj(c, col))

field::field()
{
    cells[0][6] = INIT_CELL(down_pawn, coordinates(0,6), piece::white);
    cells[0][5] = INIT_CELL(down_pawn, coordinates(0,5), piece::black);
}


bool field::move(const coordinates src, const coordinates dst, player players[PLAYERS_NUM] )
{
    if(get_attack_cells(src).count(dst) > 0){
        attack(src, dst, players);
        return true;
    }
    if(get_move_cells(src).count(dst) > 0){
        move_to(src, dst);
        return true;
    }
    return false;
}


set<coordinates> field::get_move_cells(const coordinates src) const
{
    if(get_piece(src) == nullptr) return set<coordinates>();

    auto tmp1 = std::get<0>(check_diagonales(get_piece(src)->get_position(), get_piece(src)->all_moves()));
    auto tmp = std::get<0>(check_lines(get_piece(src)->get_position(), get_piece(src)->all_moves()));
    set<coordinates> result;
    std::set_intersection(tmp1.begin(), tmp1.end(), tmp.begin(), tmp.end(), std::inserter(result, result.end()));

    return result;
}


set<coordinates> field::get_attack_cells(const coordinates src) const
{
    if(get_piece(src) == nullptr) return set<coordinates>();

    auto result = std::get<1>(check_diagonales(get_piece(src)->get_position(), get_piece(src)->all_attacks()));
    auto tmp = std::get<1>(check_lines(get_piece(src)->get_position(), get_piece(src)->all_attacks()));
    result.insert(tmp.begin(), tmp.end());

    return result;
}


piece *field::get_piece(coordinates src) const
{
    return get_cells()[src.x()][src.y()].get_piece();
}


void field::attack(const coordinates src, const coordinates dst, player players[PLAYERS_NUM])
{
    /*remove piece of opponent, count points etc, free cell*/
    /*move_to(src, dst)*/
    get_cell(dst).get_piece()->kill();
    if(get_cell(dst).get_piece()->owner_color() == piece::white){
        players[piece::white].pieces.erase(get_cell(dst).get_piece());
    }else{
        players[piece::black].pieces.erase(get_cell(dst).get_piece());
    }
    move_to(src, dst);
}


void field::move_to(const coordinates src, const coordinates dst)
{
    get_cell(dst).get_piece() = get_piece(src);
    get_cell(src).get_piece() = nullptr;
}


sets_of_movement field::check_diagonales(const coordinates curr, const set<coordinates> mov) const
{
    set<coordinates> movement(mov), boarder_pieces;

    /*\up*/
    sets_of_movement tmp = check_one_line(std::tie(movement, boarder_pieces),
                              [](int& x, int& y)->bool{return x >= 0 && y >= 0;},
                              {curr.x()-1, curr.y()-1},
                              [](int& x, int& y){--x; --y;}
    );
    /*/up*/
    tmp = check_one_line(tmp,
                              [](int& x, int& y)->bool{return x < CELLS_NUM && y >= 0;},
                              {curr.x()+1, curr.y()-1},
                              [](int& x, int& y){++x; --y;}
    );
    /*\down*/
    tmp = check_one_line(tmp,
                              [](int& x, int& y)->bool{return x < CELLS_NUM && y < CELLS_NUM;},
                              {curr.x()+1, curr.y()+1},
                              [](int& x, int& y){++x; ++y;}
    );
    /*/down*/
    tmp = check_one_line(tmp,
                              [](int& x, int& y)->bool{return x >= 0 && y < CELLS_NUM;},
                              {curr.x()-1, curr.y()+1},
                              [](int& x, int& y){--x; ++y;}
    );

    return tmp;
}


sets_of_movement field::check_lines(const coordinates curr, const set<coordinates> mov) const
{
    set<coordinates> movement(mov), boarder_pieces;

    /*up*/
    auto tmp = check_one_line(std::tie(movement, boarder_pieces),
                              [](int&, int& y)->bool{return y >= 0;},
                              {curr.x(), curr.y()-1},
                              [](int&, int& y){--y;}
    );
    /*right*/
    tmp = check_one_line(tmp,
                              [](int& x, int&)->bool{return x < CELLS_NUM;},
                              {curr.x()+1, curr.y()},
                              [](int& x, int&){++x;}
    );
    /*down*/
    tmp = check_one_line(tmp,
                              [](int&, int& y)->bool{return y < CELLS_NUM;},
                              {curr.x(), curr.y()+1},
                              [](int&, int& y){++y;}
    );
    /*left*/
    tmp = check_one_line(tmp,
                              [](int& x, int&)->bool{return x >= 0;},
                              {curr.x()-1, curr.y()},
                              [](int& x, int&){--x;}
    );

    return tmp;
}


cell &field::get_cell(coordinates c)
{
    return cells[c.x()][c.y()];
}


cell_table field::get_cells() const
{
    return cells;
}


sets_of_movement field::check_one_line(sets_of_movement sets,
        bool (*condition)(int &, int &),
        array<int, 2> curr,
        void (*foo)(int &, int &)) const
{
    auto movement = std::get<0>(sets);
    auto boarder_pieces = std::get<1>(sets);
    int x = curr[0], y = curr[1];

    bool remove = false;
    while(condition(x,y)){
        if(remove){
            movement.erase(coordinates(x, y));
            foo(x,y);
            continue;
        }
        if(nullptr == get_piece(coordinates(x, y))){
            foo(x,y);
        }
        else{
            if(movement.count(coordinates(x,y)) > 0){
                boarder_pieces.insert(coordinates(x,y));
                movement.erase(coordinates(x, y));
            }
            remove = true;
            foo(x,y);
        }
    }
    return std::tie(movement, boarder_pieces);
}


