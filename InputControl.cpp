//
//  InputControl.cpp
//  myGame
//
//  Created by andybain on 2016/11/1.
//
//

#include "InputControl.h"
//#inlcude "Coord.h"
class Coord;

bool InputControl::addOneTouchCoord(TouchCoord coord)
{
    size_t size = this->touchQue.size();
    this->touchQue.push(coord);
    if(this->touchQue.size()-size == 1){
        return true;
    }else{
        return false;
    }
}
TouchCoord InputControl::getUserTouchCoord(void)
{
    if(this->touchQue.size()>0){
        return this->touchQue.front();
    }
   TouchCoord noTouch;
    return noTouch;
}
Coord InputControl::convertTouchToCoord(TouchCoord touchCoord)
{

   Coord coord;
   return coord;
}

