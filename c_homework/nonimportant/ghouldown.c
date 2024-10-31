#include <stdio.h>
long long int a[2000005],p[2000005];
double tot,ans=0;
int main()
{
    p[0]=0;
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        p[i]=p[i-1]+a[i];
    }
    for(int i=0;i<=n-k;i++)
    {
        for(int j=i+k;j<=n;j++)
        {
            tot=p[j]-p[i];
            tot=(tot)/(j-i);
            if(tot>=ans)
            {
                ans=tot;
            }
        }
    }
    printf("%.3lf\n",ans);
}