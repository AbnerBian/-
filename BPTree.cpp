#include <stdio.h>


//˫������
typedef struct BPNTode
{
	int data;
	int parentPosition;//ָ��˫�׵�ָ��//�����±�
	char LRTag;
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100];//�ڵ�֮���Ƿ�ɢ�ģ���Ҫ�ѽڵ�洢��������
	int num_node;  //�ڵ���Ŀ
	int root;//���ڵ��λ��//ע�����洢���Ǹ��׽ڵ���������±�
}BPTree;
//�����ݿ��еĽṹ��ԭ���ڴ�����




int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
