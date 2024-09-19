#include <stdio.h>
#define MAX_N 2000005

typedef long long ll;

int a[MAX_N];
ll pre[MAX_N];
ll n, p;
int l, r;

ll ab(int l, int r) {
    if (r > l) {
        return pre[r] - pre[l - 1];
    } else if (l == r) {
        return a[r];
    } else {
        return pre[n] - pre[l - 1] + pre[r];
    }
}

int main() {
    while (scanf("%lld %lld", &n, &p) != EOF) {
        ll max = 0, max_l = 0, max_r = 0;
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            pre[i] = a[i] + pre[i - 1];
        }
        for (int i = 0; i < p; i++) {
            scanf("%d %d", &l, &r);
            if (ab(l, r) > max) {
                max = ab(l, r);
                max_l = l;
                max_r = r;
            }
        }
        printf("Max_range: (%d,%d); Value: %lld\n", max_l, max_r, max);
    }
    return 0;
}