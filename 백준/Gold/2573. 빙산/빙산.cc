#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

//동, 서, 북, 남
int movey[4] = {0, 0, -1, 1};
int movex[4] = {1, -1, 0, 0};
int map[300][300];
int n, m;

void bfs(const pair<int, int> &start, vector<vector<int>> &visited, const int &IceCnt)
{
    visited[start.first][start.second] = IceCnt;
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty())
    {
        const pair<int, int> &cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            const int nexty = cur.first + movey[i];
            const int nextx = cur.second + movex[i];
            if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
                continue;

            //빙산인데 방문하지 않았다면
            if (map[nexty][nextx] != 0 && !visited[nexty][nextx])
            {
                visited[nexty][nextx] = IceCnt;
                q.push({nexty, nextx});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> visited(n, vector<int>(m));
    memset(map, 0, sizeof(map));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    bool bAllIceMelted = false;
    int year = 0;
    while  (!bAllIceMelted)
    {
        //1년이 지나 빙산이 녹는다.
        year++;
        bAllIceMelted = true;
        int temp[300][300];
        memcpy(temp, map, sizeof(temp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
                if (map[i][j] == 0) continue;
                bAllIceMelted = false;

                for (int k = 0; k < 4; k++)
                {
                    const int nexty = i + movey[k];
                    const int nextx = j + movex[k];
                    if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
                        continue;
                    
                    if (map[nexty][nextx] == 0)
                        temp[i][j] = max(0, temp[i][j]-1);
                }
            }
        }

        //얼음이 모두 녹았다면 0출력
        if (bAllIceMelted)
        {
            cout << 0;
            break;
        }

        memcpy(map, temp, sizeof(map));

        //빙산이 몇개인지 확인한다.
        int IceCnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 0 || visited[i][j] != 0) continue;
                
                //호수가 아니고 방문하지 않은 빙산 발견
                IceCnt++;

                //빙산이 2개이면 결과 출력
                if (IceCnt == 2)
                {
                    cout << year;
                    return 0;
                }
                bfs({i, j}, visited, IceCnt);
            }
        }

        // printf("\n================\n");
        // printf("year = %d\n", year);
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << map[i][j];
        //     }
        //     cout << '\n';
        // }
    }
}