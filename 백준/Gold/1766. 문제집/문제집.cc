#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
  
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n+1);
    priority_queue<int, vector<int>, greater<>> pq;
    vector<int> entry(n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        mp[a].push_back(b);
        entry[b] += 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (entry[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        const int cur = pq.top();
        pq.pop();
        cout << cur << ' ';

        for (const int &next : mp[cur])
        {
            entry[next]--;
            if (!entry[next])
                pq.push(next);
        }
    }
}