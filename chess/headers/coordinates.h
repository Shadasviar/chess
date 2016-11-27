#ifndef COORDINATES_H
#define COORDINATES_H

#include <cstdint>
#include <stdexcept>

constexpr uint8_t CELLS_NUM = 8;


class coordinates
{
public:
    coordinates(uint8_t x = 0, uint8_t y = 0) throw(std::out_of_range);

    uint8_t x() const {return _x;}
    uint8_t y() const {return _y;}
    void set_x(uint8_t x) throw(std::out_of_range);
    void set_y(uint8_t y) throw(std::out_of_range);
    friend coordinates operator+(const coordinates& lhs, const coordinates& rhs);
    friend coordinates operator-(const coordinates& lhs, const coordinates& rhs);
    friend bool operator<(const coordinates& lhs, const coordinates& rhs);
    coordinates add(int x, int y)const throw(std::out_of_range);

private:
    uint8_t _x, _y;
};

#endif // COORDINATES_H
