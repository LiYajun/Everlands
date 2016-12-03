//
//  Piece.cpp
//  cocos2d-3.10-test
//
//  Created by li yajun on 16/10/25.
//
//
#include <iostream>
#include <cocos2d.h>
#include "InputControl.h"
#include "GameManager.h"

#include "Piece.h"
/*
 unsigned int   ID;
 short       color;
 Coord       logicCoord;
 PieceType   type;
 int         attackValue;
 int         step;
 */
static unsigned int pieceID = 1;
Piece * Piece::create(short aColor,
                      Coord alogicCoord,
                      PieceType aType,
                      int aAttackValue,
                      int aStep )
{
    Piece *pRet = new(std::nothrow) Piece();
    if (pRet && pRet->init( aColor,
                            alogicCoord,
                            aType,
                            aAttackValue,
                            aStep))
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
bool Piece::init(short aColor,
                 Coord alogicCoord,
                 PieceType aType,
                 int aAttackValue,
                 int aStep)
{
    
    color = aColor;
    logicCoord = alogicCoord;
    type = aType;
    attackValue = aAttackValue;
    step = aStep;
    ID = pieceID;
    pieceID++;
    initSprite(aType, aColor);
    return  true;
}
/*
 Elephant,
 Lion,
 Tiger,
 Leopard,
 Wolf,
 Dog,
 Cat,
 Mouse
 */
void Piece::initSprite(PieceType type, short aColor)
{
    std::string str ="";
    if(type == Elephant)
        str = "elephant_.png";
    else if(type == Lion)
        str = "lion_.png";
    else if(type == Tiger)
        str = "tiger_.png";
    else if(type == Leopard)
        str = "leopard_.png";
    else if(type == Wolf)
        str = "wolf_.png";
    else if(type == Dog)
        str = "dog_.png";
    else if(type == Cat)
        str = "cat_.png";
    else if(type == Mouse)
        str = "mouse_.png";
    else
        str ="";
    if(aColor == 0)
        str.append("1");
    else
        str.append("2");
    showSp = Sprite::create(str);
}
void Piece::setLogicCoord(Coord aCoord)
{
    logicCoord = aCoord;
    InputControl * controller = GameManager::shareGameManager()->getInputControl();
    Vec2 pos = controller->convertCoordToVec2(logicCoord);
    showSp->setPosition(pos);
}

short Piece::getColor(void)
{
    return  this->color;
}
PieceType Piece::getType(void)
{
    return type;
}
