#include <iostream>
#include <string>
using namespace std;
bool visited[1000];
bool G[1000][1000]; 
int n;
void dfs(int now,int parent)
{
    visited[now]=true;
    for(int i=0;i<n-1;i++)
    {
        if(now==i) continue;
        if(now==parent)continue;
        if(!G[now][i])continue;
        if(visited[i]); // i is in cycle
        dfs(i,now);
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
            for(int j=0;j<n;j++)
            {
                G[i][j]=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a][b]=G[b][a]=true;
        }
        //output all number in the cycle
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,-1);
            }
        }
        //output max number of nodes in the cycle
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]&&i>ans)
            {
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
}