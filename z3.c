#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, q;
int a[2000005];
typedef struct _Node
{
    int num, id;
    struct _Node *left, *right;
} Node;

Node *buildtree(int *a, int start, int end)
{
    if (start > end)
        return NULL;
    Node *root = (Node *)malloc(sizeof(Node));
    if (start == end)
    {
        root->id = start;
        root->num = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        root->id = mid;
        root->num = a[mid];
        root->left = buildtree(a, start, mid - 1);
        root->right = buildtree(a, mid + 1, end);
    }

    return root;
}
int search(Node*now,int x)
{
    if(now==NULL)//easy to use = it is dangerous rem us ==
        return -1;
    else if(now->num==x)
        return now->id;
    else if(now->num>x)
        return search(now->left,x);
    else if(now->num<x)
        return search(now->right,x);
}
int main()
{
    while(scanf("%d%d", &n, &q)!=EOF)
    {
        for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    Node*root=buildtree(a,0,n-1);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        int ans=search(root,x);
        if(ans==-1)
        {
                printf("Break your bridge!\n");
        }
        else
        {
            printf("%d\n",ans+1);
        }
    }
    }
    
}