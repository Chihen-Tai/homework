#include <stdio.h>
#include <string.h>

char a[26],toprint[26];
int n,k;
void per(int len)
{
    if(len==k)
    {
        toprint[len]='\0';
        printf("%s\n",toprint);
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            toprint[len]=a[i];
            per(len+1);
        }
    }
}
int main()
{
    scanf("%s",a);
    scanf("%d",&k);
    n=strlen(a);
    per(0);
}