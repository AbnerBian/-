#include<stdio.h>
#include<malloc.h>
//定义队列的节点
typedef struct Node{
    int data;
    Node *Pnext;
}Node,* Pnode;
//定义队列
typedef struct queue{
    Pnode rear;
    Pnode front;
}queue,* Pqueue;
//创建，推入，推出，遍历，清除
Pqueue create(){
    Pqueue queue=(Pqueue)malloc(sizeof(queue));
	queue->front=(Pnode)malloc(sizeof(Node));
    if(queue!=NULL)
    {
        printf("分配成功");
    }
	queue->rear=queue->front;
	queue->rear->Pnext=NULL;
	return queue;
}
int in_queue(Pqueue queue,int value){
	Pnode newnode=(Pnode)malloc(sizeof(Pnode));
	newnode->data=value;
	newnode->Pnext=NULL;
	queue->rear->Pnext=newnode;
	queue->rear=newnode;
	return 1;
}
int out_queue(Pqueue queue)
{
	if(queue->rear==queue->front){
		return false;
	}
	Pnode p=queue->front->Pnext;
	queue->front->Pnext=p->Pnext;


}
void traverse_queue(Pqueue queue)
{
	Pnode currentnode=queue->front->Pnext;
	while(currentnode)
	{
		printf("%d",currentnode->data);
		currentnode=currentnode->Pnext;
	}
}





int main()
{
	Pqueue queue= create();
	//printf("%d",queue);
	in_queue(queue,1);
	in_queue(queue,2);
	traverse_queue(queue);
	out_queue(queue);
	traverse_queue(queue);
	
	printf("\n");
	traverse_queue(queue);




    return 0;
}
