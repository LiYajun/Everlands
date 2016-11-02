#pragma once


// 坐标
struct Coord
{
    int x;
    int y;

    Coord();
    Coord(int x, int y);

    Coord operator=(const Coord c);
    bool operator==(const Coord c);
    bool operator!=(const Coord c);
};
