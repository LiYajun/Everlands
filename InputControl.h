//
//  InputControl.hpp
//  myGame
//
//  Created by andybain on 2016/11/1.
//
//

#ifndef InputControl_h
#define InputControl_h

#include <queue>
#include "Coord.h"
using namespace std;

struct TouchCoord
{
    float x,y;
    TouchCoord(){
        this->x=-1.0;
        this->y=-1.0;
    }
    bool isNoTouch(){
        if(this->x<0||this->y<0)
        {
            return true;
        }else
        {
            return false;
        }
    }
};
class InputControl
{
public:
    static InputControl * create(void);
    bool  init(void);
    bool  addOneCoord(Coord coord);
    Coord getInputCoord(void);
    Coord convertTouchToCoord(TouchCoord touchCoord);
private:
    queue<Coord> coordsQue;
};
#endif /* InputControl_hpp */
