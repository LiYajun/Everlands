//
//  Piece.cpp
//  cocos2d-3.10-test
//
//  Created by li yajun on 16/10/25.
//
//
#include <iostream>
#include <cocos2d.h>
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
void Piece::initSprite(PieceType type)
{
    std::string str ="";
    if(type == Elephant)
        str = "elephant.png";
    else if(type == Lion)
        str = "lion.png";
    else if(type == Tiger)
        str = "tiger.png";
    else if(type == Leopard)
        str = "leopard.png";
    else if(type == Wolf)
        str = "wolf.png";
    else if(type == Dog)
        str = "dog.png";
    else if(type == Cat)
        str = "cat.png";
    else if(type == Mouse)
        str = "mouse.png";
    else
        str ="";
    showSp = Sprite::create(str);
}
void Piece::setLogicCoord(Coord aCoord)
{
    logicCoord = aCoord;
   // showSp->setPosition(const cocos2d::Vec2 &pos)
}

short Piece::getColor(void)
{
    return  this->color;
}
PieceType Piece::getType(void)
{
    return type;
}
