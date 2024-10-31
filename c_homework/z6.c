#include <stdio.h>
int n,k;
int a[2000005];
void permutation(int len,int start)
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
            permutation(len+1,i+1);
        }
    }
}

int main()
{
    n=5,k=3;
    pernutation(1,1);
}