#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void dfs(int k, int count, vector<bool> &visited, const vector<vector<int>> &dungeons) {
    answer = max(answer, count);

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(k - dungeons[i][1], count + 1, visited, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    vector<bool> visited(dungeons.size(), false);
    dfs(k, 0, visited, dungeons);
    
    return answer;
}