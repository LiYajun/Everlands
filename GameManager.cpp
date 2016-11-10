//
//  GameManager.cpp
//  myGame
//
//  Created by andybain on 16/10/28.
//
//

#include "GameManager.h"
#include "Actor.h"
#include "Judge.h"
#include "Map.h"
#include "InputControl.h"

GameManager *GameManager::shareGameManager(void)
{
    if(gameShare == nullptr)
    {
        gameShare = new (std::nothrow) GameManager();
        if (gameShare && gameShare->init())
        {
            return gameShare;
        }else
        {
            delete gameShare;
            gameShare = nullptr;
            return nullptr;
        }
    }else
    {
        return gameShare;
    }
    
}

bool GameManager::init(void)
{
    
    return true;
}
//创建所有选手， 地图， 棋子， 裁判
bool GameManager::creaeteAll(void)
{
    
    return true;
}
void GameManager::destoryAll(void)
{
    
}
void GameManager::resetALl(void)
{
    
}
//return false 表示游戏结束
bool GameManager::gameLogic(void)
{
   TouchCoord oneTouch = inputController->getUserTouchCoord();
    if(oneTouch.isNoTouch()==true)
    {
        return true;
    }
    //获取逻辑坐标
    Coord coord = inputController->convertTouchToCoord(oneTouch);
    //获取地图片元
    MapTile * oneMapTile = map->getMapTle(coord);
    //获取当前玩家
    Actor * currentActor = judge->getCurrentActor();
    //玩家点击处理
    currentActor->clickMapTile(oneMapTile);
    
    if(info->whatToDo == invaildOper)
    {
        
    }
    else
    {
        
    }
    if(afterInfo)
    {
        
    }
}



























