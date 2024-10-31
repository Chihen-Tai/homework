#include <stdio.h>
#include <stdlib.h>
int n, r;
typedef struct
{
    int x[2005];
    int y[2005];
    int visit[2005];
} plane;

plane xy; // 定義結構變量

int dis(int i, int j)
{
    return (xy.x[i] - xy.x[j]) * (xy.x[i] - xy.x[j]) + (xy.y[i] - xy.y[j]) * (xy.y[i] - xy.y[j]);
}

int dfs(int now)
{
    xy.visit[now] = 1;
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (dis(now, i) <= r * r && xy.visit[i] == 0)
        {
            res += dfs(i);
            //printf("%d\n", res);
        }
    }
    return res;
}

int main()
{

    scanf("%d %d", &n, &r);
    int group1 = 0, group2 = 0;
    // 讀取點的座標
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &xy.x[i], &xy.y[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (xy.visit[i] == 0)
        {
            //printf("i=%d res=%d\n", i,dfs(i));
            if (dfs(i) >= 2)
            {
                group1++;
            }
            else
            {
                group2++;
            }
        }
    }
    printf("%d %d\n", group2, group1);

    return 0;
}