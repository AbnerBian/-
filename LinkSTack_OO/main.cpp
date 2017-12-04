#include <QCoreApplication>
#include<QDebug>
#include"linkstack.h"
int main(int argc, char *argv[])
{
    linkStack stack;
    stack.push(1);
    stack.push(2);
    qDebug()<<stack.top();
    qDebug()<<stack.size();
    qDebug()<<stack.pop();
    qDebug()<<stack.pop();
    return 0;


}
