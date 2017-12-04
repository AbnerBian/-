#include "maze.h"
#include<QDebug>
maze::maze()
{
    startPos.x=0;
    startPos.y=0;
    endPos.x=M_-1;
    endPos.y=N_-1;
}

void maze::createMaze()
{
    srand((unsigned )(time(NULL)));
    for(int i=0;i<M_;i++)
    {
        for(int j=0;j<N_;j++)
        {

            maze_created[i][j]=rand()%2;
        }
    }
    maze_created[0][0]=0;
    maze_created[M_-1][N_-1]=0;
}

void maze::printMaze()
{
    for(int i=0;i<M_;i++)
    {
        for(int j=0;j<N_;j++)
        {
            printf("%d",maze_created[i][j]);
        }
        printf("\n");

    }

}


//direction表示方向，1,2,3,4,1:上2:下3:左4:右
void maze::find_path()
{
    curPos=maze_info[0][0];
    pathStorage.push(curPos);
    while(true)
    {
        if((curPos.x==endPos.x)&&(curPos.y==endPos.y))
        {
            break;
        }
        if(canPass(maze_info[curPos.x][curPos.y+1])&&(curPos.x<M_)&&(curPos.y+1<N_))
        {
            maze_info[curPos.x][curPos.y+1].canMove=1;//走过的路标记为false
            pathStorage.push(maze_info[curPos.x][curPos.y+1]);
            curPos=maze_info[curPos.x][curPos.y+1];
            continue;
        }
        if(canPass(maze_info[curPos.x][curPos.y-1])&&(curPos.x<M_)&&(curPos.y-1>0))
        {
            maze_info[curPos.x][curPos.y-1].canMove=1;//走过的路标记为false
            pathStorage.push(maze_info[curPos.x][curPos.y-1]);
            curPos=maze_info[curPos.x][curPos.y-1];
            continue;
        }
        if(canPass(maze_info[curPos.x-1][curPos.y])&&(curPos.x-1>0)&&(curPos.y<N_))
        {
            maze_info[curPos.x-1][curPos.y].canMove=1;//走过的路标记为false
            pathStorage.push(maze_info[curPos.x-1][curPos.y]);
            curPos=maze_info[curPos.x-1][curPos.y];
            continue;
        }
        if(canPass(maze_info[curPos.x+1][curPos.y])&&(curPos.x+1<M_)&&(curPos.y<N_))
        {
            maze_info[curPos.x+1][curPos.y].canMove=1;//走过的路标记为1
            pathStorage.push(maze_info[curPos.x+1][curPos.y]);
            curPos=maze_info[curPos.x+1][curPos.y];
            continue;
        }
        if(pathStorage.size()==0)
        {
            printf("没有路");
            return;
        }
        pathStorage.pop();
        curPos=pathStorage.top();
    }
    pathStorage.printStack();
    printf("%d",pathStorage.size());
}

bool maze::canPass(myPoint point)
{
    if(point.canMove==0)
    {
        return true;
    }
    else{
        return false;
    }
}



void maze::createMaze_info()
{
    for(int i=0;i<M_;i++)
    {
        for(int j=0;j<N_;j++)
        {
            maze_info[i][j].x=i;
            maze_info[i][j].y=j;
            maze_info[i][j].canMove=maze_created[i][j];
        }

    }
}
void maze::printMaze_info()
{
    for(int i=0;i<M_;i++)
    {
        for(int j=0;j<N_;j++)
        {
           printf("%d",maze_info[i][j].canMove) ;
        }
        printf("\n");
    }
}









