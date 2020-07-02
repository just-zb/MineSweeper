#ifndef BLOCK_H
#define BLOCK_H
#include<vector>
//定义block类，包含炸弹数，红旗数，雷块的vector数组，时间等
class block
{
private:
    //MineNumber为炸弹数，Flag是红旗数
    int MineNumber,Flag;
    int curMineNumber;  // 当前已经出现的雷的数目
    //定义结构体为方块的状态,包含五种状态，为没有被挖，被挖，标记，已经出现的炸弹
    enum BlockState
    {
        UNDIGGED,
        DIGGED,
        MARKED,
        BOMB
    };
    //定义结构体，包含
    struct Block
    {
        BlockState State; // 当前状态
        int Value; // 数值，0到8代表它的周围有几个雷， 如果数值是-1表示他是一个雷
    };
    int mapRow; // 地图行数
    int mapCol; // 地图列数
    int timerSeconds; // 计时（秒）
    // 三种游戏状态
    enum GameState
    {
        PLAYING,
        OVER,
        WIN
    };

    // 游戏难度，有低级、中级、高级
    enum GameLevel
    {
        BASIC,
        MEDIUM,
        HARD
    };
    GameState gamestate; // 当前游戏状态
    GameLevel gamelevel; // 当前游戏难度
public:
    //构造函数
    block();
    std::vector<std::vector<Block>> GameMap; // 游戏地图
    //初始化游戏，接收游戏的行数，列数和炸弹数，默认游戏难度为简单
    void IniGame(int row = MapRow, int col = MapCol, int minenumber= MineNumber, GameLevel level = EASY);
    // 按当前参数重新开始游戏
    void restartGame();
    //检查游戏输赢
    void CheckGame();
    //标记方块的函数
    void MarkBlock(int x,int y);
    //点击函数
    void Click();
};


#endif // BLOCK_H
