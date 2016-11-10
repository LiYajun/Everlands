#pragma once

#include <vector>
#include "MapTile.h"

using std::vector;


class Map
{
public:
    Map(char *fileName = NULL);
    virtual ~Map();

    MapTile *getMapTile(Coord coord);           // 根据逻辑坐标返回地图片元
    void updateTiles(vector<Coord>coords);      // 更新地图片元

private:
    int                 m_maxWidth;             // 宽
    int                 m_maxHeight;            // 高
    vector<MapTile *>   m_tiles;
};
