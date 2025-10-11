#include <iostream>
#include <vector>
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
}

int Kruscal(vector<tuple<int, int, int>> &graph, vector<int> &parents)
{
    sort(graph.begin(), graph.end());

    int cost = 0;
    for (const tuple<int ,int ,int> &tp : graph)
    {
        int dist = get<0>(tp);
        int v1 = get<1>(tp), v2 = get<2>(tp);
        if (Find(v1, parents) != Find(v2, parents))
        {
            cost += dist;
            Union(v1, v2, parents);
        }
    }

    return cost;
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true)
    {
        int m, n; cin >> m >> n;
        if (!m && !n) break;


        vector<tuple<int, int, int>> graph(n);
        vector<int> parents(m);

        for (int i = 0; i < m; i++)
            parents[i] = i;

        int TotalCost = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y, z; cin >> x >> y >> z;
            graph[i] = {z, x, y};
            TotalCost += z;
        }

        //printf("totalCost = %d\n", TotalCost);

        cout << TotalCost - Kruscal(graph, parents) << '\n';
    }
}