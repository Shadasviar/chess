#include "coordinates.h"
#define NDEBUG
#include <cassert>


coordinates::coordinates(uint8_t x, uint8_t y) throw(std::out_of_range):_x(x), _y(y)
{
    assert(x < CELLS_NUM && y < CELLS_NUM);
    if(x >= CELLS_NUM || y >= CELLS_NUM) throw std::out_of_range("Bad coordinates");
}


void coordinates::set_x(uint8_t x)throw(std::out_of_range)
{
    assert(x < CELLS_NUM);
    if(x >= CELLS_NUM) throw std::out_of_range("Bad coordinates");
}


void coordinates::set_y(uint8_t y)throw(std::out_of_range)
{
    assert(y < CELLS_NUM);
    if(y >= CELLS_NUM) throw std::out_of_range("Bad coordinates");
}

coordinates coordinates::add(int x, int y) const throw(std::out_of_range)
{
    int8_t tmp_x(_x), tmp_y(_y);
    try{
        return coordinates((uint8_t)(x + tmp_x), (uint8_t)(y + tmp_y));
    }catch(std::out_of_range& ex){
        throw ex;
    }
}


coordinates operator+(const coordinates &lhs, const coordinates &rhs)
{
    return coordinates(lhs._x + rhs._x, lhs._y + rhs._y);
}


coordinates operator-(const coordinates &lhs, const coordinates &rhs)
{
    return coordinates(lhs._x - rhs._x, lhs._y - rhs._y);
}


bool operator<(const coordinates &lhs, const coordinates &rhs)
{
    if(lhs._x < rhs._x) return true;
    if(lhs._x == rhs._x && lhs._y < rhs._y) return true;
    return false;
}


bool operator==(const coordinates& lhs, const coordinates& rhs){
    return (lhs.x() == rhs.x() && lhs.y() == rhs.y());
}
