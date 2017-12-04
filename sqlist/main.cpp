#include <iostream>
#define INIT_SIZE 10
#define INCREMENT 5
#include <malloc.h>
typedef char elemType;
typedef char status;
using namespace std;
typedef struct{
elemType *elem;//存储空间基址
int length;//当前长度
int size;//当前分配的表长大小
}Sqlist;
status  InitList(Sqlist *L){
    L->elem=(elemType *)malloc(INIT_SIZE*sizeof(elemType));
    if(!L->elem)
    {
        return false;
    }
    L->length=0;
    L->size=INIT_SIZE;
    return true;
}
status DestroyList(Sqlist *L){
    free(L->elem);
    L->length=0;
    L->size=0;
    return true;
}
status ClearList(Sqlist *L)
{
    L->length=0;
    return true;
}
status isEmpty(const Sqlist L)//非指针类型其传址是否有影响
{
    if(0==L.length)
        {
        return true;

    }
    else
    {
        return false;
    }
}
status getLength(const Sqlist L)
{
    return L.length;
}
status getElem(const Sqlist L, int i, elemType *e)
{
    if(i<1||i>L.length)
    {
        return false;
    }
    *e=L.elem[i-1];
    return true;
}
status compare(elemType e1, elemType e2)
{
    if(e1==e2)
    {
        return 0;
    }
    else if(e1<e2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
status FindElem(const Sqlist L,elemType e)
{
    int i;
    for(i=0;i<L.length;i++){
        if(!compare(L.elem[i],e))
        {
            return i+1;
        }
    }
    if(i>=L.length)
    {
        return false;
    }
}

status  PreElem(const Sqlist L,elemType cur_e,elemType *pre_e)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(cur_e==L.elem[i])
        {
            if(i!=0)
            {
                *pre_e=L.elem[i-1];
            }
            else
            {
                return false;
            }
        }

    }
}

status NextElem(const Sqlist L, elemType cur_e, elemType *next_e)
{
    int i;
    for(i=0;i<L.length;i++){

        if(cur_e==L.elem[i])
        {
            if(i<L.length-1)
            {
                *next_e=L.elem[i+1];
                return true;
            }else
            {
                return false;
            }
            if(i>=L.length)
            {
                return false;
            }
        }
    }
}

status InsertElem(Sqlist *L,int i,elemType e)
{
    elemType *xnew;
    if(i<1||i>L->length +1)
    {
		
        return 0;
    }
    if(L->length >=L->size)
    {
        xnew=(elemType*)realloc(L->elem,(L->size+INCREMENT)*sizeof(elemType));
        if(!xnew)
        {
            return 0;
        }
        L->elem=xnew;
        L->size+=INCREMENT;
		
    }
    //插入的位置统一向后移动一位
    elemType *p=&L->elem[i-1];
    elemType *q=&L->elem[L->length -1];
    for(;q>=p;q--)
    {
        *(q+1)=*q;
    }
    *p=e;
    ++L->length;
	
    return 1;

}

status DeleteElem(Sqlist *L, int i, elemType *e)
{
    if(i<1||i>L->length)
    {
        return 0;
    }
    elemType* p=&L->elem[i-1];
    *e=*p;
    for(;p<&L->elem[L->length];p++)
    {
        *(p)=*(p+1);
    }

    --L->length;
    return 1;
}

/*
 *访问元素
 */
void  visit(elemType e)
{
    printf("%c\n",e);
}
/*
 * 遍历线性表
 */
status TraverseList(const Sqlist L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        visit(L.elem[i]);
    }
    return 1;
}

int main()
{

    //初始化线性表L
    Sqlist L;
    if(InitList(&L))
    {

        printf("初始化线性表成功\n");
    }



    InsertElem(&L,1,'a');
	InsertElem(&L,2,'b');
	InsertElem(&L,3,'c');
	InsertElem(&L,4,'d');
	InsertElem(&L,5,'e');

	printf("第一次的线性表\n");
    TraverseList(L);
	char a=1;
    elemType *e=&a;
 /*   for(int i=0;i<=0;i++)
    {
        char a=1;
        elemType *e=&a;
        DeleteElem(&L,1,e);
    }
*/
    printf("%d\n",L.length);

	printf("输出第三个元素：\n");
	visit(L.elem[2]);
	int location=FindElem(L,'a');
	printf("元素a的位置：%d\n",location);
	InsertElem(&L,4,'f');
	printf("第二次的线性表如下\n");
	TraverseList(L);
	DeleteElem(&L,3,e);
	printf("第三次的线性表如下：\n");
	TraverseList(L);
}