#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
char table[1001][1001];
int n,m;
int destory;
int ans;
queue<tuple<int,int,int>> q;
void bfs();

int main()
{
    destory=ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>table[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(table[i][j]=='I')
            {
                q.push({i,j,0});
            }
            if(table[i][j]=='T')
            {
                destory++;
            }
        }
    }
    bfs();
    if(destory!=0)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<ans<<endl;
    }
}

void bfs()
{
    while(!q.empty())
    {
        auto [x,y,dis]=q.front();
        q.pop();
        if(x<0||y<0||x>=n||y>=m)
        {
            continue;
        }
        if(table[x][y]=='C')
        {
            continue;
        }
        if(table[x][y]=='T')
        {
            destory--;
            ans=max(dis,ans);
        }
        table[x][y]='C';

        q.push({x+1,y,dis+1});
        q.push({x,y+1,dis+1});
        q.push({x-1,y,dis+1});
        q.push({x,y-1,dis+1});

    }
}