#include <iostream>
#include <iomanip>
#include <string>
int n,r;
const int max=2005;
int x[max],y[max];
bool visit[max];

int connected(int i,int j)
{
    int L=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    int R=r*r;
    return L<=R;
}

int dfs(int now)
{
    visit[now]=true;
    int res=1;
    for(int i=0;i<n;i++)
    {
        if(connected(now,i)==false)
        {
            continue;
        }
        if(visit[i]==true)
        {
            continue;
        }
        res+=dfs(i);
    }
    return res;
}

int main()
{
    std::cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        std::cin>>x[i]>>y[i];
    }

    int single=0;
    int group=0;

    for(int i=0;i<n;i++)
    {
        if(visit[i]==true)
        {
            continue;
        }

        int size=dfs(i);

        if(size==1)
        {
            single++;
        }
        else
        {
            group++;
        }
    }

    std::cout<<single<<" "<<group<<std::endl;
}