//
//  InputControl.cpp
//  myGame
//
//  Created by andybain on 2016/11/1.
//
//

#include "InputControl.h"

bool InputControl::addOneTouchCoord(TouchCoord coord)
{
    unsigned int size = this->touchQue.size();
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
   
    return TouchCoord();
}
