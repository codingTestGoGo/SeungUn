#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> buses;
int n, m;

int dijkstra(int start, int end)
{
    vector<int> visited(n+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    visited[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        const pair<int, int> cur = pq.top();
        pq.pop();

        if (visited[cur.second] < cur.first) continue;

        //printf("cur = %d\n", cur.second);
        for (const pair<int, int> p : buses[cur.second])
        {
            int nextNode = p.second;
            int NewDist = visited[cur.second] + p.first;
            if (NewDist < visited[nextNode])
            {
                pq.push({NewDist, nextNode});
                visited[nextNode] = NewDist;
            }
        }
    }

    return visited[end];
}

int main()
{
    cin >> n >> m;
    buses.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int start, end, cost; cin >> start >> end >> cost;
        buses[start].push_back({cost, end});
    }

    int start, end; cin >> start >> end;
    cout << dijkstra(start, end);
}