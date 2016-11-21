#include "field.h"
#include "pieces/down_pawn.h"

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

    auto result = std::get<0>(check_diagonales(get_piece(src)->get_position(), get_piece(src)->all_moves()));
    auto tmp = std::get<0>(check_lines(get_piece(src)->get_position(), get_piece(src)->all_moves()));
    result.insert(tmp.begin(), tmp.end());

    return result;
}


set<coordinates> field::get_attack_cells(const coordinates src) const
{
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
    auto tmp = check_one_diag(std::tie(movement, boarder_pieces),
                              [](int& x, int& y)->bool{return x >= 0 && y >= 0;},
                              {curr.x()-1, curr.y()-1},
                              [](int& x, int& y){--x; --y;}
    );
    /*/up*/
    tmp = check_one_diag(tmp,
                              [](int& x, int& y)->bool{return x < CELLS_NUM && y >= 0;},
                              {curr.x()+1, curr.y()-1},
                              [](int& x, int& y){++x; --y;}
    );
    /*\down*/
    tmp = check_one_diag(tmp,
                              [](int& x, int& y)->bool{return x < CELLS_NUM && y < CELLS_NUM;},
                              {curr.x()+1, curr.y()+1},
                              [](int& x, int& y){++x; ++y;}
    );
    /*/down*/
    tmp = check_one_diag(tmp,
                              [](int& x, int& y)->bool{return x >= 0 && y < CELLS_NUM;},
                              {curr.x()-1, curr.y()+1},
                              [](int& x, int& y){--x; ++y;}
    );

    return std::tie(movement, boarder_pieces);
}


sets_of_movement field::check_lines(const coordinates curr, const set<coordinates> mov) const
{
    set<coordinates> movement(mov), boarder_pieces;

    /*up*/
    bool remove = false;
    for(int y(curr.y()-1); y >= 0; --y){
        if(remove){
            movement.erase(coordinates(curr.x(), y));
            continue;
        }
        if(nullptr != get_piece(coordinates(curr.x(), y))){
            remove = true;
            if(mov.count(coordinates(curr.x(), y)) > 0){
                boarder_pieces.insert(coordinates(curr.x(), y));
            }
        }
    }

    /*right*/
    remove = false;
    for(int x(curr.x()+1); x < CELLS_NUM; ++x){
        if(remove){
            movement.erase(coordinates(x, curr.y()));
            continue;
        }
        if(nullptr != get_piece(coordinates(x, curr.y()))){
            remove = true;
            if(mov.count(coordinates(x, curr.y())) > 0){
                boarder_pieces.insert(coordinates(x, curr.y()));
            }
        }
    }

    /*down*/
    remove = false;
    for(int y(curr.y()+1); y < CELLS_NUM; ++y){
        if(remove){
            movement.erase(coordinates(curr.x(), y));
            continue;
        }
        if(nullptr != get_piece(coordinates(curr.x(), y))){
            remove = true;
            if(mov.count(coordinates(curr.x(), y)) > 0){
                boarder_pieces.insert(coordinates(curr.x(), y));
            }
        }
    }

    /*left*/
    remove = false;
    for(int x(curr.x()-1); x >= 0; --x){
        if(remove){
            movement.erase(coordinates(x, curr.y()));
            continue;
        }
        if(nullptr != get_piece(coordinates(x, curr.y()))){
            remove = true;
            if(mov.count(coordinates(x, curr.y())) > 0){
                boarder_pieces.insert(coordinates(x, curr.y()));
            }
        }
    }

    return std::tie(movement, boarder_pieces);
}


cell &field::get_cell(coordinates c)
{
    return cells[c.x()][c.y()];
}


cell_table field::get_cells() const
{
    return cells;
}


sets_of_movement field::check_one_diag(sets_of_movement sets,
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

