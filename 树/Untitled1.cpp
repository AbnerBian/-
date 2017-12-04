#include <stdio.h>

//二叉链表示法
typedef struct BiTNode
{
	int data;
	BiTNode *lchild,*rchild;
}BiTNode;

void preOrder(BiTNode *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d",root->data);
	//遍历左子树
	preOrder(root->lchild);
	//遍历右子树
	preOrder(root->rchild);

}

int main(int argc, char *argv[])
{
	BiTNode a;
	BiTNode b;
	a.data=1;
	a.lchild=&b;
	
	return 0;
}
