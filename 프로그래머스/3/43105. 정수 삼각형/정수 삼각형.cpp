#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> dp(triangle.begin(), triangle.end());
    for (int row = 1; row < triangle.size(); row++)
    {
        const vector<int> &r = triangle[row];
        for (int i = 0; i < r.size(); i++)
        {
            if (i == 0)
                dp[row][i] += dp[row-1][i];
            else if (i == r.size()-1)
                dp[row][i] += dp[row-1][i-1];
            else
                dp[row][i] += max(dp[row-1][i], dp[row-1][i-1]);
        }
    }
    
    const vector<int> &last = dp[dp.size()-1];
    for (auto it : last)
    {
        answer = max(answer, it);
    }
    
    return answer;
}