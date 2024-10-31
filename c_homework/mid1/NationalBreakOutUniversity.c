#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000005
// 1.choose i => p[i]>=x
// 2.sum(p)=>sum(p)-p[i]>=y
// 3.y-(sum(p)-p[i]),0

/*
for i from [1,n]
->calculate p[i]
print min{y-(sum(p)-p[i]),0}
*/

/*
sum_p=sum(p);
for(int i=0;i<n;i++)
{
    cost_now=max(x-p[i],0);
    cost_now+=max(y-(sum_p-p[i]),0);
    min_cost=min(min_cost,cost_now);
}

printf("%lld",min_cost);
*/

int lower_bound(int *a,int size,long long target)//lower_bound(arr+mid,size-mid)
{
    //return size if cannot fing a arr[i]>=target
    int l=0,r=size;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]>=target)//arr[mid]<target
        // {
        //     r=mid;
        // }
        // else
        // {
        //     l=mid+1;
        // }
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


lower_bound(p,n,x)-1;
//1.lower_bound(p,n,x)==n cant find a[i]>=x
//2.lower_bound(p,n,x)-1 is the largest a[i]<x