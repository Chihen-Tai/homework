#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _NODE
{
    int number;
    struct _NODE *right;
    struct _NODE *left;
} Node;

int buildTreeVaild(int *pre,int *in,int *post,int len)
{
    //return 1 if the tree is valid
    if(len==0)return 1;
    post[len-1]=pre[0];
    int mid=find_mid(in,len,pre[0]);
    if(mid==len)
        return 0;
    if(!buildTreeVaild(pre+1,in,post,mid-1))
        return 0;
    if(!buildTreeVaild(pre+mid+1,in+mid+1,post+mid,len-mid-1))
        return 0;
    return 1;
}

int check_same(int *a, int *b, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

int find_mid(int *in, int len, int num)
{
    for (int i = 0; i < len; i++)
    {
        if (in[i] == num)
        {
            return i;
        }
    }
    return len;
}

int main()
{
    int n, q, qs;
    int inorder[2000005], preorder[2000005], postorder[2000005];
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &preorder[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &postorder[i]);
        }
    }
    scanf("%d", &qs);
    while (qs--)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&inorder[i]);
        }
        if(buildTreeVaild(preorder,inorder,postorder,n)&&check_same(postorder,postorder,n))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}