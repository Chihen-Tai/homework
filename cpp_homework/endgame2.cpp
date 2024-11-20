#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int n, m;
int destory;
char table[1001][1001];
int ans;
// x,y,distance
queue<tuple<int, int, int>> q;

void bfs()
{
    while (!q.empty())
    {
        // tuple<int,int,int>data=q.front();
        // int x=get<0>(data);
        // int y=get<1>(data);
        // int dis=get<2>(data);
        auto [x, y, dist] = q.front();
        q.pop();
        if (x < 0 || x >= n || y < 0 || y >= m)
        {
            continue;
        }
        if (table[x][y] == 'C')
        {
            continue;
        }

        //'T' or'.'
        if (table[x][y] == 'T')
        {
            --destory;
            ans = max(ans, dist);
        }
        // set(x,y) visted;
        table[x][y] = 'C';
        q.push({x + 1, y, dist + 1});
        q.push({x - 1, y, dist + 1});
        q.push({x, y + 1, dist + 1});
        q.push({x, y - 1, dist + 1});
    }
}



int main()
{
    destory= ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (table[i][j] == 'I')
            {
                // find init point
                q.push({i, j, 0});
            }
            else if (table[i][j] == 'T')
            {
                // how many T
                destory++;
            }
        }
    }
    bfs();
    if (destory != 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << endl;
    }
}