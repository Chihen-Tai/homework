#include <stdio.h>
int a[200005];

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int q;
        int max_profit=0;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&a[i]);
        }
        int cur_min=a[0];
        for(int i=0;i<q;i++)
        {
            if(a[i]<cur_min)
            {
                cur_min=a[i];
            }
            else if(a[i]-cur_min>max_profit)
            {
                max_profit=a[i]-cur_min;
            }
        }
    }

    return 0;
}