#include <stdio.h>
#include <stdlib.h>
typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

int n;
int preorder_index = 0;

Node *buildTree(int *Inorder, int *Preorder, int inorder_start, int inorder_end)
{

    if (inorder_start > inorder_end)
        return NULL;

    Node *root = (Node *)malloc(sizeof(Node));
    root->number = Preorder[preorder_index];
    preorder_index++;

    int inorder_index = 0;
    for (int i = inorder_start; i <= inorder_end; i++)
    {
        if (Inorder[i] == root->number)
        {
            inorder_index = i;        }
    }

    root->ptr_to_left_node = buildTree(Inorder, Preorder, inorder_start, inorder_index - 1);
    root->ptr_to_right_node = buildTree(Inorder, Preorder, inorder_index + 1, inorder_end);

    return root;
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
        preorder_index = 0;
    }
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        freeTree(root->ptr_to_left_node);
        root->ptr_to_left_node = NULL;
        freeTree(root->ptr_to_right_node);
        root->ptr_to_right_node = NULL;
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