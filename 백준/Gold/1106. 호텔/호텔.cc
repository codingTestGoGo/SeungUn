#include <iostream>
#include <vector>
#include <algorithm> // min 함수를 위해
#include <climits>   // INT_MAX를 위해

using namespace std;

// 무한대를 나타낼 큰 값 (INT_MAX는 덧셈 시 오버플로우 날 수 있으므로 적당히 큰 값 사용)
const int INF = 1e9;

int main()
{
    int c, n;
    cin >> c >> n;

    vector<pair<int, int>> v(n); // {cost, value}
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    // dp[i] = 정확히 i명의 고객을 모으는 데 드는 최소 비용
    // 문제의 조건(고객 수 최대 100)에 따라 C+100까지 확인
    // 배열 크기는 C+101 (인덱스 0 ~ C+100)
    vector<int> dp(c + 101, INF);

    // 0명을 모으는 데 드는 비용은 0
    dp[0] = 0;

    // 1명부터 C+100명까지 순차적으로 계산
    for (int j = 1; j <= c + 100; j++)
    {
        // 모든 아이템(도시)을 확인
        for (int i = 0; i < n; i++)
        {
            int cost = v[i].first;
            int value = v[i].second;

            // 현재 아이템을 사용해서 j명을 만들 수 있는 경우
            // (j - value >= 0) 이고, (j - value)명을 만드는 것이 가능했던 경우 (INF가 아님)
            if (j >= value && dp[j - value] != INF)
            {
                // 기존의 값 vs (j-value)명에서 현재 아이템을 추가한 값
                dp[j] = min(dp[j], dp[j - value] + cost);
            }
        }
    }

    // "최소 C명"이므로, C명부터 C+100명까지의 최소 비용을 찾는다.
    int min_cost = INF;
    for (int i = c; i <= c + 100; i++)
    {
        min_cost = min(min_cost, dp[i]);
    }

    cout << min_cost << endl;

    return 0;
}