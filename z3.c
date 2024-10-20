#include <stdio.h>
#include <stdlib.h>

int a[2000005];
int q, n;

typedef struct _Node
{
    int data, id;
    struct _Node *left, *right;
} Node;

void build_tree(Node **now, int *arr, int l, int r)
{
    if (l > r)
        return;
    (*now) = (Node *)malloc(sizeof(Node));
    (*now)->left=(*now)->right=NULL;
    if (l == r)
    {
        (*now)->data=arr[l];
        (*now)->id=l;
    }
    else
    {
        int mid=(l+r)/2;
        (*now)->data=arr[mid];
        (*now)->id=mid;
        build_tree(&(*now)->left,arr,l,mid-1);
        build_tree(&(*now)->right,arr,mid+1,r);
    }
}

int search(Node *now, int x)
{
    if (now == NULL)
        return -1;
    if(now->data==x)
    {
        return now->id;
    }
    if(now->data<x)
    {
        return search(now->right,x);
    }
    if(now->data>x)
    {
        return search(now->left,x);
    }
}


void freeBST(Node *root)
{
    if (root == NULL)
        return;
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main()
{
    while (scanf("%d %d", &n, &q) != EOF)
    {
        Node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        build_tree(&root, a, 0, n - 1);
        for (int i = 0; i < q; i++)
        {
            int x;
            scanf("%d",&x);
            int ans = search(root, x);
            if (ans == -1)
            {
                printf("Break your bridge\n");
            }
            else
            {
                printf("%d\n",ans+1);
            }
           
        }
        freeBST(root);
    } 
}