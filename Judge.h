#pragma once

#include <vector>
#include "Coord.h"
#include "Actor.h"

using std::vector;


class Judge
{
public:
    Judge();
    virtual ~Judge();

    Actor *getCurrentActor();               // 取到当前选手
    void switchNextActor();                 // 切换到下一个选手
    bool checkOneActorOut(Actor *actor);    // 判断玩家是否出局
    bool checkPieceRule(Coord coord);       // 判断走棋是否合理
    bool checkOneGameOver();                // 判断是否游戏结束
    void calculateGameResult();             // 计算游戏结果
    int calculateActorScore(Actor *actor);  // 计算当前选手得分

private:
    vector<Actor *> m_allActors;            // 所有选手
    vector<Actor *> m_aliveActors;          // 没有出局的选手
    int             m_curIndex;             // 当前游戏选手下标索引
};
