#include <stdio.h>


//双亲链表
typedef struct BPNTode
{
	int data;
	int parentPosition;//指向双亲的指针//数组下标
	char LRTag;
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100];//节点之间是分散的，需要把节点存储到数组里
	int num_node;  //节点数目
	int root;//根节点的位置//注意此域存储的是父亲节点在数组的下标
}BPTree;
//将数据库中的结构还原到内存中来




int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
