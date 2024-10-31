#include <stdio.h>
#include <stdlib.h>
typedef struct _NODE {
    int num, id;
    struct _NODE *left, *right;
} Node;
int arr[2000005];
Node*build_tree( int *arr, int l, int r) {
    if(l>r) return NULL;
    Node *now = (Node*)malloc(sizeof(Node));
    if(l==r) {
        now->num=arr[l];
        now->id=l;
    }
    else {
        int mid=(l+r)/2;
        now->num=arr[mid];
        now->id=mid;
        now->left=build_tree(arr,l,mid-1);
        now->right=build_tree(arr,mid+1,r);
    }
    return now;
}
int search(Node *now, int x) {
    if(now==NULL) return -1;
    if(now->num==x)
        return now->id;
    else if(now->num>x)
        return search(now->left,x);
    else if(now->num<x)
        return search(now->right,x);
}

void freeBST(Node *root){
    if(root == NULL) return;
    /*do it your self*/
}

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        Node*root=build_tree(arr,0,n-1);
        while(q--)
        {
            int tar;
            scanf("%d",&tar);
            int ans = search(root,tar);
            if(ans==-1)
            {
                printf("Break your bridge!\n");
            }
            else
            {
                printf("%d\n",ans+1);
            }
        }
    }
}