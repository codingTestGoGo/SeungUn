#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<pair<int, int>> viruses;
vector<pair<int, int>> SafeZones;
vector<vector<int>> Map;

int updown[4] = {1, -1, 0, 0};
int leftRight[4] = {0, 0, -1, 1};

int CheckCount(vector<vector<int>> &TempMap)
{
    //바이러스에 전부 감염되었는지 판단
    int Count = 0;
    for (const pair<int, int> &SafeZone : SafeZones)
    {
        if (TempMap[SafeZone.first][SafeZone.second] == 0)
            Count++;
    }

    return Count;
}

bool bfs_virus(const pair<int, int> &virus, vector<vector<int>> &TempMap)
{
    queue<pair<int, int>> q;
    q.push(virus);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        //printf("{%d, %d}\n", cur.first, cur.second);
        // 안전 지대가 아니라면 검사할 필요가 없다.
        if (!TempMap[cur.first][cur.second])
            continue;

        for (int i = 0; i < 4; i++)
        {
            const int upi = cur.first + updown[i];
            if (upi >= n || upi < 0) continue;

            const int lri = cur.second + leftRight[i];
            if (lri >= m || lri < 0) continue;

            if (TempMap[upi][lri] == 0)
            {
                q.push({upi, lri});
                TempMap[upi][lri] = 2;
            }
        }
    }

    //SafeZone이 없다면 바이러스 막기 실패
    if (CheckCount(TempMap) == 0)
        return false;

    return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    vector<vector<int>> map;
    map.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                viruses.push_back({i, j});
            else if (map[i][j] == 0)
                SafeZones.push_back({i, j});
        }
    }

    //일단 바이러스를 다 퍼지지 못하게 하는 거에 중점을 둘까
    //바이러스를 순차적으로 재귀 bfs로다가
    //1번 바이러스를 퍼지지 못하게 벽을 세우는 데에 성공하면 다음 바이러스 벽 시도 하는 느낌으로다가
    //퍼지지 못하게 벽을 세우는데에가 ㅈㄴ 어렵네 벽을 보이는 곳에 세우고 bfs를 끝까지 돌아야 하는 거 아니야
    //그럴 바엔 차라리 빈칸들을 모아서 3개 선택하는게 좋아보이네
    
    const int SafeZonesCount = SafeZones.size();
    int MaxCount = 0;
    for (int i = 0; i < SafeZonesCount; i++)
    {
        for (int j = i+1; j < SafeZonesCount; j++)
        {
            for (int k = j+1; k < SafeZonesCount; k++)
            {
                const pair<int, int> p1 = SafeZones[i];
                const pair<int, int> p2 = SafeZones[j];
                const pair<int, int> p3 = SafeZones[k];

                vector<vector<int>> TempMap(map);
                TempMap[p1.first][p1.second] = 1;
                TempMap[p2.first][p2.second] = 1;
                TempMap[p3.first][p3.second] = 1;

                bool bSucceed = true;
                for (const pair<int, int> &virus : viruses)
                {
                    if (!bfs_virus(virus, TempMap))
                    {
                        bSucceed = false;
                        break;
                    }
                }

                if (bSucceed)
                {
                    int Count = CheckCount(TempMap);
                    if (Count > MaxCount)
                        MaxCount = Count;
                }
            }
        }
    }

    cout << MaxCount;

}