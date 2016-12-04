#pragma once

#include "BoardTile.h"
#include "cocos2d.h"
#include <vector>

USING_NS_CC;
using std::vector;


class Board
{
public:
    Board();
    virtual ~Board();
    
    static Board *create(Node *parent,  std::string fileName = NULL);
    virtual bool init(Node *parent, std::string fileName = NULL);
    void addPiece(Piece *piece);

    BoardTile *getBoardTile(Coord coord);       // 根据逻辑坐标返回地图片元
    void updateTiles(vector<Coord> coords);     // 更新地图片元

private:
    int                 m_maxWidth;             // 宽
    int                 m_maxHeight;            // 高
    vector<BoardTile *>   m_tiles;

    Sprite              *m_bg;
};
