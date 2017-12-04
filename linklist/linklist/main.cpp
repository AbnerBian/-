#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int elemtype;
typedef int status;
typedef  struct LNode
{
    elemtype data;
    LNode *next;

}LNode,*LinkList;
//无表头的链表

//初始化线性表
LinkList InitLinkList(LinkList L)
{
    L=(LinkList)malloc(sizeof(LNode));
    if(!L)
    {
        exit(-2);
    }else{
        int y=sizeof(L);
        L->next=NULL;
        printf("初始化链表成功\n");
        return L;
    }
}
status DestroyLinkList(LinkList L)
{
    LinkList temp;
    while(L)
    {
        temp=L->next;
        free(L);
        L=temp;

    }
    return 1;
}
status insertLinkList(LinkList L,int i,elemtype e)
{
    //找到第i-1个位置
    int j=1;
    LinkList s;
    while(L&&j<i-1)
    {
        j++;
        L=L->next;
    }
    //判断是否合法
    if(!L||j>i-1)
    {
        return 0;
    }

    s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=L->next;
    L->next=s;
    LinkList k=L;
    return 1;
}
status DeleteLinkList(LinkList L,int i,elemtype *e)
{
    //找到第i-1个位置
    int j=0;
    LinkList S,K;
    while(S&&j<i-1)
    {
        j++;
        L=L->next;
    }
    if(!L||j>i-1)
    {
        return 0;
    }
    S=L->next;
    L->next=S->next;
    *e=S->data;
    free(S);
    return 1;
}
status compare(elemtype e1,elemtype e2)
{
    if(e1==e2)
    {
        return 0;
    }
    if(e1>e2)
    {
        return 1;
    }
    if(e1<e2)
    {
        return -1;
    }
}
status FindLinkList(LinkList L,elemtype e)
{
    int i=0;
    LinkList S=L->next;
    while(S)
    {

        if(compare(S->data,e))
        {
            printf("找到了");
            return i;
        }
        i++;
        S=S->next;

    }
    printf("找不到");
    return 0;
}
status display_LinkList(LinkList L)
{
    while(1){
    L=L->next;
    if(L)
    {
        printf("%d",L->data);
    }else{
            break;
        }
    }
}


int main(int argc, char *argv[])
{
    LinkList L;
    int i=0;
    L=InitLinkList(L);
    printf("请输入20个数字进入链表 ");
    while(i<2)
    {
        int a;
        scanf("%d",&a);
        i++;
        insertLinkList(L,i+1,a);

    }
    elemtype query;
    printf("请输入你要查询的数：\n");
    scanf("%d",&query);
    int k=FindLinkList(L,query);
	

    return 0;
}
