#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
ll f[200005];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int A, B, C, D;
        ll ans = 0;
        scanf("%d %d %d %d", &A, &B, &C, &D);
        memset(f, 0, sizeof(f));

        // Initialize the difference array f
        for (int x = A; x <= B; x++) {
            f[x + B]++;
            f[x + C + 1]--;
        }

        // Calculate the prefix sums of f
        for (int i = A + B; i <= B + C; i++) {
            f[i] = f[i] + f[i - 1];
            //printf("%lld ", f[i]); // debug
        }
        //printf("\n");

        // Calculate the final answer
        for (int i = A + B; i <= B + C; i++) {
            if (i <= C) continue;
            long long z_low = C;
            long long z_high = min(i - 1, D);
            if (z_high >= z_low) {
                ans += f[i] * (z_high - z_low + 1);
            }
            //printf("final %d %lld %lld %lld\n", i, f[i], z_high, z_low); // debug
        }
        printf("%lld\n", ans);
    }
    return 0;
}