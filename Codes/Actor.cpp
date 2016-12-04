//
//  Actor.cpp
//  cocos2d-3.10-test
//
//  Created by li yajun on 16/10/25.
//
//

#include <vector>
#include "Coord.h"
#include "Board.h"
#include "BoardTile.h"
#include "GameManager.h"
#include <assert.h>

#include "Actor.h"

static unsigned int actorID = 1;
Actor * Actor::create(short color)
{
   
    Actor *pRet = new(std::nothrow) Actor();
    if (pRet && pRet->init(color))
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
bool Actor::init(short color)
{
    this->ID    = actorID;
    this->color = color;
    this->statu = no_choose_piece_statu;
    actorID++;
    
    typedef struct {
        Coord pos;
        PieceType type;
        int attack;
        int aStep;
    } pieceInfo;
    
    if(color == 0) {
        
        pieceInfo ary[8] ={
            {{0,0},Tiger,       8,  3} ,
            {{0,2},Elephant,    10, 1},
            {{1,1},Cat,         4,  1},
            {{2,2},Wolf,        6,  1},
            {{4,2},Leopard,     7,  1},
            {{5,1},Dog,         5,  1},
            {{6,0},Lion,        9,  3},
            {{6,2},Mouse,       3,  1}
        };
        
        for(int i=0; i<8; i++) {
            
            Piece * piece = Piece::create(color,
                                          ary[i].pos,
                                          ary[i].type,
                                          ary[i].attack,
                                          ary[i].aStep);
            allPieces.push_back(piece);
            alivePieces.push_back(piece);
        }
    }

    
    return true;
}
short Actor::getColor(void)
{
    return  color;
}
//走棋流程
void Actor::clickMapTile(BoardTile *mapTile)
{
    
    Piece* piece = mapTile->getPiece();
    Coord  coord = mapTile->getCoord();
    
    GameManager * share = GameManager::shareGameManager();
    if(this->statu == no_choose_piece_statu) //还没选过棋子
    {
        if(piece !=NULL)
        {
            if(piece->getColor() == this->color)
            {
             
                share->info->whatToDo = wantSelectPiece;
                share->info->coords.push_back(coord);
            }
            else {
                share->info->whatToDo = invaildOper;
                return;
            }
        }else
        {
            share->info->whatToDo = invaildOper;
            return;
        }
        
    }else if(this->statu == selected_one_piece_statu)//已经选中了棋子
    {
        if(piece != NULL)
        {
            if(piece->getColor() == this->color) //选择的自己的棋子
            {
                share->info->whatToDo = wantSelectPiece;
                share->info->coords.pop_back();
                share->info->coords.push_back(coord);
            }else                                //选择别人的棋子，吃棋子
            {
                share->info->whatToDo = wantEatOtherPiece;
                share->info->coords.push_back(coord);
            }
        }else   //移动操作
        {
            share->info->whatToDo = wantMove;
            share->info->coords.push_back(coord);
        }
    }else
    {
        share->info->whatToDo = invaildOper;
    }
    
}

void Actor::selectOnePiece(Piece* piece)
{
    if(this->selectedPieceRef != nullptr){
        
    }
    this->selectedPieceRef = piece;
}

void Actor::reMovePiece(Piece *piece)
{
    vector<Piece*>::iterator it = alivePieces.begin();
    for(;it!=alivePieces.end(); it++) {
        if(piece == *it){
            alivePieces.erase(it);
            break;
        }
    }
//    cout<<"error, can't find the piece in alivePieces";
//    exit(0);
}
void Actor::changePieceLogicCoord(Coord LogicCoord)
{
    if(selectedPieceRef  != nullptr) {
        selectedPieceRef->setLogicCoord( LogicCoord );
    }
    //return true;
}

void Actor::switchStatu( )
{
    ActorStatu oldStatu = statu;
    if(oldStatu == no_choose_piece_statu) {
         statu = selected_one_piece_statu;
    }else if(oldStatu == selected_one_piece_statu){
         statu = wait_for_statu;
    }else  {
        
    }
    
}
Actor::~Actor()
{
    //清除内部申请的内存
    vector<Piece*>::iterator it = allPieces.begin();
    for(;it<allPieces.end(); it++){
        delete (*it);
    }
}
