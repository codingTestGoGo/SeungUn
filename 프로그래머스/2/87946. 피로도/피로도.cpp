#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxCount = 0;

bool backtracking(int k, int current, vector<bool> &visited, int visitedCount, const vector<vector<int>> &dungeons)
{
    visited[current] = true;
    visitedCount += 1;
    k -= dungeons[current][1];
    //cout << "visit " << current << '\n';
    
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i] && k >= dungeons[i][0])
        {
            if (backtracking(k, i, visited, visitedCount, dungeons))
                return true;
        }
    }
    
    maxCount = max(maxCount, visitedCount);
    //cout << maxCount << '\n';
    
    visited[current] = false;
    return false;
}

int solution(int k, vector<vector<int>> dungeons) {
    sort(dungeons.begin(), dungeons.end(), [](const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    });
    
    vector<bool> visited(dungeons.size(), false);
    for (int i = 0; i < dungeons.size(); i++)
    {
        
        backtracking(k, i, visited, 0, dungeons);
        //cout << '\n';
    }
    
    return maxCount;
}