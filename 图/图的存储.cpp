#include <stdio.h>
#define MAX_VERTEX_NUM 20

typedef char VertexType;
typedef int Status;

typedef int QElemType;

//边表
typedef struct ArcNode
{
	int adjvex;			//该边所指顶点位置
	ArcNode *nextarc;	//指向下一条弧的指针
}ArcNode;

//顶点表
typedef struct VerNode
{
	VertexType data;//顶点信息
	ArcNode *firstarc;//指向第一条依附该顶点的弧
}VerNode,AdjList[MAX_VERTEX_NUM];

//图定义
typedef struct 
{
	AdjList vertices;
	int vexnum,arcnum;//图的当前顶点数和弧数
	//int kind;//图的种类标志
}ALGraph;


int visit[MAX_VERTEX_NUM];

//节点元素定位
int LocateVex(ALGraph *G,VertexType e)
{
	//找到return index,找不到return -1;
	int tmp=-1;int i;
	for(i=0;i<G->vexnum;i++)
	{
		if(G->vertices[i].data==e)
		{
			tmp=i;
			break;
		}
	}
	return tmp;
}

//邻接表头插
Status HeadInsertArc(ALGraph *G,int pos, int adjvex)
{
	//所谓头插，即为插入之结点始终为首选结点之后一个结点
	ArcNode *e;
	e=new ArcNode;
	e->adjvex=adjvex;
	e->nextarc=G->vertices[pos].firstarc;
	G->vertices[pos].firstarc=e;
	return 1;
}

//邻接表尾插
Status TailInsertArc(ALGraph *G,int pos,int adjvex)
{
	//所谓尾插，即在每一数组表中，最末尾位置插入
	ArcNode *e,*p;
	e=new ArcNode;
	e->adjvex=adjvex;
	e->nextarc=NULL;
	if(G->vertices[pos].firstarc==NULL)
	{
		G->vertices[pos].firstarc=e;
	}else{
		
		p=G->vertices[pos].firstarc;
		while(p->nextarc)
		{
			p=p->nextarc;
		}
		p->nextarc=e;
	}
	return 1;
}



//创建图
Status CreateGraph(ALGraph *G)
{
	int i;
	printf("Please input the vexnum and arcnum:");
	scanf("%d%d",&(G->vexnum),&(G->arcnum));
	getchar();
	for(i=0;i<G->vexnum;i++)
	{
		G->vertices[i].data=getchar();
		getchar();
		G->vertices[i].firstarc=NULL;
	}
	for(i=0;i<G->arcnum;i++)
	{
		char arc_s,arc_e;
		arc_s=getchar();
		getchar();
		arc_e=getchar();
		getchar();
		int v_s=LocateVex(G,arc_s);
		int v_e=LocateVex(G,arc_e);
		//headInsertArc(G,v_s,v_e);
		//headInsertArc(G,v_e,v_s);
		TailInsertArc(G,v_s,v_e);
		TailInsertArc(G,v_s,v_e);
	}


}


//.........................................................

/* //非递归    我更觉得这是广度优先搜索
Status DFS_Non_Recursion(ALGraph *G, int i)
{
    ArcNode *p;
    printf("%c ", G->vertices[i].data);
    visit[i] = 1;
    p = G->vertices[i].firstarc;

    while (p)
    {
        if (!visit[p->adjvex])
        {
            printf("%c ", G->vertices[p->adjvex].data);
            visit[p->adjvex] = 1;
        }
        p = p->nextarc;
    }
    return 1;
} 
//.........................................................

*/
//递归
Status DFS_Recursion(ALGraph *G, int i)
{
    ArcNode *p;
    printf("%c ", G->vertices[i].data);
    p = G->vertices[i].firstarc;
    visit[i] = 1;
    while (p)
    {
        if (!visit[p->adjvex])
        {
            DFS_Recursion(G, p->adjvex);
        }
        p = p->nextarc;
    }
    return 1;
}

//深度优先遍历
Status DFSTraverse(ALGraph *G)
{
    int i;
    for (i = 0; i < G->vexnum; i++)
        visit[i] = 0;
    for (i = 0; i < G->vexnum; i++)
        if (!visit[i]) DFS_Non_Recursion(G, i);
    printf("\n");
    return 1;
}



//广度优先遍历
Status BFSTraverse(ALGraph *G)
{
    int i; LinkQueue Q;
    InitQueue(&Q); //初始化队列
    for (int i = 0; i < G->vexnum; i++) //设置所为顶点为未访问
        visit[i] = 0;
    for (int i = 0; i < G->vexnum; ++i)
    {
        if (0 == visit[i]) //选取未访问的顶点
        {
            visit[i] = 1; //未访问,则(只)访问一次
            printf("%c ", G->vertices[i].data);
            EnQueue(&Q, i); //已访问则进队
            while (!QueueEmpty(&Q)) //队列不为空
            {
                DeQueue(&Q, &i); //出队
                ArcNode *p = G->vertices[i].firstarc; //指向下一个边表结点
                while (p)
                {
                    if (!visit[p->adjvex]) //未访问结点
                    {
                        visit[p->adjvex] = 1;
                        printf("%c ", G->vertices[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->nextarc; //下一个边表结点
                }
            }
        }
    }
    printf("\n");
    return 1;
}





int main(int argc, char *argv[])
{
	ALGraph *g=new ALGraph;
	CreateGraph(g);



}
