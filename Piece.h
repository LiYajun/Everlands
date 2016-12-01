//
//  Piece.hpp
//  cocos2d-3.10-test
//
//  Created by li yajun on 16/10/25.
//
//

#pragma once

#include "Coord.h"
#include <cocos2d.h>

/*
 棋子    (Piece)
 属性：  阵营(颜色,区分所属玩家)(color)
	类型(老虎，狮子)        (type:PieceType)
	逻辑坐标               (logical coordinates)
	攻击力                 (attactValue)
    步长                   (step)
 */


using namespace cocos2d;


typedef enum {
    None,
    Elephant,
    Lion,
    Tiger,
    Leopard,
    Wolf,
    Dog,
    Cat,
    Mouse
}PieceType;



class Piece
{
public:
    static Piece * create(short aColor,
                          Coord alogicCoord,
                          PieceType aType,
                          int aAttackValue,
                          int aStep);
    
    bool init(short aColor,
              Coord alogicCoord,
              PieceType aType,
              int aAttackValue,
              int aStep);
    
    short getColor(void);
    
    PieceType getType(void);
    
    void setLogicCoord(Coord aCoord);
    
    void  initSprite(PieceType type);
private:
    unsigned int   ID;
    short       color;
    Coord       logicCoord;
    PieceType   type;
    int         attackValue;
    int         step;
    Sprite *    showSp;
    friend class Judge;
};
 
