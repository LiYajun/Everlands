//
//  GameManager.cpp
//  myGame
//
//  Created by andybain on 16/10/28.
//
//
#include <vector>
#include <queue>
#include <stdlib.h>

#include "Coord.h"
#include "Actor.h"
#include "Judge.h"
#include "Board.h"
#include "InputControl.h"
#include "GameManager.h"

static GameManager* gameShare;
GameManager *GameManager::shareGameManager( )
{
    if(gameShare == nullptr)
    {
        gameShare = new (std::nothrow) GameManager();
        if (gameShare && gameShare->init( ))
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

bool GameManager::init( )
{
    do {
        info        = new Info();
        afterInfo   = new AfterInfo();
    }while(0);
    return true;
}

//创建所有选手， 地图， 棋子， 裁判
bool GameManager::creaeteAll(Node* node)
{
    if(node != nullptr) {
        layerNode       =   node;
        map             =   Board::create(layerNode,"");
        judge           =   Judge::create();
        inputController =   InputControl::create();
        
        return true;
    }
    
    return false;
}
void GameManager::destoryAll(void)
{
    
}
void GameManager::resetAll(void)
{
    
}
//return false 表示游戏结束
bool GameManager::gameLogic(void)
{

    //获取逻辑坐标
    Coord coord = inputController->getInputCoord();
    //判断逻辑坐标有效
    if(coord == CoordInvalid)
        return true;
    //获取地图片元
    BoardTile * oneMapTile = map->getBoardTile(coord);
    //获取当前玩家
    Actor * currentActor = judge->getCurrentActor();
    
    //玩家点击处理
    currentActor->clickMapTile(oneMapTile);
    
    if(info->whatToDo == invaildOper) {
        return true;
    }else{
        if(info->whatToDo == wantSelectPiece) {
            Piece * piece = oneMapTile->getPiece();
            currentActor->selectOnePiece(piece);
            currentActor->switchStatu();
        }
        else if(info->whatToDo == wantChangeSelect) {
            Piece * piece = oneMapTile->getPiece();
            currentActor->selectOnePiece(piece);
        }
        else if(info->whatToDo == wantEatOtherPiece) {
            bool canEat = judge->judgeCanMoveAndEat(info->coords);
            if(canEat == true) {
                currentActor->changePieceLogicCoord(coord);
                map->updateTiles(info->coords);
                //short otherColor   = oneMapTile->getColor();
                short  otherColor = 0;
                short  currColor = currentActor->getColor();
                otherColor = (currColor+1)%3+1;
                Actor * otherActor = judge->getActor(otherColor);
                Piece * piece = oneMapTile->getPiece();
                otherActor->reMovePiece(piece);
                currentActor->switchStatu();
                clearInfo();
                afterInfo->oneStepOver = true;
            }else {
                info->coords.pop_back();
            }
        }
        else if(info->whatToDo == wantMove){
            bool canMove   = judge->judgeCanMove(info->coords);
            if(canMove == true) {
                currentActor->changePieceLogicCoord(coord);
                map->updateTiles(info->coords);
                currentActor->switchStatu();
                clearInfo();
                afterInfo->oneStepOver = true;
            }else{
                info->coords.pop_back();
            }
        }
        
    }
    
   
        //judge->calculateActorScore(currentActor);
        //judge->checkOneActorOut(currentActor);
    if(afterInfo->oneStepOver == true) {

        if(judge->checkOneGameOver() == true) {
            judge->calculateGameResult();
            return false;
        }
        afterInfo->oneStepOver = false;
        judge->switchNextActor();
    }
    return true;
}
Board * GameManager::getMap()
{
    if(map == nullptr){
        map = Board::create(layerNode);
    }
    return  map;
}

InputControl * GameManager::getInputControl()
{
    if(inputController == nullptr) {
        inputController = InputControl::create();
    }
    return  inputController;
}
void GameManager::clearInfo()
{
    if(info!=NULL){
        info->whatToDo = invaildOper;
        info->coords.clear();
    }
}

























