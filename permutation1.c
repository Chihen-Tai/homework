#include <stdio.h>
#include <string.h>
char c[23],to_print[23];
int n,k;
void permutation(int index)
{
    if(index==k)
    {
        to_print[index]='\0';
        printf("%s\n",to_print);
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            to_print[index]=c[i];
            permutation(index+1);//不能++
        }
    }
}

int main()
{
    scanf("%s",c);
    scanf("%d",&k);
    n=strlen(c);
    //printf("%d",n);
    permutation(0);
    return 0;
}