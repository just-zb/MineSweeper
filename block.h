#ifndef BLOCK_H
#define BLOCK_H
//定义block类，包含炸弹数，红旗数，雷块的vector数组，时间等
class block
{
private:
    //MineNumber为炸弹数，Flag是红旗数
    int MineNumber;
    int CurMineNumber;  // 当前已经出现的雷的数目
    // 三种游戏状态
    enum GameState
    {
        PLAYING,
        OVER,
        WIN
    };
    GameState gamestate; // 当前游戏状态
public:
    // 游戏地图,元素为0-8代表周围的雷数目而且未翻开，如果在该处有红旗就加50，如果已经被翻开就加100，如果该处为雷就为99，149是该处为雷而且有红旗
    int GameMap[14][18];
    //构造函数
    block();
    // 按当前参数重新开始游戏
    void restartGame();
    //检查游戏输赢函数
    void Win();
    //点击函数
    void Click();
};


#endif // BLOCK_H
