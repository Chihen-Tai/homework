#include <iostream>
#include <vector>
using namespace std;
//這題我沒寫出來 草
vector<bool> visited;
vector<vector<int>> neighbor;
int ans;

void dfs(int now, int parent)
{
    visited[now] = true;
    for (int i : neighbor[now])
    {
        if (i == parent) continue;
        if (visited[i])
        {
            ans = i;
        }
        else
        {
            dfs(i, now);
        }
    }
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >> n;
        neighbor.resize(n);
        visited.resize(n);
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            neighbor[i].clear();
        }
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            neighbor[a].push_back(b);
            neighbor[b].push_back(a);
        }
        ans = -1;
        dfs(0, -1);
        cout << ans << endl;
    }
}