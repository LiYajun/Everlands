#pragma once

#include <vector>
#include "Coord.h"

using std::vector;

class Piece;


typedef enum
{
    Land,       // 陆地
    River,      // 河流
    Trap,       // 陷阱
    Nest        // 巢穴
} TileType;


struct Tile
{
    int         color;
    TileType    type;
    Coord       coord;
    Piece       *piece;
};


class Map
{
public:
    Map();
    virtual ~Map();

    Tile *getTile(Coord coord);             // 根据逻辑坐标返回地图片元
    void updateTiles(vector<Coord>coords);  // 更新地图片元

private:
    int             m_maxRow;
    int             m_maxColumn;
    vector<Tile *>  m_tiles;
};
