#include "Coord.h"
#include <math.h>


Coord::Coord()
{
    *this = CoordInvalid;
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

bool Coord::operator==(const Coord c) const
{
    return (x == c.x) && (y == c.y);
}

bool Coord::operator!=(const Coord c) const
{
    return (x != c.x) || (y != c.y);
}

Coord Coord::operator+(const Coord c) const
{
    Coord result;

    result.x = x + c.x;
    result.y = y + c.y;

    return result;
}

Coord Coord::operator-(const Coord c) const
{
    Coord result;

    result.x = x - c.x;
    result.y = y - c.y;

    return result;
}

bool Coord::isInvalid() const
{
    return (CoordInvalid == *this);
}
