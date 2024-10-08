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


void insert(Node **head, char *color, int index)
{
    Node *now = (*head);//head 只是用來作為鏈表的起始點，一般不會儲存任何有效數據 because of     head->next = NULL;
    for (int idx=0; now->next != NULL && idx != index; idx++)
    {
        now = now->next;
    }
    Node *new = (Node *)malloc(sizeof(Node));

    strcpy(new->color, color);

    new->next = now->next;
    now->next = new;
}

void erase1(Node **head, int index)
{
    Node *now = (*head), *prev = NULL;

    for (int idx=0; now->next != NULL && idx != index; idx++)
    {
        prev = now; // 一直在當時prev的前一個
        now = now->next;
        
    }

    if (prev == NULL)
    {
        return;
    }
    prev->next = now->next;

    free(now);
}

void erase2(Node **head, char *color)
{
    Node **pp =head;
    Node *entry = *head;
	while (entry != NULL)
    {
        if (strcmp(color, entry->color) == 0)
        {
           *pp = entry->next;
            //pp = &entry->next;
            //free(entry);
        }
        else
        {
			pp = &entry->next;
        }
        entry = entry->next;
    }
}

void erase3(Node**head,char*color)
{
    Node *now=*head,*prev=NULL;
    while(now!=NULL)
    {
        if(strcmp(now->color,color)==0)
        {
            prev->next=now->next;
            // free(now);
            // now=prev;
        }
        else
            prev=now;
        now=now->next;
    }
}

void reverse(Node **head, int first, int last)
{
    Node *now = (*head), *left = NULL;
    int idx;
    for (idx = 0; now != NULL && idx != first; idx++)
    {
        left = now;
        now = now->next;
    }
    while (now->next != NULL && idx < last)
    {
        Node *next = now->next;
        now->next = next->next;//orange to green
        next->next = left->next;// red to orange
        left->next = next;//blue to red
        idx++;
    }
}

void show(Node **head) {
    Node *now = (*head)->next;
    while(now!=NULL) {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}

int main()
{
    head = (Node *)malloc(sizeof(Node)); // create an empty node
    memset(head->color, '\0', sizeof(head->color));
    head->next = NULL;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", buf);
        if (!strcmp(buf, "insert"))
        {
            scanf("%s%d", buf, &num1);
            insert(&head, buf, num1); // insert <color> <dest>
        }
        else if (!strcmp(buf, "erase1"))
        {
            scanf("%d", &num1);
            erase1(&head, num1); // erase1 <dest>
        }
        else if (!strcmp(buf, "erase2"))
        {
            scanf("%s", buf);
            erase2(&head, buf); // erase2 <color>
        }
        else if (!strcmp(buf, "reverse"))
        {
            scanf("%d%d", &num1, &num2);
            reverse(&head, num1, num2); // reverse <dest1> <dest2>
        }
        else if (!strcmp(buf, "show"))
        {
            show(&head);
        }
    }
   
    return 0;
}