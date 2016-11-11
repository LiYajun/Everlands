//
//  Piece.cpp
//  cocos2d-3.10-test
//
//  Created by li yajun on 16/10/25.
//
//

#include "Piece.h"
#include <iostream>
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
    attackValue = attackValue;
    step = aStep;
    ID = pieceID;
    pieceID++;
    return  true;
}
short Piece::getColor(void)
{
    return  this->color;
}

