#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

ll f[2000005];

int min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int T;
  scanf("%d", &T);
  
  while (T--)
  {
    ll ans = 0;//ans is in while loop
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    memset(f, 0, sizeof(f));
    for (int i = a; i <= b; i++)
    {
      f[i + b]++;
      f[i + c + 1]--;
    }

    for (int i = a + b; i <= b + c; i++)
    {
      f[i] = f[i] + f[i - 1];
    }

    for (int i = a + b; i <= b + c; i++)
    {
      if (i <= c) continue;
      ll z_low = c;
      ll z_high = min(i - 1, d);
      if (z_high >= z_low)
      {
        ans += f[i] * (z_high - z_low + 1);
      }
    }
    printf("%lld\n", ans);
  }
}