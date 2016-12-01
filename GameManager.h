//
//  GameManager.hpp
//  myGame
//
//  Created by andybain on 16/10/28.
//
//

#pragma once



using namespace std;
/*
 单局游戏管理者 (GameManager)
 行为：  创建(创建棋手，裁判，地图，展示类,控制器，记录类) 	create()
	初始化							init()
	销毁游戏角色						destroyAll()
	重置游戏角色                      resetAll()
	游戏逻辑                         gameLogic()
 */


class Map;
class InputControl;
class Judge;

typedef enum
{
    invaildOper       =  0,
    wantSelectPiece   =  1,
    wantEatOtherPiece =  2,
    wantMove          =  3,
}infoType;

struct  Info
{
    infoType whatToDo;
    vector <Coord> coords;
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
    Map * getMap();
private:

    bool creaeteAll(void);
    bool init(void);
    void clearInfo(void);
private:

 
    InputControl *      inputController;
    Judge *             judge;
    Map *               map;
    //std::vector<Actor*> allActors;
  
    
};
 
