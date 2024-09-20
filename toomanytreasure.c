#include <stdio.h>
typedef long long ll;
int a[2000005];
ll p[2000005];
ll n,q,l,m,r;
int main()
{
    scanf("%lld %lld",&n,&q);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    p[0]=0;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]+a[i-1]*(a[i-1]>=0);
        //printf("p[%d]=%d ",i,p[i]);
    }
    while(q--)
    {
        scanf("%lld %lld %lld",&l,&r,&m);
        printf("%lld\n",p[l+m-1]-p[l-1]);
    }
}