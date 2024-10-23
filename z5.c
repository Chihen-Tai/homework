#include <stdio.h>
#include <stdlib.h>
int inorder[2000005], preorder[2000005];
int n;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inorder[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &preorder[i]);
        }
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (inorder[i] == preorder[j - 1] && inorder[i - 1] == preorder[j])
                {
                    ans = ans * 2;
                }
            }
        }
        printf("%d\n",ans);
    }
}