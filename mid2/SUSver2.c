#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
    int number;
    struct _NODE *right;
    struct _NODE *left;
} Node;

// Global variables
int flag = 1;
int postIndex = 0;
int *generatedPostorder;

// Function to find the index of the current root in the inorder array
int find_mid(int *in, int len, int num) {
    for (int i = 0; i < len; i++) {
        if (in[i] == num) {
            return i;
        }
    }
    return len;
}

// Function to build the binary tree from preorder and inorder arrays
Node *buildTree(int *pre, int *in, int len) {
    if (len == 0)
        return NULL;

    Node *now = (Node *)malloc(sizeof(Node));
    now->number = pre[0];

    int mid = find_mid(in, len, pre[0]);
    if (mid == len) {
        flag = 0;
        return NULL;
    }

    now->left = buildTree(pre + 1, in, mid);
    now->right = buildTree(pre + mid + 1, in + mid + 1, len - mid - 1);
    return now;
}

void postorder(Node *now) {
    if (now == NULL)
        return;
    postorder(now->left);
    postorder(now->right);
    generatedPostorder[postIndex++] = now->number;
}

int check_same(int *a, int *b, int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

void freeTree(Node *now) {
    if (now == NULL)
        return;
    freeTree(now->left);
    freeTree(now->right);
    free(now);
}

int main() {
    int n, q, qs;
    int *inorder, *preorder, *inputPostorder;

    scanf("%d", &q); 
    while (q--) {
        scanf("%d", &n); 

        // Dynamically allocate memory for the arrays
        preorder = (int *)malloc(n * sizeof(int));
        inputPostorder = (int *)malloc(n * sizeof(int));
        generatedPostorder = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &preorder[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &inputPostorder[i]);
        }

        scanf("%d", &qs);
        while (qs--) {
            flag = 1;       // Reset 
            postIndex = 0;  // Reset 

            // Allocate memory for inorder array for this query
            inorder = (int *)malloc(n * sizeof(int));

            // Read inorder array
            for (int i = 0; i < n; i++) {
                scanf("%d", &inorder[i]);
            }

            // Build the tree from preorder and inorder arrays
            Node *root = buildTree(preorder, inorder, n);
            if (flag == 0) {
                printf("No\n");
            } else {
                postorder(root);

                // Check if the generated postorder matches the input postorder
                if (check_same(generatedPostorder, inputPostorder, n) == 1) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            }

            // Free the allocated tree and arrays
            freeTree(root);
        }
    }

    return 0;
}
