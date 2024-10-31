#include <stdio.h>
#include <stdlib.h>

int a[2000005];
int cmp(const void *l, const void *r)
{
    int a = *(int *)l;
    int b = *(int *)r;
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

int lower(int *a, int l, int r, int num)
{
    int mid;
    while (l < r)
    {
        mid=(l+r)/2;
        if (a[mid] >= num)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }    
    }
    return r;
}

int upper(int *a, int l, int r, int num)
{
    int mid;
    while (l < r)
    {
        mid=(l+r)/2;
        if (a[mid] > num)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
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
    int q,tar;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&tar);
        printf("%d\n",upper(a,0,n,tar)-lower(a,0,n,tar));
    }
}