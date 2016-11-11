//
//  Actor.hpp
//  cocos2d-3.10-test
//
//  Created by li yajun on 16/10/25.
//
//

#ifndef Actor_h
#define Actor_h


#include <vector>
#include "Map.h"
#include "GameManager.h"


typedef enum {
    no_choose_piece_statu = 0,
    selected_one_piece_statu,
    moving_piece_statu,
    
}ActorStatu;
/*
 棋手(Actor)
 属性：
	编号                    (ID)
	阵营(颜色)  		(color)
	当前游戏状态		(statu : ActorStatu)
	拥有的棋牌（数组）	(allPieces   : vector)
	可活动的棋子(数组)      (alivePieces : vector)
	分数（外部属性）	(score)
	当前被选中的棋子        (selectedPieceRef)
 行为：
	对棋子选中		 clickPiece(pieceRef piece)
	移除棋子                 reMovePiece(pieceRef piece)
 改变棋子的逻辑坐标	 changePieceLogicCoord(logicCoord)
 */

class Actor
{
public:
    static Actor * createWith(int ID, short color);
    bool init(int ID, short color);
    ~Actor();

    short getColor(void);
    
    void clickMapTile(MapTile* mapTile);
    
    void selectOnePiece(Piece* piece);
    
    void reMovePiece(Piece* piece);
    
    void changePieceLogicCoord(Coord LogicCoord);
    
    void switchStatu( void );
private:
    static int actorID;
   
    int         ID;                                 //编号
    short       color;                              //阵营（颜色）
    ActorStatu  statu;                              //棋手状态
    std::vector<Actor*> allPieces;                  //拥有的棋子集合
    std::vector<Actor*> alivePieces;            //可活动的棋子集合
    unsigned    score;                              //当前得分
    Piece *     selectedPieceRef;                   //选中的棋子引用
    
};

#endif /* Actor_hpp */
