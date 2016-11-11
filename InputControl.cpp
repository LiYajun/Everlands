//
//  InputControl.cpp
//  myGame
//
//  Created by andybain on 2016/11/1.
//
//

#include "InputControl.h"
#include "Coord.h"


bool InputControl::addOneCoord(Coord coord)
{
    size_t size = this->coordsQue.size();
    this->coordsQue.push(coord);
    if(this->coordsQue.size()-size == 1){
        return true;
    }else{
        return false;
    }
}
Coord InputControl::getInputCoord( )
{
    if(this->coordsQue.size()>0){
        Coord logicCoord = coordsQue.front();
        this->coordsQue.pop();
        return  logicCoord;
    }
 
    return CoordInvalid;
}
Coord InputControl::convertTouchToCoord(TouchCoord touchCoord)
{
    
   Coord coord;
   return coord;
}

