#ifndef BLOCK_H

#define BLOCK_H

enum GameState

{

    PLAYING,

    OVER,

    WIN

};

//定义block类，包含炸弹数，红旗数，雷块的数组，时间等

class block

{

private:

    //MineNumber为炸弹数，Flag是红旗数

    int MineNumber;

    // 三种游戏状态

public:
    int GameMap[100][100];
  //  int **GameMap;
    int row;
    int col;
    int num_of_mine;
     int Flag;

     GameState gamestate; // 当前游戏状态

     int GameTime;//游戏进行时间

    // 游戏地图,元素为0-8代表周围的雷数目而且未翻开，如果在该处有红旗就加50，如果已经被翻开就加100，如果该处为雷就为99，149是该处为雷而且有红旗

 //   int GameMap[14][18];

    //构造函数

    block();
    block(int r,int c,int m);


    // 按当前参数重新开始游戏

    void restartGame(int r,int c,int m);

    //检查游戏输赢函数

    void Win(int r, int c, int m);

    //点击函数

    void Click(int i,int j,int r,int c);

    void Click0(int i, int j, int r, int c);

    void FlagNumber(int r, int c, int m);

};





#endif // BLOCK_H
