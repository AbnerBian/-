#include "linkstack.h"
#include<QDebug>
linkStack::linkStack()
{

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

void linkStack::push(elemType t)
{
    PNode newnode=new Node();
    newnode->value=t;
    newnode->next=phead->next;
    phead->next=newnode;
    count++;
}
elemType linkStack::pop()
{
    if(phead->next!=nullptr)
    {
        elemType pop_value;
        PNode pdel=new Node;
        pop_value=phead->next->value;
        pdel=phead->next;
        phead->next=phead->next->next;
        delete pdel;
        count--;
        return pop_value;
    }
    //堆栈空没写

}
elemType linkStack::top()
{
    if(phead->next!=nullptr)
    {
        elemType top_value;
        top_value=phead->next->value;
        return top_value;
    }
    //堆栈空没写
}

elemType linkStack::findElem(int i)
{//找不到第i个节点，返回10，否则返回具体的值
    int j=1;
    PNode need_node;
    need_node=phead->next;
    while(j<=i)
    {

        j++;
        if(need_node->next==nullptr)
        {
            exit(-1);
        }
        need_node=need_node->next;

    }
    return need_node->value;
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

}
void linkStack::printStack()
{
    for(int i=0;i<count;i++)
    {
        elemType x=findElem(i);
        printf("(%d,%d)",x.x,x.y);
    }
}
























