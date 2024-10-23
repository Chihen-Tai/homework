#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000005

typedef long long ll;
int a[MAX_N];

ll p[MAX_N];
ll n,q,m,l,r;

int main()
{
    scanf("%lld%lld",&n,&q);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    p[0]=0;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]+a[i-1]*(a[i-1]>=0);
    }
    while(q--)
    {
        scanf("%lld%lld%lld",&l,&r,&m);
        printf("%lld",p[l+m-1]-p[l-1]);
    }
}