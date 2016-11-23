#include "field.h"
#include <algorithm>

field::field()
{
    for(uint8_t i(0); i < CELLS_NUM; ++i){
        for(uint8_t j(0); j < CELLS_NUM; ++j){
            cells[i][j].set_position({i,j});
        }
    }
}


bool field::move(const coordinates src, const coordinates dst)
{
    get_cell(src).move_piece_to(get_cell(dst));
    return true;
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


shared_ptr<piece> field::get_piece(coordinates src) const
{
    return get_cells()[src.x()][src.y()].get_piece();
}


void field::init_cell(coordinates c, shared_ptr<piece> p)
{
    get_cell(c).get_piece() = p;
    get_cell(c).set_position(c);
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


