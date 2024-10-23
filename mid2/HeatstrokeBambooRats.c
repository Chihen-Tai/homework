#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node *right;
    struct _Node *left;
}Node;

void build_tree(Node **now, int *arr, int l, int r)
{
    if(l>r)
        return NULL;
    (*now)=(Node*)malloc(sizeof(Node));
    if(l==r)
    {
        (*now)->number=arr[l];
        (*now)->left=(*now)->right=NULL;
    }
    else
    {
        int mid = (l+r)/2;
        (*now)->number=arr[mid];
        build_tree((*now)->left,arr,l,mid-1);
        build_tree((*now)->right,arr,mid+1,r);
    }
}
int query_heatstroke(Node *now, int x)
{
    if(now==NULL)
        return 0;
    else if(now->number==x)
        return 1;
    else if(now->number>x)
        return query_heatstroke(now->left,x);
    else if(now->number<x)
        return query_heatstroke(now->right,x);
}
void eat_rat(Node **root, int x)
{
    Node **cur=root;
    while((*cur)->number!=x)
    {
        if((*cur)->number>x)
        {
            cur=&((*cur)->left);
        }
        else
        {
            cur-&((*cur)->right);
        }
    }
    if((*cur)->left==NULL&&(*cur)->right==NULL)
    {
        free(*cur);
        *cur=NULL;
    }
    else if((*cur)->left!=NULL&&(*cur)->right==NULL)
    {
        Node *big=(*cur)->left;
        while(big->left!=NULL)
        {
            big=big->left;
        }
        int val=big->number;
        (*cur)->number=val;
        eat_rat(&((*cur)->left),val);
    }
    else
    {
        Node *tmp=(*cur);
        if((*cur)->right->left==NULL)
        {
            (*cur)=(*cur)->right;
        }
        else
        {
            (*cur)=(*cur)->left;   
        }
        free(tmp);
    }
}