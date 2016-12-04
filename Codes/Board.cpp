#include "Board.h"
#include "GameManager.h"
#include "InputControl.h"


Board::Board()
{}

Board::~Board()
{
    for (int i = 0; i < m_tiles.size(); i++)
    {
        m_tiles[i]->setPiece(NULL);
        delete m_tiles[i];
    }

    m_tiles.clear();
}

Board *Board::create(Node *parent, std::string fileName /* = NULL */)
{
    Board *pRet = new(std::nothrow) Board();
    if (pRet && pRet->init(parent, fileName))
    {
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool Board::init(Node *parent, std::string  fileName /* = NULL */)
{
    if ( fileName.empty())
    {
        fileName =  "Images/board.png";
    }
    m_bg = Sprite::create(fileName);
    parent->addChild(m_bg);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    m_bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    // 竖屏
    m_maxWidth  = 7;
    m_maxHeight = 9;

    for (int h = 0; h < m_maxHeight; h++)
    {
        for (int w = 0; w < m_maxWidth; w++)
        {
            int id = w + h * m_maxWidth;

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
            else if ((1 == w || 2 == w || 4 == w || 5 == w) &&
                     (h > 2 && h < 6))
            {
                type = TileType::River;
            }

            // 逻辑坐标
            Coord coord = {w, h};

            BoardTile *tile = new BoardTile(color, type, coord, NULL);
            m_tiles.push_back(tile);
        }
    }

    return true;
}

void Board::addPiece(Piece *piece)
{
    getBoardTile(piece->logicCoord)->setPiece(piece);

    Vec2 p =  GameManager::shareGameManager()->getInputControl()->convertCoordToVec2(piece->logicCoord);
    piece->showSp->setPosition(p);
    m_bg->addChild(piece->showSp);
}

BoardTile *Board::getBoardTile(Coord coord)
{
    BoardTile *result = NULL;

    if ((coord.x >= 0 && coord.x < m_maxWidth) &&
        (coord.y >= 0 && coord.y < m_maxHeight))
    {
        result = m_tiles[coord.x + coord.y * m_maxWidth];
    }

    return result;
}

void Board::updateTiles(vector<Coord> coords)
{
    Piece *piece1 = getBoardTile(coords[0])->getPiece();
    Piece *piece2 = getBoardTile(coords[1])->getPiece();

    //display();

    getBoardTile(coords[0])->setPiece(NULL);
    getBoardTile(coords[1])->setPiece(piece1);
}
