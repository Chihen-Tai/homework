#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int number;
    struct _Node* next;
}Node;
Node*createList(int n)
{
    Node*p=(Node*)malloc(sizeof(Node));
    p->number=1;
    
    Node*now=p;
    for(int i=2;i<=n;i++)
    {
        now->next=(Node*)malloc(sizeof(Node));
        now=now->next;
        now->number=i;
    }

    now->next=p;
    return p;
}
void freeList(Node*head)
{}
int solveJosephus(Node**head,int k)
{
    int n;
    for(Node*temp=*head;temp->number>=n;n++)
    {
        temp=temp->next;
    }

    while(n>1)
    {
        int actstep=((k-1)%n-1+n)%n;
        Node*now=*head;
        for(int i=0;i<actstep;i++)
        {
            now=now->next;
        }
        now->next=now->next->next;
        *head=now->next;
        n--;
    }
    return (*head)->number;
}
int main()
{
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF )
   {
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}