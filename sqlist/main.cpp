#include <iostream>
#define INIT_SIZE 10
#define INCREMENT 5
#include <malloc.h>
typedef char elemType;
typedef char status;
using namespace std;
typedef struct{
elemType *elem;//�洢�ռ��ַ
int length;//��ǰ����
int size;//��ǰ����ı���С
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
status isEmpty(const Sqlist L)//��ָ�������䴫ַ�Ƿ���Ӱ��
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
    //�����λ��ͳһ����ƶ�һλ
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
 *����Ԫ��
 */
void  visit(elemType e)
{
    printf("%c\n",e);
}
/*
 * �������Ա�
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

    //��ʼ�����Ա�L
    Sqlist L;
    if(InitList(&L))
    {

        printf("��ʼ�����Ա�ɹ�\n");
    }



    InsertElem(&L,1,'a');
	InsertElem(&L,2,'b');
	InsertElem(&L,3,'c');
	InsertElem(&L,4,'d');
	InsertElem(&L,5,'e');

	printf("��һ�ε����Ա�\n");
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

	printf("���������Ԫ�أ�\n");
	visit(L.elem[2]);
	int location=FindElem(L,'a');
	printf("Ԫ��a��λ�ã�%d\n",location);
	InsertElem(&L,4,'f');
	printf("�ڶ��ε����Ա�����\n");
	TraverseList(L);
	DeleteElem(&L,3,e);
	printf("�����ε����Ա����£�\n");
	TraverseList(L);
}