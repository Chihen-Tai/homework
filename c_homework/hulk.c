#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000005
int n;
int a[MAX_N];

int cmp(const void *L,const void *R)
{
    int l=*(int*)L;
    int r=*(int*)R;
    if(l>r)
        return 1;
    else if(l<r)
        return -1;
    else
        return 0;
}

int upper(int*a,int l,int r,int num)
{
    int mid;
    while(r>l)
    {
        mid=(l+r)/2;
        if(a[mid]>num)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return r;
}
int lower(int*a,int l,int r,int num)
{
    int mid;
    while(r>l)
    {
        mid=(l+r)/2;
        if(a[mid]>=num)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return r;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int q,x;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&x);
        printf("%d",upper(a,0,n,x)-lower(a,0,n,x)); 
        //n和n-1好像有點差
    }
    return 0;
}