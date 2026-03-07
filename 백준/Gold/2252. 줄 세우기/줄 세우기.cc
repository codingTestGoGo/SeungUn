#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> entry(n+1, 0);
    vector<vector<int>> mp(n+1);
    queue<int> q;
    
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        mp[a].push_back(b);
        entry[b] += 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (entry[i] == 0)
            q.push(i);
    }


    while (!q.empty())
    {
        const int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (const int &next : mp[cur])
        {
            entry[next] -= 1;
            if (entry[next] == 0)
                q.push(next);
        }
    }
}