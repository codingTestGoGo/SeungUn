#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int NotTree = 0;

void bfs(int start, int num, vector<vector<int>> &graph, vector<int> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = num;

    vector<int> before(visited.size(), 0);
    bool bNotTree = false;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            //아직 방문하지 않았다면 큐에 넣는다.
            if (!visited[next])
            {
                before[next] = cur;
                visited[next] = num;
                q.push(next);
            }

            //방문했는데 현재 num이랑 같다면 사이클이므로 지금부터 탐색하는 노드들은 트리 찾기에서 제외한다.
            else if (!bNotTree && before[cur] != next && visited[next] == num)
            {
                NotTree++;
                bNotTree = true;
                //printf("num %d is not tree, NotTree = %d\n", num, NotTree);
            }
        }
    }
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cs = 1;
    while (true)
    {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        vector<vector<int>> graph(n+1);
        vector<int> visited(n+1, 0);

        for (int i = 0; i < m; i++)
        {
            int a, b; cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int num = 0;
        NotTree = 0;
        for (int node = 1; node <= n; node++)
        {
            //이미 방문한 노드라면 가지 않는다.
            if (visited[node]) continue;
            
            num += 1;
            //printf("num = %d\n", num);
            bfs(node, num, graph, visited);
        }

        int result = num - NotTree;

        cout << "Case " << cs << ':';
        if (result > 1)
            cout << " A forest of " << result << " trees.\n";
        else if (result == 1)
            cout << " There is one tree.\n";
        else
            cout << " No trees.\n";

        cs++;
    }
}