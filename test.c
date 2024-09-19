#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _Node
{
    int number;
    struct _Node *next;
} Node;

Node *createList(int n)
{
    Node*head=(Node*)malloc(sizeof(Node));
    head->number=1;
    Node*cur=head;
    for(int i=2;i<=n;i++)
    {
        cur->next=(Node*)malloc(sizeof(Node));
        cur=cur->next;
        cur->number=i;
    }
    cur->next=head; // Ensure the last node points to head

    return head;
}
int solveJosephus(Node **head, int step)
{
    int n=0;
    Node*tmp;
    for(tmp=*head;tmp->next!=NULL&&n<tmp->number;n++)
    {
        //printf("%d",tmp->number);
        tmp=tmp->next;
    }
    while(n>1)
    {
        Node*now=*head;
        int act=((step-1)%n-1+n)%n;
        for(int i=0;i<act;i++)
        {
            now=now->next;
        }
        Node*del=now->next;
        now->next=now->next->next;
        *head=now->next;
        n--;
    }

    return (*head)->number;
}
