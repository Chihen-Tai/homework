#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    int type;
    int var;
    char ch;
    struct _Node *left,*right;
}Node;

enum
{
    NUM,
    VAR,
    OP
};
Node*newNode(int type,int var,char ch)
{
    Node*new=(Node*)malloc(sizeof(Node));
    new->type=type;
    new->var=var;
    new->ch=ch;
    new->right=new->left=NULL;
    return new;
}
Node*buildTree()
{
    char exp[2000005];
    scanf("%s",exp);
    Node*now=NULL;
    if('x'<=exp[0]&&'z'>=exp[0])
    {
        now=newNode(VAR,0,exp[0]);
    }
    else if('0'<=exp[0]&&'9'>=exp[0])
    {
        now=newNode(NUM,atoi(exp),'\0');
    }
    else
    {
        now=newNode(OP,0,exp[0]);
        now->left=buildTree();
        now->right=buildTree();
    }
    return now;
}

int showans(Node*root,int x,int y,int z)
{
    if(root==NULL)
        return 0;
    switch (root->type)
    {
        case NUM:
            printf("%d",root->var);
            return root->var;
            break;
        case VAR:
            printf("%c",root->ch);
            if(root->ch=='x')
                return x;
            else if (root->ch=='y')
                return y;
            else if (root->ch=='z')
                return z;
            break;
        case OP:
        {   
            int l=showans(root->left,x,y,z);
            printf("%c",root->ch);
            int r=showans(root->right,x,y,z);
            if(root->ch=='+')
                return l+r;
            else if (root->ch=='-')
                return l-r;
            else if (root->ch=='*')
                return l*r;
            else if (root->ch=='/')
                return l/r;
            break;
        }
    }
}

int main()
{
    Node*root=buildTree();
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int ans=showans(root,x,y,z);
    printf("\n");
    printf("%d",ans);
    return 0;
}
