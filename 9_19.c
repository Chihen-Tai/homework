#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next,*prev; // Changed from struct Node to struct _Node
}Node;

Node *now;

Node *createNode(int val)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=newNode->prev=newNode;
    return newNode;
}

void insert(Node **head,int val,int count)
{
    now=*head;
    while(count--)
    {
        Node *newNode=createNode(val);
        Node *nextNode=now->next;
        now->next=newNode;
        newNode->prev=now;
        newNode->next=nextNode;
        nextNode->prev=newNode;
        now=newNode;
    }
}

void erase(Node**head,int count)
{
    now=*head;
    while(count--)
    {
        Node *toDelete = now->next;
        now->next = toDelete->next;
        toDelete->next->prev = now;
        free(toDelete);
    }
}

void move(Node**head,int steps)
{
    now=*head;
    int list_size=0;
    Node*tmp=now;
    do
    {
        list_size++;
        tmp=tmp->next;
    } while(tmp!=now);
    steps=steps%list_size;

    while(steps--)
    {
        now=now->next;
    }
    *head=now;
    
}

void show(Node*head)
{
    Node*start=head;
    do{
        printf("%d",start->data);
        start=start->next;
        if(start!=head)
        {
            printf(" ");
        }
    }while(start!=head);
}

int main()
{
    int first,n;
    scanf("%d",&first);
    Node*head=createNode(first);
    Node*current=head;
    scanf("%d",&n);
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
            erase(&current, count);
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