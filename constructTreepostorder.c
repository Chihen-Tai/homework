#include <stdio.h>
#include <stdlib.h>
typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

int n;
int postorder_index;
Node *buildTree(int *Inorder, int *postorder, int inorder_start, int inorder_end)
{

    if (inorder_start > inorder_end)
        return NULL;

    Node *root = (Node *)malloc(sizeof(Node));
    root->number = postorder[postorder_index];
    postorder_index--;

    int inorder_index;
    for (inorder_index = inorder_start; inorder_index <= inorder_end; inorder_index++)
    {
        if (Inorder[inorder_index] == root->number)
        {
            break;
        }
    }

    root->ptr_to_right_node = buildTree(Inorder, postorder, inorder_index + 1, inorder_end);
    root->ptr_to_left_node = buildTree(Inorder, postorder, inorder_start, inorder_index - 1);

    /*postorder遍歷順序：postorder的最後一個元素是整棵樹的根節點，然後是右子樹，最後是左子樹。
    所以當你從postorder數組中取出一個元素作為根時，接下來應該先構建右子樹，然後構建左子樹，這樣才能符合postorder的順序。
    節點選取順序：如果你先處理左子樹，會導致postorder數組中的節點選取順序不正確，進而錯誤地構建樹的結構。*/

    return root;
}
void showpreorder(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d ", root->number);
        showpreorder(root->ptr_to_left_node);
        showpreorder(root->ptr_to_right_node);
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
        postorder_index = n - 1;
        int inorder[100], postorder[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &inorder[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &postorder[i]);
        Node *root = buildTree(inorder, postorder, 0, n - 1);
        printf("testcase%d: ", id++);
        showpreorder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}