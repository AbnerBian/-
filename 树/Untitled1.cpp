#include <stdio.h>

//��������ʾ��
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
	//����������
	preOrder(root->lchild);
	//����������
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
