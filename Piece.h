//
//  Piece.hpp
//  cocos2d-3.10-test
//
//  Created by li yajun on 16/10/25.
//
//

#ifndef Piece_h
#define Piece_h

/*
 棋子    (Piece)
 属性：  阵营(颜色,区分所属玩家)(color)
	类型(老虎，狮子)        (type:PieceType)
	逻辑坐标               (logical coordinates)
	攻击力                 (attactValue)
    步长                   (step)
 */
#include "Coord.h"

typedef enum {
    Dog = 0,
    
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
    
    void setLogicCoord(Coord aCoord);
    
private:
    unsigned int   ID;
    short       color;
    Coord       logicCoord;
    PieceType   type;
    int         attackValue;
    int         step;
};
#endif /* Piece_h */
