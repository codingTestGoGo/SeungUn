#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<vector<int>> childs;
vector<vector<int>> graph;
vector<int> countries;

//0 : 우수 마을일 때, 1: 우수 마을이 아닐 때
vector<vector<int>> dp;

void MakeTree(int node, int parent)
{
    childs[node].reserve(graph[node].size());

    for (const int &next : graph[node])
    {
        if (next != parent)
        {
            parents[next] = node;
            childs[node].push_back(next);

            //자식들 게산 후
            MakeTree(next, node);

            //우수마을 인 경우
            dp[0][node] += dp[1][next];

            //우수 마을이 아닌 경우
            dp[1][node] += max(dp[0][next], dp[1][next]);
        }
    }

    //우수 마을인 경우는 자기 자신을 더해야 한다.
    dp[0][node] += countries[node];
}

int main()
{
    int n; cin >> n;

    countries.resize(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> countries[i];

    graph.resize(n+1);
    childs.resize(n+1);
    parents.resize(n+1, -1);

    dp.resize(2, vector<int>(n+1, 0));
    for (int i = 0; i < n-1; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //node가 우수 마을일 때 주민수의 총합은
    //node의 자식들은 우수마을이 아닐때 총합 + node의 주민 수

    //node가 우수 마을이 아닐 때 주민수 총합은
    //node의 자식들이 우수마을인 경우와 우수마을이 아닌 경우 중 큰 것
    MakeTree(1, -1);

    cout << max(dp[0][1], dp[1][1]);
}