#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE
{
    int data;
    struct _NODE *next;
} Node;

Node* Create_List(Node*, int);
Node* Reverse_List(Node*);
void Print_List(Node*);
void Free_List(Node*);

int main() {
    Node *head = NULL;
    int n, data, i;
    
    scanf("%d", &n);
    for( i=0; i<n; i++ ) {
        scanf("%d", &data);
        head = Create_List( head, data );
    }
    
    head = Reverse_List( head );
    
    Print_List( head );
    Free_List( head );
    
    return 0;
}

Node* Create_List(Node *head, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Node* Reverse_List(Node *head) {
    Node *prev = NULL, *cur = head, *next = NULL;
    while( cur != NULL ) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

void Print_List(Node *head) {
    Node *cur = head;
    int a[100];
    int i=0;
    while( cur != NULL ) {
        
        a[i]=cur->data;
        cur = cur->next;
        i++;
    }
    while(i>0)
    {
        i--;
        printf("%d",a[i]);
        if(i!=0)
        {
             printf("->");
        }
       
    }
}

void Free_List(Node *head) {
    Node *cur = head, *next = NULL;
    while( cur != NULL ) {
        next = cur->next;
        free(cur);
        cur = next;
    }
}