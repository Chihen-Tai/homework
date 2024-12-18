#include <iostream>
#include <string>
#include <array>
#include <iomanip>
constexpr int MAX_N = 2000;
std::array<bool, MAX_N> visited;
std::array<std::string, MAX_N> str; // str[MAX_N]->string
int n;
bool connected(int x, int y)
{
    for (int i = 0; i < 26; i++)
    {
        // current char 'a'+i;
        bool findx = false;
        bool findy = false;
        for (char &c : str[x])
        {
            if (c == 'a' + i)
            {
                findx = true;
            }
        }
        for (char &c : str[y])
        {
            if (c == 'a' + i)
            {
                findy = true;
            }
        }
        if (findx && findy)
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
        if (visited[i])
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
    std::cin.tie(nullptr);
    // replace std::endl with '\n'
    int t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
         visited.fill(false);
        for (int i = 0; i < n; i++)
        {
            std::cin >> str[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
                ans++;
            }
        }
        std::cout<<ans<<"\n";
    }
}