//
//  InputControl.cpp
//  myGame
//
//  Created by andybain on 2016/11/1.
//
//

#include "Coord.h"
#include <queue>
#include <iostream>

#include "InputControl.h"

InputControl* InputControl::create( )
{
    InputControl *pRet = new(std::nothrow) InputControl();
    if (pRet && pRet->init( ))
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

bool InputControl::init()
{
    do{
        deviceWidPixel = 1024*2.0;
        deviceHeiPixel = 768*2.0;
        pieceOffsetX   = 88.0;
        pieceOffsetY   = 116.0;
        pieceWid = 197.5/2.0;
        pieceHei = 197.5/2.0;
        coordMaxX      = 7;
        coordMaxY      = 9;
        
    }while(0);
    return true;
}
    
        
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
Vec2 InputControl::convertCoordToVec2(const Coord& coord)
{
    Vec2 pos =  Vec2(0.0, 0.0);
    pos.x = coord.x * pieceWid + pieceOffsetX;
    pos.y = coord.y * pieceHei + pieceOffsetY;
     
    return pos;
}
Coord InputControl::convertTouchToCoord(Touch * touchCoord)
{
    Vec2 pos = touchCoord->getLocation();
    int coordX = (pos.x - pieceOffsetX+pieceWid/2.0)/pieceWid;
    int coordY = (pos.y - pieceOffsetY+pieceHei/2.0)/pieceHei;
    if(coordX>=0 && coordY>=0 && coordX < coordMaxX && coordY < coordMaxY){
        Coord coord = Coord(coordX, coordY);
        return coord;
    }
   return CoordInvalid;
}


