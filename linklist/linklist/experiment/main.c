#include <stdio.h>
#include<malloc.h>
typedef struct student
{
    int data;
    int *f;
}student;
student* ma(student* L)
{
    L=(student*)malloc(40);
    return L;
}

int main(int argc, char *argv[])
{

    student *p;
    p=ma(p);
    //p->f=NULL;
    //p->f++;
    p->f;
    printf("%d",p->f);
    return 0;
}
