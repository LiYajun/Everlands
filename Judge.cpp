#include "Judge.h"
#include "GameManager.h"
#include "Piece.h"
#include <assert.h>


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

// bool Judge::checkOneActorOut(Actor *actor)
// {
//     for (vector<Actor *>::iterator it = m_aliveActors.begin(); m_aliveActors.end() != it; it++)
//     {
//         if (actor == *it)
//         {
//             // 待商定
//             if ()
//             {
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }
// 
//     assert(false, "error parameter.");
// }

bool Judge::judgeCanMove(vector<Coord> coords)
{
    // 需要两个同行同列的逻辑坐标
    if (2 != coords.size() || coords[0] == coords[1] || 
        (coords[0].x != coords[1].x && coords[0].y != coords[1].y))
    {
        return false;
    }

    // 起点要有棋子
    Piece *piece = GameManager::shareGameManager()->getMap()->getMapTile(coords[0])->getPiece();
    if (NULL == piece)
    {
        return false;
    }

    // 待处理
    switch (piece->getType())
    {
        // ...

        default:
            break;
    }
}

bool Judge::judgeCanMoveAndEat(vector<Coord> coords)
{
    Piece *piece1 = GameManager::shareGameManager()->getMap()->getMapTile(coords[0])->getPiece();
    Piece *piece2 = GameManager::shareGameManager()->getMap()->getMapTile(coords[1])->getPiece();

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

    // 不符合吃子比较（未实现）
    if (piece1 < piece2)
    {
        return false;
    }

    return true;
}

bool Judge::checkOneGameOver()
{
    static int i = 0;
    i++;

    if (10 == i)
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
    
}

// int Judge::calculateActorScore(Actor *actor)
// {
//     return 100;
// }
