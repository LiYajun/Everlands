#pragma once

#include <vector>
#include "Coord.h"
#include "Actor.h"

using std::vector;


class Judge
{
public:
    virtual ~Judge();

    Judge *create();
    bool init();

    Actor *getCurrentActor();                       // 取到当前选手
    Actor *getActor(int color);                     // 获取指定颜色玩家
    void switchNextActor();                         // 切换到下一个选手
    bool judgeCanMove(vector<Coord> coords);        // 判断能否走棋
    bool judgeCanMoveAndEat(vector<Coord> coords);  // 判断能否进行吃子操作
    bool checkOneGameOver();                        // 判断是否游戏结束
    void calculateGameResult();                     // 计算游戏结果

private:
    vector<Actor *> m_allActors;            // 所有选手
    vector<Actor *> m_aliveActors;          // 没有出局的选手
    int             m_curIndex;             // 当前游戏选手下标索引
};
