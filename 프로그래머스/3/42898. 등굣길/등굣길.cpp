#include <string>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

const int rest = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> visited(n, vector<int>(m, 1));
    for (int i = 0; i < puddles.size(); i++)
    {
        visited[puddles[i][1]-1][puddles[i][0]-1] = 0;   
    }
    
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (visited[r][c] == 0) continue;
            
            if (r == 0 && c > 0)
                visited[r][c] = visited[r][c-1] % rest;
            
            else if (c == 0 && r > 0)
                visited[r][c] = visited[r-1][c] % rest;
            
            else if (r > 0 && c > 0)
                visited[r][c] = (visited[r][c-1] + visited[r-1][c]) % rest;
        }
    }
    
    return visited[n-1][m-1];
}