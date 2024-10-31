#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    NUM,
    VAR,
    OP
};

typedef struct _Node
{
    int type;
    int var;
    char ch;
    struct _Node *left,*right;
}Node;

Node*makenode(int type,int var,int ch)
{
    Node* now=(Node*)malloc(sizeof(Node));
    now->left=now->right=NULL;
    now->type=type;
    now->var=var;
    now->ch=ch;
    return now;
}

Node*buildtree()
{
    char exp[2000005];
    scanf("%s",exp);
    Node*now=NULL;
    if('0'<=exp[0]&&'9'>=exp[0])
    {
        now=makenode(NUM,atoi(exp),'\0');
    }
    else if('x'<=exp[0]&&'z'>=exp[0])
    {
        now=makenode(VAR,0,exp[0]);
    }
    else
    {
        now=makenode(OP,0,exp[0]);
        now->left=buildtree();
        now->right=buildtree();
    }
    return now;
}

int show_inorder(Node*root,int x,int y,int z)
{
    if(root==NULL)
        return 0;
    else
    {
        switch(root->type)
        {
            case NUM:
                printf("%d",root->var);
                return root->var;
                break;
            case VAR:
                printf("%c",root->ch);
                if(root->ch=='x')
                    return x;
                else if(root->ch=='y')
                    return y;
                else if(root->ch=='z')
                    return z;
                break;
            case OP:
            {
                int l=show_inorder(root->left,x,y,z);
                printf("%c",root->ch);
                int r=show_inorder(root->right,x,y,z);
                if(root->ch=='+')
                    return l+r;
                else if(root->ch=='-')
                    return l-r;
                else if(root->ch=='*')
                    return l*r;
                else if(root->ch=='/')
                    return l/r;
                break;
            }
        }

    }
}

int main()
{
    Node*root=buildtree();
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int ans=show_inorder(root,x,y,z);
    printf("\n");
    printf("%d",ans);
}