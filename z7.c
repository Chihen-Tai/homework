#include <stdio.h>
#include <stdlib.h>

int a[200005];

int cmp(const void* l,const void *r)
{
    int L=*(int *)l;
    int R=*(int *)r;
    if(L>R)
        return 1;
    else if (L<R)
        return -1;
    else
        return 0;
}

int upper(int *a,int start,int end,int tar)
{
    int mid;
    while(start<end)
    {
        mid=(start+end)/2;
        if(a[mid]>tar)
        {
            end=mid; 
        }
        else
        {
            start=mid+1;
        }
    }
    return end;
}

int lower(int *a,int start,int end,int tar)
{
    int mid;
    while(start<end)
    {
        mid=(start+end)/2;
        if(a[mid]>=tar)
        {
            end=mid; 
        }
        else
        {
            start=mid+1;
        }
    }
    return end;
}
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int q,tar;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&tar);
        printf("%d",upper(a,0,n,tar)-lower(a,0,n,tar));
    }
}
