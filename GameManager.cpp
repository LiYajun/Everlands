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

static GameManager* gameShare;
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
    //判断逻辑坐标有效
    //if(coord.isVaild() == false) return true;
    //获取地图片元
    MapTile * oneMapTile = map->getMapTile(coord);
    //获取当前玩家
    Actor * currentActor = nullptr;
    //currentActor = judge->getCurrentActor();
    
    //玩家点击处理
    currentActor->clickMapTile(oneMapTile);
    
    if(info->whatToDo == invaildOper) {
        return true;
    }else{
        if(info->whatToDo == wantSelectPiece) {
            Piece * piece = oneMapTile->getPiece();
            
            currentActor->selectOnePiece(piece);
            currentActor->switchStatu();
        }else if(info->whatToDo == wantEatOtherPiece) {
            bool canEat = true; //canEat = judge->JudageCanMoveAndEat();
            if(canEat == true) {
                currentActor->changePieceLogicCoord(coord);
                map->updateTiles(info->coords);
                short otherColor   = oneMapTile->getColor();
                Actor * otherActor = nullptr; // otherActor = judge->getActor(otherColor);
                Piece * piece = oneMapTile->getPiece();
                otherActor->reMovePiece(piece);
                currentActor->switchStatu();
                clearInfo();
            }else {
                
            }
        }else if(info->whatToDo == wantMove){
            bool canMove = true;  //canMove = judge->JudgeCanMove();
            if(canMove == true) {
                currentActor->changePieceLogicCoord(coord);
                map->updateTiles(info->coords);
                currentActor->switchStatu();
                clearInfo();
            }else{
                
            }
        }
        
    }
    
    if(afterInfo)
    {
        judge->calculateActorScore(currentActor);
        judge->checkOneActorOut(currentActor);
        if(judge->checkOneGameOver() == true)
        {
            judge->calculateGameResult();
            return false;
        }
        judge->switchNextActor();
        
    }
    
    return true;
}

void GameManager::clearInfo()
{
    if(info){
        info->whatToDo = invaildOper;
        info->coords.clear();
    }
}

























