#include <stdio.h>
#include <stdlib.h>
int n,r;

typedef struct
{
    int x[2005];
    int y[2005];
    int visit[2005];
}plane;

plane xy;

int dis(int i,int j)
{
    return (xy.x[i]-xy.x[j])*(xy.x[i]-xy.x[j])+(xy.y[i]-xy.y[j]*(xy.y[i]-xy.y[j]));
}

int dfs(int now)
{
    xy.visit[now]=1;
    int res=1;
    for(int i=0;i<n;i++)
    {
        if(dis(now,r)<=r*r&&xy.visit[i]==0)
        {
            res+=dfs(i);
        }
    }
    return res;
}

int main()
{
    scanf("%d %d",&n,&r);
    int g1=0, g2=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&xy.x[i],&xy.y[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(xy.visit[i]==0)
        {
            if(dfs(i)>=2)
            {
                g1++;
            }
            else 
                g2++;
        }
    }

    printf("%d %d\n",g2,g1);
    return 0;
}