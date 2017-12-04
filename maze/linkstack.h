#ifndef LINKSTACK_H
#define LINKSTACK_H
#define elemType myPoint

typedef struct myPoint{
    int x;
    int y;
    int canMove;
}myPoint;

typedef struct Node{
    elemType value;
    Node* next;

}Node,*PNode;

class linkStack
{
public:
    linkStack();
    ~linkStack();
    bool isEmpty();
    int size();
    void push(elemType t);
    elemType pop();
    elemType top();
    elemType findElem(int i);//找到堆栈中第i个元素
    void printStack();
private:
    int count;
    PNode phead;



};

#endif // LINKSTACK_H
