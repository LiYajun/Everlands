#include "Judge.h"


Judge::Judge()
{

}

Judge::~Judge()
{
    
}

Actor *Judge::getCurrentActor()
{
    Actor *result = NULL;

    if (0 <= m_curIndex && m_aliveActors.size() > m_curIndex)
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

bool Judge::checkOneActorOut(Actor *actor)
{
    return false;
}

bool Judge::judageCanMove(vector<Coord> coords)
{
    return true;
}

bool Judge::judageCanMoveAndEat(vector<Coord> coords)
{
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

int Judge::calculateActorScore(Actor *actor)
{
    return 100;
}
