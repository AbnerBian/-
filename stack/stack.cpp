#include<stdio.h>
#include<malloc.h>
//定义堆栈的节点
typedef struct Node{
    int data;
    Node *Pnext;
}Node,* Pnode;
//定义堆栈
typedef struct stack{
    Pnode top;
    Pnode bottom;
}Stack,* Pstack;
//创建，推入，推出，遍历，清除
Pstack create(){
    Pstack stack=(Pstack)malloc(sizeof(stack));
	stack->top=(Pnode)malloc(sizeof(Node));
    if(stack!=NULL)
    {
        printf("分配成功");
    }
	stack->bottom=stack->top;
	stack->bottom->Pnext=NULL;
	return stack;
}
int push_stack(Pstack stack,int value){
	Pnode newnode=(Pnode)malloc(sizeof(Pnode));
	newnode->data=value;
	newnode->Pnext=stack->top;
	stack->top=newnode;
	return 1;
}
int pop_stack(Pstack stack)
{
	if(stack->top==stack->bottom){
		return false;
	}
	stack->top=stack->top->Pnext;
}
void traverse_stack(Pstack stack)
{
	Pnode currentnode=stack->top;
	while(currentnode!=stack->bottom)
	{
		printf("%d",currentnode->data);
		currentnode=currentnode->Pnext;
	}
}
int clear_stack(Pstack stack)
{
	if(stack->top==stack->bottom)
	{
		return 1;
	}
	Pnode p=stack->top;
	Pnode r=NULL;
	while(p!=stack->bottom)
	{
		r=p->Pnext;
		free(p);
		p=r;
	}
	stack->top=stack->bottom;

}






int main()
{
	Pstack stack= create();
	//printf("%d",stack);
	push_stack(stack,1);
	push_stack(stack,2);
	traverse_stack(stack);
	pop_stack(stack);
	traverse_stack(stack);
	clear_stack(stack);
	printf("\n");
	traverse_stack(stack);




    return 0;
}
