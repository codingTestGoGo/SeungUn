#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    vector<int> dp(k+1, 100001);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int coin; cin >> coin;
        for (int j = coin; j <= k; ++j)
        {
            dp[j] = min(dp[j], dp[j-coin] + 1);
        }
    }

    if (dp[k] == 100001)
        cout << -1;
    else
        cout << dp[k];
}