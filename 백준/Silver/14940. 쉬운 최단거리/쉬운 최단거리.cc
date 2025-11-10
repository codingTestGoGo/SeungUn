#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int goalx, goaly;
int updown[4] = {1, -1, 0, 0};
int leftright[4] = {0, 0, 1, -1};

void bfs(const vector<vector<int>> &map, vector<vector<int>> &visited, const pair<int, int> start)
{
    int starty = start.first, startx = start.second;

    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty())
    {
        const pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            const int nexty = front.first + updown[i];
            const int nextx = front.second + leftright[i];

            if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;

            if (!visited[nexty][nextx] && map[nexty][nextx] != 0)
            {
                visited[nexty][nextx] = visited[front.first][front.second] + 1;
                q.push({nexty, nextx});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                goalx = j; goaly = i;
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    bfs(map, visited, {goaly, goalx});

    visited[goaly][goalx] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i != goaly || j != goalx) && map[i][j] == 1 && visited[i][j] == 0)
            {
                cout << -1 << ' ';
            }
            else
                cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}