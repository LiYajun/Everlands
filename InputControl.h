//
//  InputControl.hpp
//  myGame
//
//  Created by andybain on 2016/11/1.
//
//
#pragma once


#include <cocos2d.h>
using namespace cocos2d;
using namespace std;
class InputControl
{
public:
    static InputControl * create(void);
    bool  init(void);
    bool  addOneCoord(Coord coord);
    Coord getInputCoord(void);
    Coord convertTouchToCoord(Touch * touchCoord);
    Vec2  convertCoordToVec2(const Coord& coord);
private:
    float deviceWidPixel;
    float deviceHeiPixel;
    float pieceWid;
    float piecehei;
    float pieceOffsetX, pieceOffsetY;
    int   coordMaxX,  coordMaxY;
    queue<Coord> coordsQue;
};
