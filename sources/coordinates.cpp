#include "coordinates.h"
#include <cassert>


coordinates::coordinates(uint8_t x, uint8_t y) throw(std::out_of_range):_x(x), _y(y)
{
    assert(x < 8 && y < 8);
    if(x >= 8 || y >= 8) throw std::out_of_range("Bad coordinates");
}


void coordinates::set_x(uint8_t x)throw(std::out_of_range)
{
    assert(x < 8);
    if(x >= 8) throw std::out_of_range("Bad coordinates");
}


void coordinates::set_y(uint8_t y)throw(std::out_of_range)
{
    assert(y < 8);
    if(y >= 8) throw std::out_of_range("Bad coordinates");
}


coordinates operator+(const coordinates &lhs, const coordinates &rhs)
{
    return coordinates(lhs._x + rhs._x, lhs._y + rhs._y);
}


bool operator<(const coordinates &lhs, const coordinates &rhs)
{
    if(lhs._x < rhs._x) return true;
    if(lhs._x == rhs._x && lhs._y < rhs._y) return true;
    return false;
}
