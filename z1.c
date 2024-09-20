#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *prev, *next;
}Node;



Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = newNode->prev = newNode;
    return newNode;
}
void insert(Node **head, int val, int count)
{
    Node *now = *head;
    while (count--)
    {
        Node *newNode = createNode(val);
        Node *nextNode = now->next;
        now->next = newNode;
        nextNode->prev = newNode;
        newNode->prev = now;
        newNode->next = nextNode;
        now = newNode;
    }
}

void erase(Node**head,int count)
{
    Node*del;
    Node*now=*head;
    while(count--)
    {
        del=now->next;
        now->next=del->next;
        del->next->prev=now;
        free(del);
    }
}

void move(Node**head,int count)
{
    Node*now=*head;
    int length=0;
    Node*tmp=now;
    do
    {
        length++;
        tmp=tmp->next;
    } while (tmp!=now);

    count=count%length;

    while(count--)
    {
        now=now->next;
    }

    *head=now;
}
void show(Node*head)
{
    Node*cur=head;
    do{
        printf("%d",cur->data);
        cur=cur->next;
        if(cur!=head)
        {
            printf(" ");
        }
    }while(cur!=head);
    printf("\n");
}

int main()
{
    int first, n;
    scanf("%d", &first);
    Node *head = createNode(first);

    Node *cur = head;
    scanf("%d", &n);
    while (n--)
    {
        char oper[10];
        scanf("%s", oper);
        if (strcmp(oper, "insert") == 0)
        {
            int value, count;
            scanf("%d %d", &value, &count);
            insert(&cur, value, count);
        }
        else if (strcmp(oper, "erase") == 0)
        {
            int val;
            scanf("%d",&val);
            erase(&cur, val);
        }
        else if (strcmp(oper, "move") == 0)
        {
            int pos;
            scanf("%d",&pos);
            move(&cur, pos);
        }
        else if (strcmp(oper, "show") == 0)
        {
            show(cur);
        }
    }
}