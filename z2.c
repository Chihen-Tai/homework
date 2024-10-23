#include <stdio.h>
int a[200005];
int n,k;
void per(int len,int start)
{
    if(len==k+1)
    {
        for(int i=1;i<=k;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(int i=start;i<=n;i++)
        {
            a[len]=i;
            per(len+1,i+1);
        }
    }
}
int main()
{
    n=5,k=3;
    per(1,1);
}