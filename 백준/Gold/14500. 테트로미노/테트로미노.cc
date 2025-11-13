#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> map;
int updown[4] = {1, -1, 0, 0};
int leftrig[4] = {0, 0, 1, -1};
int res = 0;

void dfs(vector<vector<bool>> &visited, int count, int sum, int y, int x)
{
    if (count == 4)
    {
        if (sum > res) res = sum; 
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        const int nexty = y + updown[i];
        const int nextx = x + leftrig[i];
        if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;

        if (!visited[nexty][nextx])
        {
            visited[nexty][nextx] = true;
            dfs(visited, count + 1, sum + map[nexty][nextx], nexty, nextx);
            visited[nexty][nextx] = false;
        }
    }
}

void checkmnt(int sum, int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int nextsum = sum;
        int lefti = i-1 < 0 ? 3 : i-1;
        int righti = i+1 > 3 ? 0 : i+1;
        
        const int nexty = y + updown[i];
        const int nextx = x + leftrig[i];
        if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;

        nextsum += map[nexty][nextx];

        const int lefty = y + updown[lefti];
        const int leftx = x + leftrig[lefti];
        if (lefty < 0 || lefty >= n || leftx < 0 || leftx >= m) continue;

        nextsum += map[lefty][leftx];

        const int righty = y + updown[righti];
        const int rightx = x + leftrig[righti];
        if (righty < 0 || righty >= n || rightx < 0 || rightx >= m) continue;

        nextsum += map[righty][rightx];

        if (res < nextsum) res = nextsum;
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    map.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            dfs(visited, 1, map[i][j], i, j);
            visited[i][j] = false;
            checkmnt(map[i][j], i, j);
        }
    }

    cout << res;
}