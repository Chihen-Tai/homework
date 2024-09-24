#include <stdio.h>
#define INT_MAX 2147483647
int a[2000005];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int q;
        int cur_min = INT_MAX;
        int max_profit = 0;
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < q; i++)
        {
            if (a[i] < cur_min)
            {
                cur_min = a[i];
            }
            else if (a[i] - cur_min > max_profit)
            {
                max_profit = a[i] - cur_min;
            }
        }
        
        printf("%d\n", max_profit);
    }
}