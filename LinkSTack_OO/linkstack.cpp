#include "linkstack.h"
#include<QDebug>
linkStack::linkStack()
{
    qDebug()<<"初始化堆栈成功";
    phead=new Node();
    phead->next=nullptr;
    count=0;
}
bool linkStack::isEmpty()
{
    return count==0;
}
int linkStack::size()
{
    return count;
}

void linkStack::push(int t)
{
    PNode newnode=new Node();
    newnode->value=t;
    newnode->next=phead->next;
    phead->next=newnode;
    count++;
}
int linkStack::pop()
{
    if(phead->next!=nullptr)
    {
        int pop_value;
        PNode pdel=new Node;
        pop_value=phead->next->value;
        pdel=phead->next;
        phead->next=phead->next->next;
        delete pdel;
        count--;
        return pop_value;
    }else{
        qDebug()<<"当前堆栈已空，不可弹出值";
    }

}
int linkStack::top()
{
    if(phead->next!=nullptr)
    {
        int top_value;
        top_value=phead->next->value;
        return top_value;
    }else{
        qDebug()<<"当前堆栈已空";
    }
}
linkStack::~linkStack()
{
    while(phead->next!=nullptr)
    {
        PNode pnode=phead->next;
        phead->next=phead->next->next;
        delete pnode;
    }
     phead=nullptr;
    qDebug()<<"堆栈清除成功";
}
























