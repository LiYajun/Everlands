#pragma once

#include "Coord.h"
#include "Piece.h"
#include <stdio.h>


typedef enum
{
    Empty,      // 无效标记
    Land,       // 陆地
    River,      // 河流
    Trap,       // 陷阱
    Nest        // 巢穴
} TileType;


class BoardTile
{
public:
    BoardTile();
    BoardTile(int color, TileType type, Coord coord, Piece *piece);

    inline int getColor()
    {
        return m_color;
    }

    inline TileType getType()
    {
        return m_type;
    }

    inline Coord getCoord()
    {
        return m_coord;
    }

    inline Piece *getPiece()
    {
        return m_piece;
    }

    void setPiece(Piece *piece);

private:
    int         m_color;
    TileType    m_type;
    Coord       m_coord;
    Piece       *m_piece;
};
