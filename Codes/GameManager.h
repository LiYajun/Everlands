//
//  GameManager.hpp
//  myGame
//
//  Created by andybain on 16/10/28.
//
//

#pragma once

#include <vector>
#include "Coord.h"
#include "cocos2d.h"

using namespace std;
using std::vector;
USING_NS_CC;
/*
 单局游戏管理者 (GameManager)
 行为：  创建(创建棋手，裁判，地图，展示类,控制器，记录类) 	create()
	初始化							init()
	销毁游戏角色						destroyAll()
	重置游戏角色                      resetAll()
	游戏逻辑                         gameLogic()
 */


class Board;
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
    static GameManager * shareGameManager();

    bool creaeteAll(Node* node = nullptr);

    Board *         getMap();
    InputControl *  getInputControl();
    bool gameLogic(void);
    Info *      info;
    AfterInfo *     afterInfo;
private:
    bool init( );
    void clearInfo(void);
    void destoryAll(void);
    void resetAll(void);
    
private:

 
    InputControl *      inputController;
    Judge *             judge;
    Board *               map;
    Node  *             layerNode;
  
    
};
