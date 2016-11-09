//（1）游戏初始化，选手状态 no_choose_piece_statu
//（2）用户点击操作触发
struct  Info
{
    int whatToDo;
    std::vector<Coord> coords;
};
struct  AfterInfo
{
    int scoreColor;
    int Score;
    int failColor;
    int isGameOver;
};
bool gamelogic()
{

	touch = getUserTouch();//从队列获取触摸
	logicCoord = convert(touch);
	mapTile = getMapTile(logicCoord);

	//info = judge.Start();
    info =	currentActor.clickMapTile(mapTile); //点击空地或者棋子
    
    if(info.invaildOper == YES)
    {
    	
    }else
    {
        if(info.wantSelectPiece == YES)
        {
        	 currentActor.selectPiece();	
        }
    	else if(info.wantEatOtherPiece == YES)
    	{
    		  canEat = judge.JudgeCanMoveAndEat();
    		  if(canEat == YES)
    		  {
    		  		currentActor.changePieceLogicCoord();
    		  		map.dealWithInfo();
    		  		AfteronePieceInfo = otherActor.removePiece();
    		  }
    	}
    	else if(info.wantMove == YES) // move
    	{
    		  canMove = judge.JudgeCanMove();
    		  if(canMove == YES)
    		  {
    		  		currentActor.changePieceLogicCoord();
    		  		AfteronePieceInfo = map.dealWithInfo();

    		  		 
    		  		//otherActor.removePiece();
    		  }
    	} 
    }	

    if(AfteronePieceInfo)
    { 
    	Judge.calculateActorScore(); //单步走棋
		Judge.checkOneActorOut();    
		if(Judge.checkOneGmaeOver()==YES)
		{
			Judge.calculateGameResult(); //游戏结束后的结果
			return NO;
		}
		
		Judge.switchNextActor();
    }
    return YES;

}