#include <stdio.h>
#define max 1000
typedef long long ll;
void fib(ll*s)
{
    s[0]=s[1]=1;
    for(ll i=2;i<max;i++)
    {
        s[i]=s[i-1]+s[i-2];
    }
}

int main()
{
    ll n;
    ll f[max];
    fib(f);
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        for(ll i=max-1;i>=0;i++)
        {
            if(((n-f[i])>0)&&((n-f[i])%f[i+1]==0))
            {
                printf("%lld\n",(n-f[i])/f[i+1]);
                break;
            }
        }
    }
}