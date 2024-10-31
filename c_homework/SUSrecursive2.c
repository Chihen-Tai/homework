#include <stdio.h>
#define MAX_N 9

void get_pre(int *pre, int *in, int *post, int sz) {
    if(sz == 0) return;
    pre[0] = post[sz-1];
    int mid;
    for(mid=0; in[mid] != post[sz-1] && mid < sz; ++mid);
    if(mid==sz) {
        pre[0] = -1;
        return;
    }
    get_pre(pre + 1, in, post, mid);
    get_pre(pre + 1 + mid, in + mid + 1, post + mid, sz - mid - 1);
}

int n;
int post[MAX_N], pre[MAX_N];
int selected[MAX_N];

int getans(int now) {
    static int in[MAX_N], pre_valid[MAX_N];
    if(now == n) {
        get_pre(pre_valid, in, post, n);
        int valid = 1;
        for(int i = 0; i < n && valid; ++i)
            if(pre_valid[i] != pre[i])
                valid = 0;
        return valid;
    }
    int res = 0;
    for(int i=1; i <= n; ++i) {
        if(!selected[i]) {
            selected[i] = 1;
            in[now] = i;
            res += getans(now + 1);
            selected[i] = 0;
        }
    }
    return res;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i=0; i < n; ++i) scanf("%d", &pre[i]);
        for(int i=0; i < n; ++i) scanf("%d", &post[i]);
        printf("%d\n", getans(0));
    }
    return 0;
}