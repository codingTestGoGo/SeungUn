#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> weights;
vector<vector<int>> graph;
vector<vector<vector<pair<int, bool>>>> childs;
vector<vector<int>> dp;

//1
//2
//3  6
//4  7
//5

void makeTree(int node, int parent)
{
    childs[0][node].resize(graph[node].size());
    childs[1][node].resize(graph[node].size());
    for (const int &child : graph[node])
    {
        if (child != parent)
        {
            makeTree(child, node);

            dp[1][node] += dp[0][child];
            childs[1][node].push_back({child, false});
            //printf("child[1][%d] -> {%d, false}\n", node, child);

            if (dp[0][child] >= dp[1][child])
            {
                dp[0][node] += dp[0][child];
                childs[0][node].push_back({child, false});
                //printf("child[0][%d] -> {%d, false}\n", node, child);
            }
            else
            {
                dp[0][node] += dp[1][child];
                childs[0][node].push_back({child, true});
                //printf("child[0][%d] -> {%d, true}\n", node, child);
            }
        }
    }

    dp[1][node] += weights[node];
    //printf("dp[0][%d] = %d, dp[1][%d] = %d\n",node, dp[0][node], node, dp[1][node]);
}

void countTree(int node, bool bSelected, vector<int> &result)
{
    if (bSelected)
        result.push_back(node);

    for (const pair<int, bool> &p : childs[bSelected][node])
    {
        countTree(p.first, p.second, result);
    }
}

int main()
{
    int n; cin >> n;
    weights.resize(n+1);
    graph.resize(n+1);
    childs.resize(2, vector<vector<pair<int, bool>>>(n+1));
    dp.resize(2, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    /*
        루트가 node인 트리의 최대 독립 집합은
        dp[1][node] = (dp[0][child]...) + node
        dp[0][node] = max(dp[0][child], dp[1][child]) ...
    */

    makeTree(1, -1);

    vector<int> result;
    if (dp[0][1] > dp[1][1])
    {
        cout << dp[0][1] << '\n';
        countTree(1, false, result);
    }
    else
    {
        cout << dp[1][1] << '\n';
        countTree(1, true, result);
    }

    sort(result.begin(), result.end());
    
    for (const int &n : result)
        cout << n << ' ';
}