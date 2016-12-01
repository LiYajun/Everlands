//
//  InputControl.hpp
//  myGame
//
//  Created by andybain on 2016/11/1.
//
//
#pragma once



struct Touch
{
    float x, y;
};
using namespace std;
class InputControl
{
public:
    static InputControl * create(void);
    bool  init(void);
    bool  addOneCoord(Coord coord);
    Coord getInputCoord(void);
    Coord convertTouchToCoord(Touch touchCoord);
private:
    queue<Coord> coordsQue;
};
