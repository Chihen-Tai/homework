#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node*next;
}Node;

Node *createList(int n)
{
    Node*p;
    p=(Node*)malloc(sizeof(Node));
    p->number=1;

    Node*cur=p;
    for(int i=2;i<=n;i++)
    {
        cur->next=(Node*)malloc(sizeof(Node));
        cur=cur->next;
        cur->number=i;
    }
    cur->next=p;

    return p;
}
int sloveJosephus(Node**head,int step)
{
    int n=0;
    Node*tmp,*delNode;
    for(tmp=*head; n < tmp->number; n++)
    {
        tmp = tmp->next;
    }
    while(n>1)
    {
        int act=((step-1)%n-1+n)%n;
        tmp=*head;
        for(int i=0;i<act;i++)
        {
            tmp=tmp->next;
        }
        delNode=tmp->next;
        tmp->next=tmp->next->next;
        *head=tmp->next;

        free(delNode);
        n--;
    }

    return (*head)->number;
}

void freeList(Node*head)
{
    free(head);
}
