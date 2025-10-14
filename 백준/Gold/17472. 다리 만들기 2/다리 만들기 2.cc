#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int Find(int a, vector<int> &parents)
{
    if (parents[a] != a)
        parents[a] = Find(parents[a], parents);
    
    return parents[a];
}

void Union(int a, int b, vector<int> &parents)
{
    a = Find(a, parents);
    b = Find(b, parents);

    if (a == b)
        return;
    
    parents[a] = b;
    //printf("Union %d %d\n", a, b);
}

int Kruscal(int island_count, vector<tuple<int, int, int>> &graph, vector<int> &parents)
{
    sort(graph.begin(), graph.end());

    int cost = 0;
    int edges = 0;
    for (const tuple<int ,int ,int> &tp : graph)
    {
        int dist = get<0>(tp);
        int v1 = get<1>(tp) - 1, v2 = get<2>(tp) - 1;
        if (Find(v1, parents) != Find(v2, parents))
        {
            cost += dist;
            Union(v1, v2, parents);
            edges++;
        }
    }

    if (cost <= 0) return -1;
    
    // 모든 섬이 연결되었는지 확인 (연결된 간선의 수가 섬 개수 - 1 이어야 함)
    if (island_count > 1 && edges != island_count - 1) {
        return -1;
    }
    
    return cost;
}

void bfs(vector<vector<int>> &map, vector<vector<bool>> &visited, pair<int, int> start, int N, int M, int number, vector<pair<int, pair<int, int>>> &islands)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    map[start.first][start.second] = number;
    islands.push_back({number, start});

    int rl[4] = {1, -1, 0, 0};
    int dt[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        //동서남북 순서대로 판단한다.
        for (int i = 0; i < 4; i++)
        {
            int x = cur.second + rl[i];
            int y = cur.first + dt[i];
            
            if (x < 0 || x >= M || y < 0 || y >= N) continue;

            if (visited[y][x]) continue;

            if (map[y][x] < 1) continue;

            visited[y][x] = true;
            map[y][x] = number;
            q.push({y, x});
        }
    }
}

bool bfs2(vector<vector<int>> &map, int N, int M, const pair<int, pair<int, int>> &island, vector<tuple<int, int, int>> &graph)
{
    //visited 정보 {거리, 방향 (전방향 = -1)}
    vector<vector<pair<int, int>>> visited(N, vector<pair<int, int>>(M, {0, -1}));\
    queue<pair<int, int>> q;

    int number = island.first;
    pair<int, int> start = island.second;

    visited[start.first][start.second].first = 1;
    q.push(start);

    int rl[4] = {1, -1, 0, 0};
    int dt[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        //printf("q.size() = %d, visited[%d][%d] = {%d, %d}\n",q.size(), cur.first, cur.second, visited[cur.first][cur.second].first, visited[cur.first][cur.second].second);

        if (visited[cur.first][cur.second].second == -1)
        {
            //동서남북 순서대로 판단한다.
            for (int i = 0; i < 4; i++)
            {
                int x = cur.second + rl[i];
                int y = cur.first + dt[i];

                if (x < 0 || x >= M || y < 0 || y >= N) continue;

                if (visited[y][x].first) continue;

                //map에 도착한 지점이 같은 번호라면 아직 같은 섬을 안벗어난 것이기 때문에 dist는 증가하지 않는다.
                if (map[y][x] == number)
                {
                    visited[y][x] = visited[cur.first][cur.second];
                    q.push({y, x});
                }

                //map에 도착한 지점이 바다(0)라면 dist를 1 증가시킨다.
                //그리고 바다는 같은 방향으로 쭉 나가야 한다.
                else if (map[y][x] == 0)
                {
                    visited[y][x].first = visited[cur.first][cur.second].first + 1;
                    visited[y][x].second = i;
                    q.push({y, x});
                }

                //map에 도착한 지점이 섬이라면.. 이 경우는 말이안된다.
                // 같은 숫자도 아닌 대륙이 이 number섬과 붙어있는 경우이므로
                // 애초에 bfs를 잘못한 것
                else
                {
                    //printf("return false! visited[%d][%d] = {%d, %d}\n", cur.first, cur.second, visited[cur.first][cur.second].first, visited[cur.first][cur.second].second);
                    return false;
                }
            }
        }
        //방향이 정해져 있다면 그쪽으로만 탐색한다.
        else
        {
            int way = visited[cur.first][cur.second].second;
            int x = cur.second + rl[way];
            int y = cur.first + dt[way];

            if (x < 0 || x >= M || y < 0 || y >= N) continue;

            if (visited[y][x].first) continue;

            //map에 도착한 지점이 같은 번호라면 아직 같은 섬을 안벗어난 것이기 때문에 dist는 증가하지 않는다.
            if (map[y][x] == number)
            {
                visited[y][x] = visited[cur.first][cur.second];
                q.push({y, x});
            }

            //map에 도착한 지점이 바다(0)라면 dist를 1 증가시킨다.
            //그리고 바다는 같은 방향으로 쭉 나가야 한다.
            else if (map[y][x] == 0)
            {
                visited[y][x].first = visited[cur.first][cur.second].first + 1;
                visited[y][x].second = way;
                q.push({y, x});
            }

            //map에 도착한 지점이 대륙이라면, 해당 대륙과의 최소거리를 기록한다.
            //만약 다리 길이가 1 이하라면 무시한다.
            //섬을 가로질러 가는 다리는 없기 때문에 큐에 넣지 않는다.
            else
            {
                visited[y][x].first = visited[cur.first][cur.second].first;
                visited[y][x].second = way;

                if (visited[y][x].first - 1 <= 1) continue;
                graph.push_back({visited[y][x].first - 1, number, map[y][x]});
            }
        }
    }

    return true;
}




int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
         cin >> map[i][j];
    }

    //섬의 번호를 지정하고, 각 섬과의 거리를 구해 최소신장트리를 구한다.
    //1. 섬의 번호를 지정하기 위해 bfs로 탐색한다.

    int number = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<pair<int, pair<int, int>>> islands;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] >= 1 && !visited[i][j])
            {
                number += 1;
                bfs(map, visited, {i, j}, N, M, number, islands);
            }
        }
    }

    //맵 출력(디버깅)
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    //2. 섬과 섬사이의 거리를 튜플로 저장한다. {거리, 섬1, 섬2}
    //섬을 돌며 bfs로 구한다.

    // 2. 모든 가능한 다리 찾기 (4방향 모두 탐색)
    vector<tuple<int, int, int>> graph;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 0) continue;

            int start_island = map[i][j];

            // 오른쪽 방향 탐색
            int len = 0;
            for (int k = j + 1; k < M; ++k) {
                if (map[i][k] == start_island) break;
                if (map[i][k] == 0) {
                    len++;
                } else {
                    if (len >= 2) {
                        graph.push_back({len, start_island, map[i][k]});
                    }
                    break;
                }
            }
            
            // 아래쪽 방향 탐색
            len = 0;
            for (int k = i + 1; k < N; ++k) {
                if (map[k][j] == start_island) break;
                if (map[k][j] == 0) {
                    len++;
                } else {
                    if (len >= 2) {
                        graph.push_back({len, start_island, map[k][j]});
                    }
                    break;
                }
            }
            // 왼쪽, 위쪽 방향은 탐색할 필요 없음
            // 모든 땅에서 오른쪽/아래만 탐색해도 모든 다리 쌍(A->B)이 한 번씩 발견됨
        }
    }

    //graph 출력 (디버깅)
    // printf("graph\n");
    // for (const tuple<int, int, int> &tp : graph)
    //     printf("{%d %d %d}\n", get<0>(tp),get<1>(tp),get<2>(tp));

    //3. 최소 신장 트리를 구한다.
    //만약 가능한 다리 갯수가 섬의 갯수 - 1보다 작으면 불가능하기 때문에 -1을 출력한다.
    if (graph.size() < islands.size()-1)
    {
        cout << -1;
        return 0;
    }

    vector<int> parents(islands.size());
    for (int i = 0; i < parents.size(); i++)
        parents[i] = i;

    cout << Kruscal(number, graph, parents);
}