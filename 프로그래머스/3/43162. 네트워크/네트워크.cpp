#include <string>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        
        answer += 1;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for (int j = 0; j < n; j++)
            {
                if (j == cur) continue;
                if (!visited[j] && computers[cur][j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
    
    return answer;
}