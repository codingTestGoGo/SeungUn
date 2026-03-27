#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define BIG_NUM 1000000007

int solution(int n, vector<int> money) {
    int answer = 0;
    
    sort(money.begin(), money.end());
    
    int dp[100000] = {0, };
    dp[0] = 1;
    for (int i = 0; i < money.size(); i++)
    {
        int mon = money[i];
        for (int j = mon; j <= n; j++)
        {
            dp[j] += (dp[j-mon] % BIG_NUM);
        }
    }
    
    return dp[n] % BIG_NUM;
}