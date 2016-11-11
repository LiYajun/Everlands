//
//  GameManager.hpp
//  myGame
//
//  Created by andybain on 16/10/28.
//
//

#ifndef GameManager_h
#define GameManager_h

#include <vector>
#include <queue>
#include "Map.h"
/*
 单局游戏管理者 (GameManager)
 行为：  创建(创建棋手，裁判，地图，展示类,控制器，记录类) 	create()
	初始化							init()
	销毁游戏角色						destroyAll()
	重置游戏角色                      resetAll()
	游戏逻辑                         gameLogic()
 */
class Judge;
class Actor;
class InputControl;


#define invaildOper         0
#define wantSelectPiece     1
#define wantEatOtherPiece   2
#define wantMove            3

struct  Info
{
    int whatToDo;
    std::vector <Coord> coords;
};
struct  AfterInfo
{
    bool oneStepOver; //一步棋下棋结束
    int scoreColor;
    int Score;
    int failColor;
    int isGameOver;
};


 
class GameManager
{
public:
    static GameManager * shareGameManager(void);
    void destoryAll(void);
    void resetALl(void);
    bool gameLogic(void);
    Info *               info;
    AfterInfo *          afterInfo;
private:

    bool creaeteAll(void);
    bool init(void);
    void clearInfo(void);
private:

    Judge *             judge;
    InputControl *      inputController;
    std::vector<Actor*> allActors;
    Map *               map;
    
};
#endif /* GameManager_hpp */
