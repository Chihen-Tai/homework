#include <iostream>
#include <string>
#include <array>
#include <iomanip>
constexpr int MAX_N = 2000;
std::array<bool, MAX_N> visited;
//std::array<std::string, MAX_N> str; // str[MAX_N]->string
std::array<std::array<bool, 26>, MAX_N> hasLetter;
int n;
// bool connected(int x, int y)
// {
//     for (auto &c1 : str[x])
//     {
//         for (char &c2 : str[y])
//         {
//             if (c1 == c2)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
bool connected(int x, int y)
{
    for(int i=0;i<26;i++)
    {
        if(hasLetter[x][i]&&hasLetter[y][i])
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // replace std::endl with '\n'
    int t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        visited.fill(false);
        hasLetter.fill({false});
        //read string
        for (int i = 0; i < n; i++)
        {
           std::string str;
           std::cin>>str;
           for(char &c:str)
           {
            hasLetter[i][c-'a']=true;
           }
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