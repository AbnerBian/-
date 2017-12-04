#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef struct queueNode
{
    int value;
    queueNode *next;
}Node,*PNode;

class linkQueue
{
public:
    linkQueue();
    ~linkQueue();
    void inLinkQueue(int in_value);
    int outLinkQueue();
    int size();
    int isEmpty();



private:
    PNode front;
    PNode rear;
    int count;

};

#endif // LINKQUEUE_H
