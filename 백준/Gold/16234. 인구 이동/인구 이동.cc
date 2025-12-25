#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string.h>

using namespace std;
int map[50][50];
int ud[4] = {-1, 1, 0, 0};
int lr[4] = {0, 0, -1, 1};
int N, L, R;
bool visited[50][50];

bool check(const pair<int, int> &start)
{
    if (visited[start.first][start.second]) return false;

    set<pair<int, int>> s;
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nexty = cur.first + ud[i];
            int nextx = cur.second + lr[i];

            if (nexty < 0 || nexty >= N || nextx < 0 || nextx >= N || visited[nexty][nextx])
                continue;

            const int diff = abs(map[cur.first][cur.second] - map[nexty][nextx]);
            if (diff >= L && diff <= R)
            {
                visited[nexty][nextx] = true;
                s.insert(cur);
                s.insert({nexty, nextx});
                q.push({nexty, nextx});
            }
        }
    }

    if (s.empty())
        return false;

    int Total = 0;
    for (auto &p : s)
        Total += map[p.first][p.second];
    const int NewPopulation = Total / (int)s.size();
    
    for (auto &p : s)
    {
        map[p.first][p.second] = NewPopulation;
    }

    return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    int days = 0;
    bool bIsTransform = false;
    while (true)
    {
        memset(visited, false, sizeof(visited));
        bIsTransform = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (check({i, j}))
                {
                    //printf("check {%d, %d}\n", i, j);
                    bIsTransform = true;
                }
            }
        }

        if (!bIsTransform) break;
        days += 1;
        
        // printf("====days %d====\n", days);
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         printf("%d ", map[i][j]);
        //     }
        //     printf("\n");
        // }
    }

    cout << days;
}