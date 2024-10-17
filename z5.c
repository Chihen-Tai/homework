#include <stdio.h>
int a[2000005];
int p[2000005];
int main()
{
    p[0]=0;
    int n,k;
    double ans=0,tmp=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]+a[i-1];
        printf("%d\n",p[i]);
    }
    tmp=(p[n-k+1]-p[1]);
    ans=(p[n-k+1]-p[1])/(n-k);
    printf("%.3lf\n",ans);
    printf("%.3lf\n",tmp);
}