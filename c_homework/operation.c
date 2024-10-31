#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *prev;
} Node;


Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode->prev = newNode; // Circular link
    return newNode;
}

void insert(Node **current, int value, int count)
{
    Node *now = *current;
    while (count--)
    {
        Node *newNode = createNode(value);
        Node *nextNode = now->next;
        now->next = newNode;
        newNode->prev = now;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        now = newNode;
    }
}

void erase(Node *current, int count)
{
    Node *now = current;
    while (count--)
    {
        Node *toDelete = now->next;
        now->next = toDelete->next;
        toDelete->next->prev = now;
        free(toDelete);
    }
}

void move(Node **current, int steps)
{
    Node *now = *current;
    int list_size = 0;

    // Calculate list size
    Node *temp = now;
    do
    {
        list_size++;
        temp = temp->next;
    } while (temp != now);

    // Optimize movement direction
    steps = steps % list_size; // Optimize large steps
    // if (steps < 0)
    // {
    //     steps += list_size; // Convert negative steps to forward steps
    // }

    while (steps--)
    {
        now = now->next;
    }

    *current = now;
}

void show(Node *current)
{
    Node *start = current;
    do
    {
        printf("%d", current->data);
        current = current->next;
        if (current != start)
            printf(" ");
    } while (current != start);
    printf("\n");
}

int main()
{
    int first, n;
    scanf("%d", &first);

    // Create circular linked list with the first element
    Node *head = createNode(first);
    Node *current = head;

    scanf("%d", &n);
    while (n--)
    {
        char operation[10];
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0)
        {
            int value, count;
            scanf("%d %d", &value, &count);
            insert(&current, value, count);
        }
        else if (strcmp(operation, "erase") == 0)
        {
            int count;
            scanf("%d", &count);
            erase(current, count);
        }
        else if (strcmp(operation, "move") == 0)
        {
            int steps;
            scanf("%d", &steps);
            move(&current, steps);
        }
        else if (strcmp(operation, "show") == 0)
        {
            show(current);
        }
    }

    return 0;
}