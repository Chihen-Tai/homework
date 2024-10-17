#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node *left, *right;
} Node;
int n;
int pre_idx = 0;
Node *buildTree(int *inorder, int *preorder, int start, int end)
{
    if (start > end)
        return NULL;
    Node *root = (Node *)malloc(sizeof(Node));
    root->number = preorder[pre_idx];
    pre_idx++;

    int inorder_idx=0;
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == root->number)
        {
            inorder_idx = i;
        }
    }

    root->left = buildTree(inorder, preorder, start, inorder_idx - 1);
    root->right = buildTree(inorder, preorder, inorder_idx + 1, end);

    return root;
}
void freeTree(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        freeTree(root->right);
        freeTree(root->left);
        free(root);
        
    }
}

void showPostorder(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->number);
        pre_idx=0;
    }
}
int main()
{
    int id = 1;
    while (scanf("%d", &n) != EOF)
    {
        int inorder[100], preorder[100];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inorder[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &preorder[i]);
        }
        printf("1\n");
        Node *root = buildTree(inorder, preorder, 0, n - 1);
        printf("1\n");
        showPostorder(root);
        printf("1\n");
        freeTree(root);
        printf("1\n");
    }
}