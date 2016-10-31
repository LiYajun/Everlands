//
//  GameManager.hpp
//  myGame
//
//  Created by andybain on 16/10/28.
//
//

#ifndef GameManager_hpp
#define GameManager_hpp

/*
 单局游戏管理者 (GameManager)
 行为：  创建(创建棋手，裁判，地图，展示类,控制器，记录类) 	create()
	初始化							init()
	销毁游戏角色						destroyAll()
	重置游戏角色  						resetAll()
	游戏逻辑                                                gameLogic()
 */
class Judge;
class Actor;
class Map;

class GameManager
{
public:
    static GameManager * shareGameManager(void);
    void destoryAll(void);
    void resetALl(void);
    void gameLogic(void);
private:
    static GameManager* gameShare;
    bool creaeteAll(void);
    bool init(void);
private:
    Judge *  judge;
    std::vector<Actor*> allActors;
    Map *    map;
    
};
#endif /* GameManager_hpp */
