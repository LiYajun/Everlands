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
class Coord;
struct TouchCoord
{
    float x,y;
    TouchCoord(){
        this->x=-1.0;
        this->y=-1.0;
    }
};
class InputControl
{
public:
    bool addOneTouchCoord(TouchCoord coord);
    TouchCoord getUserTouchCoord(void);
private:
    std::queue<TouchCoord> touchQue;
};
#endif /* InputControl_hpp */
