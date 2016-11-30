#include "Map.h"


Map::Map(char *fileName /* = NULL */)
{
    if (NULL == fileName)
    {
        // 竖屏
        m_maxWidth  = 7;
        m_maxHeight = 9;

        for (int i = 0; i < m_maxWidth; i++)
        {
            for (int j = 0; j < m_maxHeight; j++)
            {
                int id = i + j * m_maxWidth;

                // 颜色
                int color = 0;
                if (2 == id || 3 == id || 4 == id || 10 == id)
                {
                    color = 1;
                }
                else if (52 == id || 58 == id || 59 == id || 60 == id)
                {
                    color = 2;
                }

                // 类型
                TileType type = TileType::Land;
                if (2 == id || 4 == id || 10 == id ||
                    52 == id || 58 == id || 60 == id)
                {
                    type = TileType::Trap;
                }
                else if (3 == id || 59 == id)
                {
                    type = TileType::Nest;
                }
                else if ((1 == i || 2 == i || 4 == i || 5 == i) &&
                         (j > 2 && j < 6))
                {
                    type = TileType::River;
                }

                // 逻辑坐标
                Coord coord = {i, j};

                MapTile *tile = new MapTile(color, type, coord, NULL);
                m_tiles.push_back(tile);
            }
        }
    }
}

Map::~Map()
{
    for (int i = 0; i < m_tiles.size(); i++)
    {
        delete m_tiles[i];
    }

    m_tiles.clear();
}

MapTile *Map::getMapTile(Coord coord)
{
    MapTile *result = NULL;

    if ((coord.x >= 0 && coord.y < m_maxWidth) &&
        (coord.y >= 0 && coord.y < m_maxHeight))
    {
        result = m_tiles[coord.x + coord.y * m_maxWidth];
    }

    return result;
}

void Map::updateTiles(vector<Coord> coords)
{
    Piece *piece1 = getMapTile(coords[0])->getPiece();
    Piece *piece2 = getMapTile(coords[1])->getPiece();

    //display();

    getMapTile(coords[0])->setPiece(NULL);
    getMapTile(coords[1])->setPiece(piece1);
}
