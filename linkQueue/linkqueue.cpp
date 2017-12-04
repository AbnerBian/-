#include "linkqueue.h"

linkQueue::linkQueue()
{
    count=0;
    rear=new queueNode();
    rear->next=nullptr;
    front=rear;
}
int linkQueue::size()
{
    return count;
}
int linkQueue::isEmpty()
{
    return count==0;
}
void linkQueue::inLinkQueue(int in_value)
{
    PNode newnode=new Node();
    newnode->value=in_value;
    newnode->next=rear->next;
    rear->next=newnode;
    rear=rear->next;
    count++;
}

int linkQueue::outLinkQueue()
{
    int out_value=front->next->value;
    count--;
    PNode delNode=front->next;
    front->next=front->next->next;
    delete delNode;
    return out_value;


}
linkQueue::~linkQueue()
{
    while(front->next!=nullptr)
    {
        PNode delNode=front->next;
        front->next=front->next->next;
        delete delNode;
    }
     front=nullptr;



}



