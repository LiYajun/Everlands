#include "MapTile.h"


MapTile::MapTile()
{
    m_color = -1;
    m_type  = Empty;
    m_coord = CoordInvalid;
    m_piece = NULL;
}

MapTile::MapTile(int color, TileType type, Coord coord, Piece *piece)
    :m_color(color), m_type(type), m_coord(coord), m_piece(piece)
{}
