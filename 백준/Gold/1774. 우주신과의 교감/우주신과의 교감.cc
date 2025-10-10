#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

vector<int> parents;
vector<int> level;

int Find(int a)
{
    if (parents[a] != a)
    {
        parents[a] = Find(parents[a]);
    }

    return parents[a];
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return;
    
    if (level[a] < level[b])
    {
        parents[a] = b;
    }
    else if (level[a] > level[b])
    {
        parents[b] = a; 
    }
    else
    {
        parents[a] = b;
        level[b]++;
    }
}

double dist(pair<long long, long long> p1, pair<long long, long long> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

long double kruscal(vector<tuple<double, long long, long long>> &space)
{
    long double cost = 0;
    sort(space.begin(), space.end());

    for (const auto &tp : space)
    {
        int v1 = get<1>(tp), v2 = get<2>(tp);
        //printf("{%f %d %d}\n", get<0>(tp), v1, v2);
        if (Find(v1) != Find(v2))
        {
            Union(v1, v2);
            cost += get<0>(tp);
        }
    }

    return cost;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n, m; cin >> n >> m;
   vector<tuple<double, long long, long long>> space;
   vector<pair<long long, long long>> nodes(n);
   parents.resize(n);
   level.resize(n, 0);

   for (int i = 0; i < n; i++)
   {
        cin >> nodes[i].first >> nodes[i].second;
        parents[i] = i;
   }

   for (int i = 0; i < m; i++)
   {
        //이미 연결된 통로는 비용이 0이다.
        int start, end; cin >> start >> end;
        Union(start-1, end-1);
   }

   for (int i = 0; i < n; i++)
   {
        for (int j = i+1; j < n; j++)
        {
            if (i == j) continue;

            double d = dist(nodes[i], nodes[j]);
            space.push_back({d, i, j});
        }
   }

   cout << fixed;
   cout.precision(2);
   cout << kruscal(space);
}