#include <QCoreApplication>
#include<QDebug>
#include"linkstack.h"
#include"maze.h"
int main(int argc, char *argv[])
{
    maze maze_rand;
    maze_rand.createMaze();
    maze_rand.printMaze();
    maze_rand.createMaze_info();
    maze_rand.printMaze_info();
    maze_rand.find_path();
    return 0;


}
