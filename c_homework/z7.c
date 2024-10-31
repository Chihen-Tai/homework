#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node *right,*left;
}Node;

int flag=1;
int postIndex=0;
int *genpostorder;
int find_mid(int *in,int len,int num)
{
    for(int i=0;i<len;i++)
    {
        if(in[i]==num)
        {
            return i;
        }
    }
    return len;
}

Node *buildTree(int *pre,int*in,int len)
{
    if(len==0)
        return NULL;
    Node*now=(Node*)malloc(sizeof(Node));
    now->number=pre[0];
    int mid=find_mid(in,len,pre[0]);
    if(mid==len)
    {
        flag=0;
        return NULL;
    }
    now->left=buildTree(pre+1,in,mid);
    now->right=buildTree(pre+mid+1,in+mid+1,len-mid-1);
    return now;
}

void postorder(Node*now)
{
    if(now==NULL)
        return;
    postorder(now->left);
    postorder(now->right);
    genpostorder[postIndex++]=now->number;
}

int check_same(int *a,int *b,int len)
{
    for(int i=0;i<len;i++)
    {
        if(a[i]!=b[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n,q,qs;
    int *inorder,*preorder,*inputpostorder;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        preorder=(int*)malloc(n*sizeof(int));
        inputpostorder=(int*)malloc(n*sizeof(int));
        genpostorder=(int*)malloc(n*sizeof(int));

        for(int i=0;i<n;i++)
        {
            scanf("%d",&preorder[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&inputpostorder);
        }
        scanf("%d",&qs);
        while(qs--)
        {
            flag=1;
            postIndex=0;
            inorder=(int*)malloc(n*sizeof(int));

            for(int i=0;i<n;i++)
            {
                scanf("%d",&inorder[i]);
            }

            Node*root=buildTree(preorder,inorder,n);
            if(flag==0)
            {
                
            }
        }
    }
}