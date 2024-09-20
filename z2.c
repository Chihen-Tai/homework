#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node* next;
}Node;

Node *createList(int n)
{
    Node*head=(Node*)malloc(sizeof(Node));
    head->number=1;
    Node*now=head;
    for(int i=2;i<=n;i++)
    {
        now->next=(Node*)malloc(sizeof(Node));
        now=now->next;
        now->number=i;
    }
    now->next=head;

    return head;
}
void freeList(Node* head)
{
}
int solveJosephus(Node **head, int step)
{
    Node*tmp;
    tmp=*head;
    int n=0;
    for(n=0;tmp->next!=NULL&&n<tmp->number;n++)
    {
        tmp=tmp->next;
    }
    while(n>1)
    {
        Node*cur=*head;
        Node *del;
        int act= ((step-1)%n-1+n)%n;
        for(int i=0;i<act;i++)
        {
            cur=cur->next;
        }
        cur->next=cur->next->next;
        *head=cur->next;
        n--;
    }

    return (*head)->number;
}