#include <iostream>
#include <string>
#include <iomanip>

constexpr int MAX_N = 2000;

std::array<bool, MAX_N> visited;
std::array<std::array<bool, 26>, MAX_N> hasletter;
int n;

bool connected(int x, int y)
{
    for(int i=0;i<26;i++)
    {
        if(hasletter[x][i]&&hasletter[y][i])
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
        if (visited[i] == true)
        {
            continue;
        }
        if (connected(now, i))
        {
            dfs(i);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while(t--)
    {
        visited.fill(false);
        hasletter.fill({false});
        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            std::string str;
            std::cin>>str;
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
        std::cout<<ans<<"\n";
    }
}