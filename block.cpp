#include"block.h"

#include<time.h>

#include<stdlib.h>



block::block()

{

    GameMap[14][18]={0};

    for(int i=0;i<14;i++)

    {

        for(int j=0;j<18;j++)

        {

            GameMap[i][j]=0;

        }

    }

    MineNumber=40;

    Flag=0;

    GameTime=0;//游戏时间的初始化

    gamestate=PLAYING;

    //随机布雷

    srand((unsigned int)time(0));

    int k=MineNumber;

    while(k>0){

        //生成随机数

        int row=rand()%14;

        int col=rand()%18;

        if(GameMap[row][col]!=99)

        {

            GameMap[row][col]=99;

            k--;

        }

    }

    //计算每个方格的周围的雷数，该方格为雷除外

    for(int i = 0; i < 14; i++)

    {

        for(int j = 0; j < 18; j++)

        {

            // y为行偏移量，x为列偏移量

            if(GameMap[i][j]!=99)

            {

                for(int y = -1; y <= 1; y++)

                {

                    for(int x = -1; x <= 1; x++)

                    {

                        if(i + y >= 0

                        && i + y < 14

                        && j + x >= 0

                        && j + x < 18

                        && GameMap[i + y][j + x]==99

                        && !(x == 0 && y == 0))

                        {

                            // 方块数字加1

                            GameMap[i][j]++;

                        }

                    }

                }

            }

        }

    }

}

void block::restartGame(){

    block mblock;//重新定义一个对象生成随机数，然后将现在的游戏地图设置成mblock的地图

    for(int i=0;i<14;i++){

        for(int j=0;j<18;j++){

            GameMap[i][j]=mblock.GameMap[i][j];

        }

    }

    gamestate=PLAYING;//游戏状态

    Flag=0;

    GameTime=0;

}

void block::Win()

{   int flag=0;

gamestate=PLAYING;

for(int i=0;i<14;i++)

{

    for(int j=0;j<18;j++)

    {

        if(GameMap[i][j]==199)

        {   gamestate=OVER;
            flag=1;
            break;}
    }
    if(flag==1)
        break;

}

int sum=0;

for(int i=0;i<14;i++)

{

    for(int j=0;j<18;j++)

    {

        if(GameMap[i][j]==99||GameMap[14][19]==149||(GameMap[i][j]<=108&&GameMap[i][j]>=100))

            sum++;

    }

}

if(sum==14*18)

    gamestate=WIN;

}

void block::FlagNumber(){

    Flag=0;

    for(int i=0;i<14;i++)

    {

        for(int j=0;j<18;j++)

        {

            if(GameMap[i][j]==149||(GameMap[i][j]<=58&&GameMap[i][j]>=50))

                Flag++;

        }

    }

}

void block::Click0(int i, int j){

    //如果点击到为0的方格，就采用递归方法显示空白方格和空白方格周围的带有数字的方格

    //TODO:实现鼠标的在地图【i】【j】处的点击

    //TODO如果点到空白的格子就递归显示方块



    //大体思路是，如果一个块是0就加100，对他周围每一个不等于100的块进行递归，

    //并让被重复运算的块的值始终在100~108

    //如果数字在1~8或99都翻开（加100），已经插了旗的不做操作

    if((GameMap[i][j]>=1 && GameMap[i][j]<8) || GameMap[i][j]==99)

    {

        GameMap[i][j]+=100;

    }
    if(GameMap[i][j]==0)

    {

        GameMap[i][j]+=100;

        if((i-1)>=0 && (j-1)>=0 && GameMap[i-1][j-1]!=100)

        {
            Click0(i-1,j-1);

            GameMap[i-1][j-1]+=100;

            if(GameMap[i-1][j-1]>=150) GameMap[i-1][j-1]-=100;

        }

        if((i-1)>=0 && GameMap[i-1][j]!=100)

        {

            Click0(i-1,j);

            GameMap[i-1][j]+=100;

            if(GameMap[i-1][j]>=150) GameMap[i-1][j]-=100;

        }

        if((i-1)>=0 && (j+1)<18 && GameMap[i-1][j+1]!=100)

        {
            Click0(i-1,j+1);

            GameMap[i-1][j+1]+=100;

            if(GameMap[i-1][j+1]>=150) GameMap[i-1][j+1]-=100;

        }

        if((j-1)>=0 && GameMap[i][j-1]!=100)

        {
            Click0(i,j-1);

            GameMap[i][j-1]+=100;

            if(GameMap[i][j-1]>=150) GameMap[i][j-1]-=100;

        }

        if((j+1)<18 && GameMap[i][j+1]!=100)

        {
            Click0(i,j+1);

            GameMap[i][j+1]+=100;

            if(GameMap[i][j+1]>=150) GameMap[i][j+1]-=100;

        }

        if((i+1)<14 && (j-1)>=0 && GameMap[i+1][j-1]!=100)

        {
            Click0(i+1,j-1);

            GameMap[i+1][j-1]+=100;

            if(GameMap[i+1][j-1]>=150) GameMap[i+1][j-1]-=100;

        }

        if((i+1)<14 && GameMap[i+1][j]!=100)

        {

            Click0(i+1,j);
          
            GameMap[i+1][j]+=100;

            if(GameMap[i+1][j]>=150) GameMap[i+1][j]-=100;

        }

        if((i+1)<14 && (j+1)<18 && GameMap[i+1][j+1]!=100)

        {
            Click0(i+1,j+1);

            GameMap[i+1][j+1]+=100;

            if(GameMap[i+1][j+1]>=150) GameMap[i+1][j+1]-=100;

        }

    }

}

//原来的变成Click0，现在能实现点击已翻开的部分，监测周围标旗的数和雷数是否相同，如果相同将周围的棋格翻开

void block::Click(int i, int j)

{

    if(GameMap[i][j]>=101 && GameMap[i][j]<=108)

    {

        int mine0 = 0;

        int flag0_true = 0;

        int flag0_false = 0;

        for(int x=-1;x<2;x++)

        {

            for(int y=-1;y<2;y++)

            {

                if(i+x>=0 && j+y>=0 && i+x<14 && j+y<18)

                {

                    if(GameMap[i+x][j+y]==99)

                        mine0++;

                    if(GameMap[i+x][j+y]==149)

                        flag0_true++;

                    if(GameMap[i+x][j+y]>=51 && GameMap[i+x][j+y]<=58)

                        flag0_false++;

                }

            }

        }

        if(mine0 == flag0_false)

        {

            for(int x=-1;x<2;x++)

            {

                for(int y=-1;y<2;y++)

                {

                    if(i+x>=0 && j+y>=0 && i+x<14 && j+y<18)

                    {

                        Click0(i+x,j+y);

                    }

                }

            }

        }

    }

    Click0(i,j);

}
//原来的变成Click0，现在能实现点击已翻开的部分，监测周围标旗的数和雷数是否相同，如果相同将周围的棋格翻开
void block::Click(int i, int j)
{
    if(GameMap[i][j]>=101 && GameMap[i][j]<=108)
    {
        int mine0 = 0;
        int flag0_true = 0;
        int flag0_false = 0;
        for(int x=-1;x<2;x++)
        {
            for(int y=-1;y<2;y++)
            {
                if(i+x>=0 && j+y>=0 && i+x<14 && j+y<18)
                {
                    if(GameMap[i+x][j+y]==99)
                        mine0++;
                    if(GameMap[i+x][j+y]==149)
                        flag0_true++;
                    if(GameMap[i+x][j+y]>=51 && GameMap[i+x][j+y]<=58)
                        flag0_false++;
                }
            }
        }
        if(mine0 == flag0_false)
        {
            for(int x=-1;x<2;x++)
            {
                for(int y=-1;y<2;y++)
                {
                    if(i+x>=0 && j+y>=0 && i+x<14 && j+y<18)
                    {
                        Click0(i+x,j+y);
                    }
                }
            }
        }
    }
    Click0(i,j);
}
