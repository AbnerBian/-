#ifndef MAZE_H
#define MAZE_H
#include"linkstack.h"
#include<stdlib.h>
#include<stdio.h>
#define M_ 3
#define N_ 3

class maze
{
public:
    maze();
    void createMaze();
    void printMaze();
    int printPath();
    void createMaze_info();

    void find_path();//x0,y0为出发的初始化位置，maze为迷宫数组，
    bool canPass(myPoint point);
    myPoint nextPos(myPoint curPos,int direction );//direction表示方向，1,2,3,4,1:上2:下3:左4:右
    void printMaze_info();
private:
    int maze_created[M_][N_];
    myPoint maze_info[M_][N_];
    myPoint curPos;
    myPoint startPos;
    myPoint endPos;
    linkStack pathStorage;
};

#endif // MAZE_H
