#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int map[20][20];
int n; 
int ud[4] = {-1, 1, 0, 0};
int lr[4] = {0, 0, -1, 1};
int fishCount = 0;
int TotalTime = 0;

//양수면 p1(유지), 음수면 p2
int CompareFish(const pair<int, int> &p1, const pair<int, int> &p2, const int visited[20][20])
{
    //거리가 다르다면 리턴
    if (visited[p1.first][p1.second] != visited[p2.first][p2.second])
    {
        return  visited[p2.first][p2.second] - visited[p1.first][p1.second];
    }

    //거리가 같다면 y좌표 비교
    if (p1.first != p2.first)
    {
        return p2.first - p1.first;
    }

    //거리도 같고, y좌표도 같다면 x죄표 비교
    return p2.second - p1.second;
}

bool bError = false;
bool bfs(pair<int, int> &start, int &SharkSize, int &EatenFish)
{
    int FishCounttmp = fishCount;
    queue<pair<int ,int>> q;
    q.push(start);

    //방문안함 = -1
    int visited[20][20];
    memset(visited, -1, sizeof(visited));
    visited[start.first][start.second] = 0;

    pair<int, int> closestFish;
    bool bFoundFish = false;
    while (!q.empty())
    {
        const pair<int, int> cur = q.front();
        q.pop();

        //printf("cur = {%d, %d}\n", cur.first, cur.second);

        for (int ar = 0; ar < 4; ar++)
        {
            pair<int, int> next;
            next.first = cur.first + ud[ar];
            next.second = cur.second + lr[ar];
            //printf("next {%d, %d}\n", next.first, next.second);

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
                continue;

            if (visited[next.first][next.second] == -1 && map[next.first][next.second] <= SharkSize)
            {
                //printf("bfs {%d, %d}\n", next.first, next.second);
                visited[next.first][next.second] = visited[cur.first][cur.second] + 1;
                q.push(next);

                //만약 물고기가 있다면 가장 가까운 물고기 인지 비교 시작
                if (map[next.first][next.second] > 0 && map[next.first][next.second] < SharkSize)
                {
                    //rintf("found Fish = %d, dist = %d\n", map[next.first][next.second], visited[next.first][next.second]);
                    if (!bFoundFish)
                    {
                        closestFish = next;
                    }
                    else
                    {
                        int res = CompareFish(closestFish, next, visited);
                        if (res > 0)
                        {
                            //유지
                        }
                        else if (res < 0)
                        {
                            //유지
                            closestFish = next;
                        }
                        else
                        {
                            printf("Something wrong...\n");
                            bError = true;
                            return false;
                        }
                    }
                    
                    bFoundFish = true;
                    FishCounttmp--;
                    //printf("closest Fish = {%d, %d}\n", closestFish.first, closestFish.second);

                    if (FishCounttmp == 0)
                        break;
                }
            }
        }

        if (FishCounttmp == 0)
        break;
    }

    //가장 가까운 생선이 있으면 먹는다.
    if (bFoundFish)
    {
        //이동
        //printf("move shark {%d, %d} -> {%d, %d}\n", start.first, start.second, closestFish.first, closestFish.second);
        start = closestFish;
        map[closestFish.first][closestFish.second] = 0;

        EatenFish += 1;
        fishCount--;
        if (EatenFish == SharkSize)
        {
            SharkSize += 1;
            EatenFish = 0;
            //printf("sharkSize up to %d\n", SharkSize);
        }

        //이동 거리만큼 시간 갱신
        TotalTime += visited[closestFish.first][closestFish.second];
        return true;
    }
    
    //물고기를 찾지 못했다면, 먹을 수 있는 물고기가 없는 경우이다.
    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;

    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                start = {i, j};
            }
            //9, 0이 아니면 물고기
            else if (map[i][j] != 0)
            {
                fishCount++;
            }
        }
    }

    int sharkSize = 2; int EatenFish = 0;
    map[start.first][start.second] = 0;
    while (fishCount)
    {
        bool bResult = bfs(start, sharkSize, EatenFish);
        if (!bResult)
        {
            break;
        }
        if (bError)
        {
            break;
        }

        // printf("\n=======\n");
        // printf("left fish count = %d\n", fishCount);
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i == start.first && j == start.second)
        //             printf("9");
        //         else
        //             printf("%d",map[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("=======\n\n");
    }

    cout << TotalTime;
}