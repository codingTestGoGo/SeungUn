#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visited;

// current 노드를 루트로 하는 서브트리의 DP 값을 계산하는 함수
void solve(int current) {
    visited[current] = true;

    // dp[current][1]: 현재 노드가 얼리 어답터인 경우. 비용이 1에서 시작.
    // dp[current][0]: 현재 노드가 얼리 어답터가 아닌 경우. 비용이 0에서 시작.
    dp[current][1] = 1;
    dp[current][0] = 0;

    for (int next : graph[current]) {
        if (!visited[next]) {
            // 자식 서브트리의 문제를 먼저 재귀적으로 해결
            solve(next);

            // 자식의 결과값을 이용해 현재 노드의 DP 값을 갱신

            // 경우 1: 'current'가 얼리 어답터가 아닌 경우
            // 모든 자식('next')은 반드시 얼리 어답터여야 함
            dp[current][0] += dp[next][1];

            // 경우 2: 'current'가 얼리 어답터인 경우
            // 자식('next')은 얼리 어답터이거나 아니거나 상관 없으므로,
            // 각 자식 서브트리에서 더 비용이 적은 쪽을 선택
            dp[current][1] += min(dp[next][0], dp[next][1]);
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    graph.resize(n + 1);
    // dp[i][0] -> 노드 i가 얼리 어답터가 아닐 때
    // dp[i][1] -> 노드 i가 얼리 어답터일 때
    dp.resize(n + 1, vector<int>(2, 0));
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 트리이므로 어떤 노드를 루트로 잡아도 상관없음 (보통 1번)
    solve(1);

    // 루트 노드의 두 가지 경우 중 최솟값이 최종 정답
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}