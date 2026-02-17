#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int FindTreeSize(int startNode, int ignoreNode, int n, const vector<vector<int>> &adj)
{
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(startNode);
    visited[startNode] = true;
    int cnt = 1;
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int next : adj[cur])
        {
            if (next == ignoreNode) continue; 
            
            if (!visited[next])
            {
                visited[next] = true;
                cnt++;
                q.push(next);
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    vector<vector<int>> adj(n);
    for (const auto &w : wires) {
        adj[w[0] - 1].push_back(w[1] - 1);
        adj[w[1] - 1].push_back(w[0] - 1);
    }
    
    for (const auto &w : wires) {
        int v1 = w[0] - 1;
        int v2 = w[1] - 1;
        
        int cnt = FindTreeSize(v1, v2, n, adj);
        int diff = abs(cnt - (n - cnt));
        answer = min(answer, diff);
    }
    
    return answer;
}