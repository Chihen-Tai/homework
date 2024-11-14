#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int MAX_N=1005;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m;
int d = 0;
char table[MAX_N][MAX_N];
int ans;

queue<tuple<int ,int ,int>>q;

int bfs()
{
    while(!q.empty())
    {
        auto [x,y,dis]=q.front();
        q.pop();
        if(x<0||x>=n||y<0||y>=m)
        {
            continue;
        }
        if(table[x][y]=='C')
        {
            continue;
        }
        if(table[x][y]=='T')
        {
            ans=max(ans,dis);
            --d;
        }
        table[x][y]='C';
        for(int i=0;i<4;i++)
        {
            q.push({x+dx[i],y+dy[i],dis+1});
        }
    }    
    
    return ans;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%s",table[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(table[i][j]=='I')
            {
                q.push({i,j,0});
            }
            else if(table[i][j]=='T')
            {
                d++;
            }
        }
    }
    bfs();
    if(d==0)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
}