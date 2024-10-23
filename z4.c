#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;
int n;
int preorder_idx = 0;
Node *buildTree(int *inorder, int *preorder, int start, int end)
{
    if (start > end)
        return NULL;
    else
    {
        Node *root = (Node *)malloc(sizeof(Node));
        root->number = preorder[preorder_idx];
        preorder_idx++;

        int inorder_idx=0;
        for (int i = start; i <= end; i++)//remember add <=
        {
            if (inorder[i] == root->number)
            {
                inorder_idx = i;
            }
        }
        root->ptr_to_left_node = buildTree(inorder, preorder, start, inorder_idx - 1);
        root->ptr_to_right_node = buildTree(inorder, preorder, inorder_idx + 1, end);
        return root;
    }
}
void showPostorder(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        showPostorder(root->ptr_to_left_node);
        showPostorder(root->ptr_to_right_node);
        printf("%d ", root->number);
        preorder_idx=0;
    }
}
void freeTree(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        freeTree(root->ptr_to_left_node);
        freeTree(root->ptr_to_right_node);
        free(root);
    }
}
int main(void)
{
    int id = 1;
    while (~scanf("%d", &n))
    {
        int inorder[100], preorder[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &inorder[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &preorder[i]);
        Node *root = buildTree(inorder, preorder, 0, n - 1);
        printf("testcase%d: ", id++);
        showPostorder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}