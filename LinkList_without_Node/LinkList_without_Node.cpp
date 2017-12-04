#include <stdio.h>
#include<malloc.h>
#define k 4
typedef struct Node
{
	int data;
	Node *Pnext;

}Node,*PNode,*LinkList;

LinkList Init(LinkList S)
{
	S=(LinkList)malloc(sizeof(LinkList));
	S->Pnext=NULL;
	return S;
}




void input(LinkList S,int x)
{//输入一个数值，追加到链表尾端
	
	PNode x1=(PNode)malloc(sizeof(PNode));
	while(S->Pnext)
	{
		S=S->Pnext;
	}
	S->data=x;
	S->Pnext=x1;
	x1->data=NULL;
	x1->Pnext=NULL;
}
void findElem(LinkList S,int x)
{
	while(S!=NULL)
	{
		if(S->data==x)
		{
			printf("找到了\n");
			return;
		}
		S=S->Pnext;
	}
	printf("找不到\n");

}
void Insert(LinkList S,int pos,int value)
{
	//取出第pos-1的位置,设置可在1~max之间插入
	//最后一个元素不存在，所以需要增加限定条件
	int j=0;
	if(pos==0)
	{
		printf("只能在两个数之间插入\n");
		return;
	}
	while(j<pos-1)
	{
		S=S->Pnext;
		j++;
	}//可以在这里加入限定条件
	PNode newnode=(PNode)malloc(sizeof(PNode));
	newnode->data=value;
	newnode->Pnext=S->Pnext;
	S->Pnext=newnode;
}
LinkList Delete(LinkList S,int pos)
{
	int j=0;
	PNode prev=NULL;
	PNode phead=S;
	while(j<pos)
	{
		prev=S;
		S=S->Pnext;
		j++;
	}
	if(pos==0)
	{
		S=S->Pnext;
		return S;
	}else{
		prev->Pnext=S->Pnext;
		free(S);
		return phead;
	}
}
int compare(int a,int b)
{
	if(a==b)return 1;
	if(a!=b)return 0;
}
void drop_duplicate(LinkList S)
{
	
	PNode Phead=S;
	PNode prev=NULL;
	PNode current=S;
	while(S->Pnext!=NULL)
	{
		PNode t=S;
		prev=S;
		S=S->Pnext;
		
		while(S->Pnext!=NULL)
		{
			if(compare(t->data,S->data))
			{
				prev->Pnext=S->Pnext;
			    current=S;
			    S=S->Pnext;
			    free(current);
				
			}else{
			prev=S;
			S=S->Pnext;
			}
		}

	}

}
int check_even(int x)
{
	if(x%2==0)return 1;
	else {return 0;}
}



PNode DeleteEvenNode(LinkList S)
{
	PNode Phead=S;
	PNode current=S;
	PNode prev=NULL;
	while(S->Pnext!=NULL)
	{
		if(check_even(current->data))
		{
			if(prev==NULL)
			{
				S=S->Pnext;
				free(current);
				Phead=S;
				current=S;
			}else{
				prev->Pnext=current->Pnext;
				S=S->Pnext;
				free(current);
				current=S;
			}
			

		}else{
			prev=S;
			S=S->Pnext;
			current=S;
		}

	}
	return Phead;
}

void Traverse(LinkList S)
{
	printf("遍历结果：\n");
	//最后一个数不属于链表内容，不输出
	while(S->Pnext!=NULL)
	{
		printf("%d\n",S->data);
		S=S->Pnext;
	}
}
void circular_linklist(LinkList S)
{
	//链尾元素作为头结点
	PNode phead=S;
	while(S->Pnext!=NULL)
	{
		S=S->Pnext;

	}
	S->Pnext=phead;

}
void split_linklist(LinkList S,LinkList odd,LinkList even)
{
	int counter=0;
	while(S->Pnext!=NULL)
	{	
		if(counter%2==0)
		{	
			//为偶数时
			even->Pnext=S;
			even=even->Pnext;
			counter++;
			S=S->Pnext;
		}else{
			//为奇数
			odd->Pnext=S;
			odd=odd->Pnext;
			counter++;
			S=S->Pnext;
		
		}


	}
	odd->Pnext=NULL;
	even->Pnext=NULL;
}
void specialTraverse(LinkList S)
{
	S=S->Pnext;
	printf("遍历结果：\n");
	//最后一个数不属于链表内容，不输出
	while(S!=NULL)
	{
		printf("%d\n",S->data);
		S=S->Pnext;
	}
}


int main(int argc, char *argv[])
{
	int i=3;
	LinkList S=Init(S);
	//输入20个数
	while(i)
	{
		
		
		int value;
		printf("请输入第%d个数：",k-i);
		scanf("%d",&value);
		input(S,value);
		i--;
		
	}
	Traverse(S);
	findElem(S,100);
	Insert(S,1,5);
	Traverse(S);
	S=Delete(S,1);
	Traverse(S);
	drop_duplicate(S);
	Traverse(S);
	S=DeleteEvenNode(S);
	Traverse(S);
	//circular_linklist(S);
	//Traverse(S);链表首位相连，此时无限循环输出
	LinkList odd_linkList=Init(odd_linkList);
	LinkList even_linkList=Init(even_linkList);

	split_linklist( S,odd_linkList,even_linkList);

	specialTraverse(odd_linkList);
	specialTraverse(even_linkList);
	return 0;
}
