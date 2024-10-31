#include <stdio.h>
#include <stdlib.h>

long long int a[200005];
int cmp1(const void *a, const void *b)
{
    return *(long long int *)a> *(long long int *)b- *(long long int *)a<*(long long int *)b;
}
int cmp(const void *a, const void *b) {
    // 使用long long int类型的比较，避免溢出或不匹配
    return (*(long long int *)a > *(long long int *)b) - (*(long long int *)a < *(long long int *)b);
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int q;
        scanf("%d", &q);
        for(int i=0;i<q;i++)
        {
            scanf("%lld",&a[i]);
        }
        qsort(a, q, sizeof(int), cmp);
        for(int i=0;i<q-1;i++)
        {
            printf("%lld ",a[i]);
        }
        if(q>0)
            printf("%lld\n",a[q-1]);
        else
            printf("%lld\n",a[q-1]);
    }
}