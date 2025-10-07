#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

vector<int> map[100001];
int visited[100001];

void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        for (int nextNode : map[curNode])
        {
            if (!visited[nextNode]) 
            {
                visited[nextNode] = curNode;
                q.push(nextNode);
            }
        }
    }
}


int main()
{
    int n; cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int a, b; cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    bfs();

    for (int i = 2; i <= n; i++)
    {
        cout << visited[i] << '\n';
    }
}