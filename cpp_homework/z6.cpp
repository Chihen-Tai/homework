#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;
const int MAX_N = 2005;
array<bool, MAX_N> visited;
array<array<bool, 26>, MAX_N> hasletter;
int n;

bool connected(int x, int y)
{
    for (int i = 0; i < 26; i++)
    {
        if (hasletter[x][i] && hasletter[y][i])
        {
            return true;
        }
    }
    return false;
}
void dfs(int now)
{
    visited[now] = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && connected(now, i))
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        visited.fill(false);
        hasletter.fill({false});
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            for(char &c:str)
            {
                hasletter[i][c-'a']=true;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i);
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}