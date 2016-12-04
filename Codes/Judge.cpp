
#include "GameManager.h"
#include "Board.h"
#include "Piece.h"
#include <assert.h>
#include "Actor.h"
#include "Judge.h"
Judge::~Judge()
{
    for (vector<Actor *>::iterator it = m_allActors.begin(); m_allActors.end() != it; it++)
    {
        delete *it;
    }

    m_aliveActors.clear();
    m_allActors.clear();
}

Judge *Judge::create()
{
    Judge *pRet = new(std::nothrow) Judge();

    if (pRet && pRet->init())
    {
        // nothing to do.
    }
    else
    {
        delete pRet;
        pRet = NULL;
    }

    return pRet;
}

bool Judge::init()
{
    m_curIndex = 0;

    for (int i = 0; i < 2; i++)
    {
        Actor *actor = Actor::create(i + 1);
        m_allActors.push_back(actor);
        m_aliveActors.push_back(actor);
    }

    return true;
}


Actor *Judge::getCurrentActor()
{
    Actor *result = NULL;

    if (m_curIndex >=0 && m_curIndex < m_aliveActors.size())
    {
        result = m_aliveActors[m_curIndex];
    }

    return result;
}

Actor *Judge::getActor(int color)
{
    Actor *result = NULL;

    for (vector<Actor *>::iterator it = m_aliveActors.begin(); m_aliveActors.end() != it; it++)
    {
        if (color == (*it)->getColor())
        {
            result = *it;
            break;
        }
    }

    return result;
}

void Judge::switchNextActor()
{
    m_curIndex = (m_curIndex + 1) % m_aliveActors.size();
}

bool Judge::judgeCanMove(vector<Coord> coords)
{
    Board *board = GameManager::shareGameManager()->getMap();

    // 需要两个同行同列的逻辑坐标
    if (2 != coords.size() || coords[0] == coords[1] || 
        (coords[0].x != coords[1].x && coords[0].y != coords[1].y))
    {
        return false;
    }

    // 起点要有棋子
    Piece *piece = board->getBoardTile(coords[0])->getPiece();
    if (NULL == piece)
    {
        return false;
    }

    // 单步
    if (1 == abs(coords[0].x - coords[1].x) + abs(coords[0].y - coords[1].y))
    {
        // 单步
        if (PieceType::Mouse == piece->getType())
        {
            // 老鼠单步，总允许
            return true;
        }
        else if (TileType::River != board->getBoardTile(coords[1])->getType())
        {
            // 其他动物岸上单步，总允许
            return true;
        }
    }
    // 跃河
    else if (PieceType::Lion == piece->getType() || PieceType::Tiger == piece->getType())
    {
        // 纵跳
        if (coords[0].x == coords[1].x)
        {
            bool bH = (1 == coords[0].x) || (2 == coords[0].x) || (4 == coords[0].x) || (5 == coords[0].x);
            bool bV = (2 == coords[0].y && 6 == coords[1].y) || (6 == coords[0].y && 2 == coords[1].y);
            if (bH && bV)
            {
                for (int i = 3; i < 6; i++)
                {
                    if (NULL != board->getBoardTile(Coord(coords[0].x, i))->getPiece())
                    {
                        return false;
                    }
                }

                return true;
            }
        }
        // 横跳
        else if (coords[0].y == coords[1].y)
        {
            bool bV = (3 == coords[0].y) || (4 == coords[0].y) || (5 == coords[0].y);
            bool bH = (3 == abs(coords[0].x - coords[1].x));
            if (bV && bH)
            {
                int leftX = (coords[0].x < coords[1].x) ? coords[0].x : coords[1].x;
                for (int i = leftX + 1; i < leftX + 3; i++)
                {
                    if (NULL != board->getBoardTile(Coord(i, coords[0].y))->getPiece())
                    {
                        return false;
                    }
                }

                return true;
            }
        }
    }

    return false;
}

bool Judge::judgeCanMoveAndEat(vector<Coord> coords)
{
    Board *board = GameManager::shareGameManager()->getMap();

    Piece *piece1 = board->getBoardTile(coords[0])->getPiece();
    Piece *piece2 = board->getBoardTile(coords[1])->getPiece();

    // 不存在吃子关系
    if (!piece1 || !piece2 || piece1->getColor() == piece2->getColor())
    {
        return false;
    }

    // 不符合走棋路线
    if (!judgeCanMove(coords))
    {
        return false;
    }

    // 判断能否吃子
    if (TileType::Trap == board->getBoardTile(coords[1])->getType() &&
        board->getBoardTile(coords[1])->getColor() != board->getBoardTile(coords[1])->getPiece()->getColor())
    {
        return true;
    }
    else if (PieceType::Elephant == piece1->getType())
    {
        return (PieceType::Mouse != piece2->getType());
    }
    else if (PieceType::Mouse == piece1->getType())
    {
        return (PieceType::Elephant == piece2->getType() || PieceType::Mouse == piece2->getType());
    }
    else
    {
        return (piece1->getType() <= piece2->getType());
    }
}

bool Judge::checkOneGameOver()
{
    static const int coordOffset[5] = {0, 1, 0, -1, 0};
    Board *board = GameManager::shareGameManager()->getMap();

    // 判断当前选手是否被卡死
    int pieceCount = getCurrentActor()->alivePieces.size();
    bool enableMove = false;

    for (int i = 0; i < pieceCount; i++)
    {
        Piece *piece = getCurrentActor()->alivePieces[i];
        Coord coord = piece->logicCoord;

        // 测试单步
        for (int j = 0; j < 4; j++)
        {
            Coord testCoord = Coord(coord.x + coordOffset[j], coord.y + coordOffset[j + 1]);
            if (board->getBoardTile(testCoord))
            {
                vector<Coord> coordVec;
                coordVec[0] = coord;
                coordVec[1] = testCoord;
                if (judgeCanMove(coordVec))
                {
                    enableMove = true;
                    break;
                }
            }
        }

        // 测试跃河
        if (!enableMove && PieceType::Lion == piece->getType() || PieceType::Tiger == piece->getType())
        {
            for (int j = 0; j < 4; j++)
            {
                Coord testCoord = Coord(coord.x + coordOffset[j] * 3, coord.y + coordOffset[j + 1] * 4);
                if (board->getBoardTile(testCoord))
                {
                    vector<Coord> coordVec;
                    coordVec[0] = coord;
                    coordVec[1] = testCoord;
                    if (judgeCanMove(coordVec))
                    {
                        enableMove = true;
                        break;
                    }
                }
            }
        }

        if (enableMove)
        {
            break;
        }
    }

    // 当前选手被卡死，移除所有棋子
    if (!enableMove)
    {
        getCurrentActor()->alivePieces.clear();
    }

    // 清除没有棋子的选手
    vector<Actor *>::iterator itA = m_aliveActors.begin();
    for (; m_aliveActors.end() != itA; itA++)
    {
        if (0 == (*itA)->alivePieces.size())
        {
            itA = m_aliveActors.erase(itA);
        }
    }

    // 如果只剩一名选手，游戏结束
    if (1 == m_aliveActors.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Judge::calculateGameResult()
{
    // ...
}
