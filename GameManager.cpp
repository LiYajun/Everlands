//
//  GameManager.cpp
//  myGame
//
//  Created by andybain on 16/10/28.
//
//

#include "GameManager.hpp"
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
bool GameManager::gameLogic(void)
{
    
}



























