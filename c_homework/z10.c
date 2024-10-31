#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
ll n, q;
int a[2000005];

ll p[2000005];
int l, r;

ll value(int r, int l)
{
    if (l > r)
    {
        return p[l] - p[r - 1];
    }
    else if (l == r)
    {
        return a[l];
    }
    else if (l < r)
    {
        return p[n] - p[r - 1] + p[l];
    }
}
int main()
{
    
    while (scanf("%lld%lld", &n, &q) != EOF)
    {
        p[0] = 0;
        ll ans = 0;
        ll ansl=0, ansr=0;
        for (int i = 1; i <=n; i++)
        {
            scanf("%d", &a[i]);
            p[i] = p[i - 1] + a[i];
        }
        
        while (q--)
        {
            scanf("%d%d", &l, &r);
            printf("%lld", value(l, r));
            if (value(l, r) > ans)
            {
                ans = value(l, r);
                ansl = l;
                ansr = r;
            }
        }
        printf("Max_range: (%d,%d); Value: %lld\n", ansl, ansr, ans);
    }
    return 0;
}