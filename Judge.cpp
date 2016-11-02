#include "Judge.h"


Judge::Judge()
{

}

Judge::~Judge()
{
    
}

void Judge::switchNextActor()
{
    m_curIndex = (m_curIndex + 1) % m_aliveActors.size();
}

bool Judge::checkOneActorOut(Actor *actor)
{
    return false;
}

bool Judge::checkPieceRule(Coord coord)
{
    static int i = 0;
    i++;

    if (0 == i % 3)
    {
        return false;
    }
    else
    {
        return true;
    }
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

int Judge::calculateActorScore(Actor *actor)
{
    return 100;
}
