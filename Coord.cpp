#include "Coord.h"


Coord::Coord()
{
    x = 0;
    y = 0;
}

Coord::Coord(int x, int y)
{
    this->x = x;
    this->y = y;
}

Coord Coord::operator=(const Coord c)
{
    x = c.x;
    y = c.y;

    return *this;
}

bool Coord::operator==(const Coord c)
{
    return (x == c.x) && (y == c.y);
}

bool Coord::operator!=(const Coord c)
{
    return (x != c.x) || (y != c.y);
}
