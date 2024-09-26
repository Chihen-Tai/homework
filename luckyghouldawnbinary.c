#include <stdio.h>
#include <stdlib.h>

int arr[2000005];

// int loser_bound(array , left , right , target)
// int lower_bound(int *arr,int l,int r,int num)
// int loser_bound(array,sizeof_array,target)
int lower_bound(int *arr, int n, int target)
{
    int l = 0, r = n;
    while (l < r)
    {
        int mid = ((l + r) / 2);
        if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return r;
}

int main()
{
    int n, q;
    while (scanf("%d %d", &n, &q) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < q; i++)
        {
            int target;
            scanf("%d", &target);
            int idx = lower_bound(arr, n, target);
            if (idx == n || arr[idx] != target)
            {
                printf("Break your bridge!\n");
            }
            else
            {
                printf("%d\n", idx+1);
            }
        }
    }
}