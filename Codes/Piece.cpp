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
        str = "Images/elephant_";
    else if(type == Lion)
        str = "Images/lion_";
    else if(type == Tiger)
        str = "Images/tiger_";
    else if(type == Leopard)
        str = "Images/leopard_";
    else if(type == Wolf)
        str = "Images/wolf_";
    else if(type == Dog)
        str = "Images/dog_";
    else if(type == Cat)
        str = "Images/cat_";
    else if(type == Mouse)
        str = "Images/mouse_";
    else
        str ="";
    if(aColor == 1)
        str.append("1.png");
    else
        str.append("2.png");
    showSp = Sprite::create(str);
    showSp->setScale(0.4);
    Size s = showSp->getContentSize();
    log("showSp contentSize %f, %f", s.width, s.height);
}

void Piece:: changeStatu(PieceStatu statu)
{
    if(showSp) {
        if(statu == Normal){
            showSp->removeAllChildren();
        }else if(statu == selected){
            auto label = Label::createWithTTF("selected", "fonts/Marker Felt.ttf", 32);
            Size s = showSp->getContentSize();
            label->setPosition( Vec2( s.width/2 , s.height/2));
            label->setColor(Color3B(0, 0, 0));
            showSp->addChild(label);
        }else if(statu == hidden)
        {
            showSp->setVisible(false);
        }
    }
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

int   Piece::getAttack(void)
{
    return  attackValue;
}
PieceType Piece::getType(void)
{
    return type;
}
