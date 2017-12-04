#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef struct Node{
    int value;
    Node* next;

}Node,*PNode;

class linkStack
{
public:
    linkStack();
    ~linkStack();
    bool isEmpty();
    int size();
    void push(int t);
    int pop();
    int top();
private:
    int count;
    PNode phead;



};

#endif // LINKSTACK_H
