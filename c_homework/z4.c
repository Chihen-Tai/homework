#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;


int n;
char buf[100];
int num1, num2;
Node *head;

void insert(Node**head,char*color,int index)
{
    Node*now=*head;
    for(int i=0;i!=index&&now->next!=NULL;i++)
    {
        now=now->next;
    }
    Node*new=(Node*)malloc(sizeof(Node));
    strcpy(new->color,color);
    new->next=now->next;
    now->next=new;
}

void erase1(Node**head,int index)
{
    Node*now=*head,*prev=NULL;
    for(int i=0;now->next!=NULL&&i!=index;i++)
    {
        prev=now;
        now=now->next;
    }
    if(prev==NULL)
    {
        return;
    }
    prev->next=now->next;
    free(now);
    now=prev;
}

void erase2(Node**head,char*color)
{
    Node*now=*head,*prev=NULL;
    while(now!=NULL)
    {
        if(strcmp(now->color,color)==0)
        {
            prev->next=now->next;
            free(now);
            now=prev;
        }
        prev=now;
        now=now->next;
    }
}

void reverse(Node**head,int start,int end)
{
    int idx;
    Node*now=*head,*left=NULL;
    for(idx=0;now->next!=NULL&&idx!=start;idx++)
    {
        left=now;
        now=now->next;
    }
    for(;now->next!=NULL&&idx!=end;idx++)
    {
        Node*next=now->next;
        now->next=next->next;
        next->next=left->next;
        left->next=next;
    }
}