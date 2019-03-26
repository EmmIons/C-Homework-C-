#include <stdio.h>
#include <stdlib.h>
#define n 7
typedef struct Joseph
{
    int password;
    int number;
    struct Joseph* next;
} Loop;
void Joseph(Loop* p,int m,int x)
{
    Loop*q;
    int i;
    if(x==0) return 0;
    q=p;
    m%=x;
    if(m==0) m=x;
    for(i=1;i<=m;++i)
    {
        p=q;
        q=p->next;
    }
    p->next=q->next;
    i=q->password;
    printf("%d\n",q->number);
    free(q);
    Joseph(p,i,x-1);
}
Loop* creat(int m)
{
    Loop* head=(Loop*)malloc(sizeof(Loop));
    Loop *p,*e;
    if(!head) return 0;
    int a;
    printf("第1人的密码：");
    scanf("%d",&a);
    head->password=a;
    head->number=1;
    head->next=NULL;
    p=head;
    int x;
    for(int i=1;i<m;++i)
    {
        if(!(e=(Loop*)malloc(sizeof(Loop)))) return 0;

        printf("第%d人的密码：",i+1);
        scanf("%d",&x);
        e->number=i+1;
        e->password=x;
        p->next=e;
        p=e;
    }
    p->next=head;
    return p;
}
void main()
{
    int m;
    Loop*head=creat(n);
    printf("上限值：");
    scanf("%d",&m);
    Joseph(head,m,n);
}
