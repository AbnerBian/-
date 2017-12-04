#include<stdio.h>
#include<malloc.h>
//�����ջ�Ľڵ�
typedef struct Node{
    int data;
    Node *Pnext;
}Node,* Pnode;
//�����ջ
typedef struct stack{
    Pnode top;
    Pnode bottom;
}Stack,* Pstack;
//���������룬�Ƴ������������
Pstack create(){
    Pstack stack=(Pstack)malloc(sizeof(stack));
	stack->top=(Pnode)malloc(sizeof(Node));
    if(stack!=NULL)
    {
        printf("����ɹ�");
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
