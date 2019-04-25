#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodelist{
    int f;          // �ڵ��Ƶ��
    char data;      // �ڵ������ַ�
    int lchild;     // �ڵ�������ӽڵ�
    int rchild;
}tree;
void Initialization(int a[],char b[],int n,tree hfm[])
{
    int pot[100],i,m,mm,s=n,min,mmin,t;     // pot���Ϊ�������Ľڵ� m,mm,min,mmin������Сֵ�ʹ�Сֵ����ڵ�ı��
    for (i=0;i<100;i++) pot[i]=0; //��ʼ��
    for (i=0;i<n;i++) {hfm[i].data=b[i]; hfm[i].f=a[i]; pot[i]=1; hfm[i].lchild=-1; hfm[i].rchild=-1;}
    while (s<2*n-1) // ��������Ϊ��ȫ����������ڵ���Ϊ2n-1
    {
        min=1000;mmin=1001;
        for (i=0;i<s;i++)
        {
         if (pot[i]!=0&&hfm[i].f<mmin) {mmin=hfm[i].f; mm=i;}
         if (mmin<min) {t=min; min=mmin; mmin=t; t=mm; mm=m; m=t;}
        } // �ҵ���Сֵ�ʹ�Сֵ
        hfm[s].lchild=mm; hfm[s].rchild=m;
        hfm[s].f=min+mmin;
        pot[m]=0; pot[mm]=0; pot[s]=1; s++;    //���в���
    }
    return;
}
void makeit(int a[],char c[][27],int q,tree hfm[]) //���ݵݹ�������ɵĹ����������б���(���������ı���)
{
    int r;
    if (hfm[q].lchild>=0) {r=hfm[q].lchild; strcpy(c[r],c[q]); c[r][strlen(c[r])]='0'; makeit(a,c,r,hfm);}
    if (hfm[q].rchild>=0) {r=hfm[q].rchild; strcpy(c[r],c[q]); c[r][strlen(c[r])]='1'; makeit(a,c,r,hfm);}
}
char translate(char s[],tree hfm[],int q) //���ݱ�����з���
{
    int i=0,j=q;
    while (i<strlen(s))
    {
        if (s[i]=='0') j=hfm[j].lchild;
        else j=hfm[j].rchild;
        i++;
    }
    return hfm[j].data;
}
int main()
{
    tree hfm[100]; // �ýṹ������洢����������ÿһ���ṹ��
    int n=27,a[100]={186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1},i,j,q; //��ʼ�ַ���Ƶ��
    char b[27]={' ','A','B','C','D','E','F','G','H','I','G','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; //��ʼ���ַ�
    char c[100][27]; // c�����洢ÿ���ڵ�ı���
    char s[100]={"HELLO WORLD"},secret[100][27]; //sΪ��������ַ�����secret�����洢sÿ���ַ��ı���
    Initialization(a,b,n,hfm); // ������������
    q=2*n-2;
    for (i=0;i<q;i++)
    for (j=0;j<27;j++)
        c[i][j]='\0';
    makeit(a,c,q,hfm);  // ��ÿ���ڵ���б���
    for (i=0;i<strlen(s);i++)
    {
        if (s[i]==' ') strcpy(secret[i],c[0]);
        else strcpy(secret[i],c[s[i]-'A'+1]);
        puts(secret[i]);
    } // ���ַ�����ÿ���ַ�����
    for (i=0;i<strlen(s);i++) printf("%c",translate(secret[i],hfm,q)); // ������벢���
}
