#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node *next;
} Node;

Node *createList(int n)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->number = 1;

    Node *cur = p;
    for (int i = 2; i <= n; i++)
    {
        cur->next = (Node *)malloc(sizeof(Node));
        cur = cur->next;
        cur->number = i;
    }
    cur->next = p;

    return p;
}
void freeList(Node *head)
{
    free(head);
}
int solveJosephus(Node **head, int step)
{
    int n = 0;
    Node *tmp, *delNode;

    for (tmp = *head; n < tmp->number; n++)
    {
        tmp = tmp->next;
    }
    while (n > 1)
    {
        int actaulsstep = ((step - 1) % n - 1 + n) % n;
        // step-1 because we start from 1
        //%n because we need to wrap around
        //-1 because we need to go to the previous node
        //+n avoid negative value
        // second % to range in 0 to n-1(not necessary)
        Node *tmp = *head;
        // Node*tmp=head;
        for (int i = 0; i < actaulsstep; i++)
        {
            tmp = tmp->next;
        }
        delNode = tmp->next;
        tmp->next = tmp->next->next;
        *head = tmp->next;

        free(delNode);
        n--;
    }

    return (*head)->number;
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