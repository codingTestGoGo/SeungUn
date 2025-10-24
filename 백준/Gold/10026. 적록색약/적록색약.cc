#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;

int n;
int updown[4] = {1, -1, 0, 0};
int leftright[4] = {0, 0, -1, 1};

void bfs(pair<int, int> start, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push(start);

    int color = map[start.first][start.second];
    //printf("start{%d, %d}, color = %c\n", start.first, start.second, color);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next;
            next.first = cur.first + updown[i];
            next.second = cur.second + leftright[i];

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
                continue;

            if (!visited[next.first][next.second] && color == map[next.first][next.second])
            {
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
}

void bfs_ColorBlindless(pair<int, int> start, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push(start);

    int color = map[start.first][start.second];
    if (color == 'G')
        color = 'R';

    //printf("start{%d, %d}, color = %c\n", start.first, start.second, color);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next;
            next.first = cur.first + updown[i];
            next.second = cur.second + leftright[i];

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
                continue;

            int nextColor = map[next.first][next.second];
            if (nextColor == 'G')
                nextColor = 'R';

            if (!visited[next.first][next.second] && color == nextColor)
            {
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> n;
    map.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch; cin >> ch;
            map[i][j] = ch;
        }
    }

    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%c", map[i][j]);
    //     }
    //     printf("\n");
    // }


    int count = 0, CBcount = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<bool>> visited_ColorBlindless(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                count += 1;
                bfs({i, j}, visited);
            }
            
            if (!visited_ColorBlindless[i][j])
            {
                visited_ColorBlindless[i][j] = true;
                CBcount += 1;
                bfs_ColorBlindless({i, j}, visited_ColorBlindless);
            }
        }
    }

    cout << count << ' ' << CBcount;
}