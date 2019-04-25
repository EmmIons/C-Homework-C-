#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodelist{
    int f;          // 节点的频率
    char data;      // 节点代表的字符
    int lchild;     // 节点的左右子节点
    int rchild;
}tree;
void Initialization(int a[],char b[],int n,tree hfm[])
{
    int pot[100],i,m,mm,s=n,min,mmin,t;     // pot标记为加入树的节点 m,mm,min,mmin代表最小值和次小值及其节点的编号
    for (i=0;i<100;i++) pot[i]=0; //初始化
    for (i=0;i<n;i++) {hfm[i].data=b[i]; hfm[i].f=a[i]; pot[i]=1; hfm[i].lchild=-1; hfm[i].rchild=-1;}
    while (s<2*n-1) // 哈夫曼树为完全二叉树，其节点数为2n-1
    {
        min=1000;mmin=1001;
        for (i=0;i<s;i++)
        {
         if (pot[i]!=0&&hfm[i].f<mmin) {mmin=hfm[i].f; mm=i;}
         if (mmin<min) {t=min; min=mmin; mmin=t; t=mm; mm=m; m=t;}
        } // 找到最小值和次小值
        hfm[s].lchild=mm; hfm[s].rchild=m;
        hfm[s].f=min+mmin;
        pot[m]=0; pot[mm]=0; pot[s]=1; s++;    //进行操作
    }
    return;
}
void makeit(int a[],char c[][27],int q,tree hfm[]) //根据递归对已生成的哈夫曼树进行编码(哈夫曼树的遍历)
{
    int r;
    if (hfm[q].lchild>=0) {r=hfm[q].lchild; strcpy(c[r],c[q]); c[r][strlen(c[r])]='0'; makeit(a,c,r,hfm);}
    if (hfm[q].rchild>=0) {r=hfm[q].rchild; strcpy(c[r],c[q]); c[r][strlen(c[r])]='1'; makeit(a,c,r,hfm);}
}
char translate(char s[],tree hfm[],int q) //根据编码进行翻译
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
    tree hfm[100]; // 用结构体数组存储哈夫曼树的每一个结构体
    int n=27,a[100]={186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1},i,j,q; //初始字符的频度
    char b[27]={' ','A','B','C','D','E','F','G','H','I','G','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; //初始的字符
    char c[100][27]; // c用来存储每个节点的编码
    char s[100]={"HELLO WORLD"},secret[100][27]; //s为待翻译的字符串，secret用来存储s每个字符的编码
    Initialization(a,b,n,hfm); // 建立哈夫曼树
    q=2*n-2;
    for (i=0;i<q;i++)
    for (j=0;j<27;j++)
        c[i][j]='\0';
    makeit(a,c,q,hfm);  // 对每个节点进行编码
    for (i=0;i<strlen(s);i++)
    {
        if (s[i]==' ') strcpy(secret[i],c[0]);
        else strcpy(secret[i],c[s[i]-'A'+1]);
        puts(secret[i]);
    } // 对字符串的每个字符编码
    for (i=0;i<strlen(s);i++) printf("%c",translate(secret[i],hfm,q)); // 翻译编码并输出
}
