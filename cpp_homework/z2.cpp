#include <iostream>
#include <iomanip>
using namespace std;
int n;
int r;
const int MAX_N=2005;
int x[MAX_N];
int y[MAX_N];
bool visited[MAX_N];
bool connected(int i,int j)
{
    int L=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    int R=r*r;
    return L<=R;
}

int dfs(int now)
{
    visited[now]=true;
    int res=1;
    for(int i=0;i<n;i++)
    {
        if(connected(now,i)==false)
        {
            continue;
        }
        if(visited[i]==true)
        {
            continue;
        }
        res+=dfs(i);
    }

    return res;
}

int main()
{
    cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    int single=0;
    int group=0;

    for(int i=0;i<n;++i)
    {
        if(visited[i]==true)
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
    cout<<single<<" "<<group<<endl;
}