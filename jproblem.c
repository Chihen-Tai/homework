#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node *next;
} Node;

Node *createList(int n)
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    for (int i = 1; i <= n; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->number = i;
        newNode->next = head;
        head = newNode;
    }


    return head;
}

void freeList(Node *head)
{
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int solveJosephus(Node **head, int step)
{
}

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        Node *head;
        head = createList(n);
        printf("%d\n", solveJosephus(&head, k));
        freeList(head);
    }
    return 0;
}