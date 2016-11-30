//
//  InputControl.hpp
//  myGame
//
//  Created by andybain on 2016/11/1.
//
//
#pragma once

#include "Coord.h"
#include <queue>
#include <cocos2d.h>
#include <iostream>
using namespace std;
class InputControl
{
public:
    static InputControl * create(void);
    bool  init(void);
    bool  addOneCoord(Coord coord);
    Coord getInputCoord(void);
    Coord convertTouchToCoord(cocos2d::Touch touchCoord);
private:
    queue<Coord> coordsQue;
};
