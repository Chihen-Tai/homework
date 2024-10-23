#include <stdio.h>
#include <stdlib.h>
enum
{
    NUM,//0
    VAL,//1
    OP//2
};

#define MAX_N 2000005
typedef struct _Node
{
    int val;
    int type;//type=0->number,type=1->valriable,type=2>operator
    char ch;
    struct _Node *left,*right;
}Node;

Node* new_node(int type,int val,char ch)
{
    Node*p=(Node*)malloc(sizeof(Node));
    p->left=p->right=NULL;
    p->type=type,p->val=val,p->ch=ch;
    return p;
}

Node* buildTree()
{
    char exp[MAX_N+1];
    scanf("%s",exp);
    printf("%s\n", exp);
    Node* now=NULL;
    if('0'<=exp[0]&&exp[0]<='9')
    {
        now=new_node(NUM,atoi(exp),'\0');
    }
    else if('x'<=exp[0]&&exp[0]<='z')
    {
        now=new_node(VAL,0,exp[0]);
        //變數下面不需要分左右
    }
    else
    {
        now=new_node(OP,0,exp[0]);
        now->left=buildTree();
        now->right=buildTree();
    }

    return now;
}

int show_inorder(Node*now,int x,int y,int z)
{
    if(now==NULL)
        return 0;
    int l;
    int r;
    switch(now->type)
    {
        case NUM:
            printf("%d",now->val);
            return now->val;
            break;
        case VAL:
            printf("%c",now->ch);
            if(now->ch=='x')
                return x;
            else if(now->ch=='y')
                return y;
            else if(now->ch=='z')
                return z;
            break;
        case OP:
            l=show_inorder(now->left,x,y,z);
            printf("%c",now->ch);
            r=show_inorder(now->right,x,y,z);
            if(now->ch=='+')
                return l+r;
            else if(now->ch=='-')
                return l-r;
            else if(now->ch=='*')
                return l*r;
            else if(now->ch=='/')
                return l/r;
            break;
    }

}

int main()
{
    Node *root = buildTree();
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    
    int ans=show_inorder(root, x, y, z);
    printf("\n");
  	printf("%d",ans);

    return 0;
}
