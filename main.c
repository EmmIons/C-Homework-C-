#include <stdio.h>
#include <stdlib.h>

void Push(int a[],int e)
{
    a[0]++;
    a[a[0]]=e;
}
void equ(int a[],int b[])
{
    for(int i=0;i<=a[0];i++) b[i]=a[i];
}

void arrange(int out[],int tem[],int i,int n)
{
    int out1[100],tem1[100];
    if(i>n)
    {
        for(int a=1;a<=out[0];a++) printf("%d ",out[a]);
        for(int j=tem[0];j>0;j--) printf("%d ",tem[j]);
        printf("\n");
    }
    else
    {
        equ(tem,tem1);equ(out,out1);
        Push(tem,i);
        arrange(out,tem,i+1,n);
        equ(tem1,tem);equ(out1,out);
        if(tem[0]!=0)
        {
            out[0]++;out[out[0]]=tem[tem[0]];tem[0]--;
            arrange(out,tem,i,n);
        }
    }

}
void main()
{
    int tem[100],out[100];
    tem[0]=0,out[0]=0;
    arrange(out,tem,1,5);
}
