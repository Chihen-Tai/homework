#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int n,m;
int destory;
queue<tuple<int,int,int>> q;
char table[1001][1001];
void bfs()
{
    while(!q.empty())
    {
        auto [x,y,dis]=q.front();
        q.pop();
        if(x<0||x>=n||y<0||x>=m)
        {
            continue;
        }
        if(table[x][y]=='C')
        {
            continue;
        }
    }
}

int main()
{
    destory=0;
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
            else if(table[i][j]=='T')
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

    }

}