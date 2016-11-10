//
//  Actor.cpp
//  cocos2d-3.10-test
//
//  Created by li yajun on 16/10/25.
//
//

#include "Actor.h"
#include "Piece.h"
#include "MapTile.h"
#include <assert.h>

int Actor::actorID;
Actor * Actor::createWith(int ID, short color)
{
   
    Actor *pRet = new(std::nothrow) Actor();
    if (pRet && pRet->init(ID, color))
    {
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}
bool Actor::init(int ID, short color)
{
   
    this->ID    = actorID;
    this->color = color;
    actorID++;
    return true;
}
//走棋流程
void Actor::clickMapTile(MapTile *mapTile)
{
    assert(mapTile);
    Piece* piece = mapTile->getPiece();
    Coord  coord = mapTile->getCoord();
    if(this->statu == no_choose_piece_statu) //还没选过棋子
    {
        if(piece !=NULL)
        {
            if(piece->getColor() == this->color)
            {
                this->selectedPieceRef = piece;
                this->switchStatu(this->statu);
            }
            else
                return;
        }else
        {
            return;
        }
        
    }else if(this->statu == selected_one_piece_statu)//已经选中了棋子
    {
        if(piece != NULL)
        {
            if(piece->getColor() == this->color) //选择的自己的棋子
            {
                if(this->selectedPieceRef != piece)
                    this->selectedPieceRef = piece;
            }else                                //选择别人的棋子，吃棋子
            {
                //判断能不能吃掉
                /*
                    canMove = Map->judgeMove(currentCoord, coord);
                    if canMove == YES
                    {
                        canEat = Map->judgeEat(currentCoord, coord);
                        if canEat == YES
                        {
                            this->changePieceLogicCoord(coord);
                            map->dealWithInfo(currentCoord, coord);
                        }else
                            return;
                    }else
                        return
                 */
                
                //this->switchStatu(this->statu);
            }
        }else   //移动操作
        {
            //判断能不能移动到空地去
            /*
               canMove = Map->judgeMove(currentCoord, coord);
               if canMove==YES
                this->changePieceLogicCoord(coord);
                map->dealWithInfo(currentCoord, coord);
               else
                return
            */
            
        }
    }
    
}

bool Actor::reMovePiece(Piece *piece)
{
    
    return true;
}
bool Actor::changePieceLogicCoord(Coord LogicCoord)
{
    return true;
}

void Actor::switchStatu(ActorStatu oldStatu)
{
    if(oldStatu == no_choose_piece_statu)
    {
        
        this->statu = selected_one_piece_statu;
        
    }else if(oldStatu == selected_one_piece_statu)
    {
        this->statu = moving_piece_statu;
    }else
    {
        
    }
    
}
Actor::~Actor()
{
    //清除内部申请的内存
}
