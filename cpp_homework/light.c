#include <stdio.h>
#define MAX 1000

void fib(long long *s)
{
    s[0] = s[1] = 1;
    for (long long i = 2; i < MAX; i++)
        s[i] = s[i - 1] + s[i - 2];
}
// when n>=2, F(n) = fib(n-1)*F(1) + fib(n-2)
// F(0) = 1, F(1) = F(1)

int main()
{
    long long n;
    long long f[MAX];
    fib(f);
    while (scanf("%lld", &n) != EOF)
    {
        if (n == 0)
        {
            printf("0\n");
            continue;
        }
        for (long long i = MAX - 1; i >= 0; i--)
        {
            if ((n - f[i]) > 0 && (n - f[i]) % f[i + 1] == 0)
            {
                printf("%lld\n", (n - f[i]) / f[i + 1]);
                break;
            }
        }
    }
}