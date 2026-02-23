#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    if (n == 1) return money[0];

    // Case 1: 첫 번째 집을 포함하는 경우 (마지막 집은 제외)
    vector<int> dp1(n, 0);
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }

    // Case 2: 첫 번째 집을 제외하는 경우 (마지막 집 포함 가능)
    vector<int> dp2(n, 0);
    dp2[0] = 0;
    dp2[1] = money[1];
    for (int i = 2; i < n; i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }

    return max(dp1[n - 2], dp2[n - 1]);
}