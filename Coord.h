#pragma once


// 逻辑坐标
struct Coord
{
    int x;
    int y;

    Coord();
    Coord(int x, int y);

    Coord operator=(const Coord c);
    bool operator==(const Coord c) const;
    bool operator!=(const Coord c) const;

    // 判断坐标是否无效
    bool isInvalid() const;
};

// 无效坐标
const Coord CoordInvalid = {-1000, -1000};
