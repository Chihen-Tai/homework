#include <stdio.h>
#include <stdlib.h>
int pre[2000005], post[200005];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        long long ans = 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &pre[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &post[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (pre[i] == post[j + 1] && pre[i + 1] == post[j])
                {
                    ans = ans * 2;
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
