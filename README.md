
3D RockPaperScissors game project. Player should change its pawn pressing "space" key to get point. 

All character types (rock,paper scissors) has own data table created by using UStruct. And their datas such as mesh,enemy type (if pawn is rock its enemy paper vice versa). 
I'm using UWorld::Spawn<T>(...) function and bind it to time menager in order to spawn enemies at certain times. 
