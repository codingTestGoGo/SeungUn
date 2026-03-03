#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    int max_node = 0;
    for (int n : nodes) {
        max_node = max(max_node, n);
    }

    // 인접 리스트, 차수 배열, 방문 배열을 최대 노드 번호에 맞게 할당
    vector<vector<int>> adj(max_node + 1);
    vector<int> degree(max_node + 1, 0);
    vector<bool> visited(max_node + 1, false);

    // 간선 정보를 이용해 트리 구성 및 차수 계산
    for (const auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        degree[e[0]]++;
        degree[e[1]]++;
    }

    int odd_even_trees = 0;
    int rev_odd_even_trees = 0;

    // 포레스트 내의 각 트리(컴포넌트)를 탐색
    for (int start_node : nodes) {
        if (visited[start_node]) continue;

        queue<int> q;
        q.push(start_node);
        visited[start_node] = true;

        int group0_cnt = 0;
        int group1_cnt = 0;
        int total_nodes = 0;

        // BFS로 현재 트리의 노드들을 순회
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            total_nodes++;

            // 노드의 값과 차수의 홀짝성 비교
            if ((curr % 2) == (degree[curr] % 2)) {
                group0_cnt++;
            } else {
                group1_cnt++;
            }

            for (int nxt : adj[curr]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        // 홀짝 트리 조건 검사
        if (group0_cnt == 1 && group1_cnt == total_nodes - 1) {
            odd_even_trees++;
        }
        
        // 역홀짝 트리 조건 검사
        if (group1_cnt == 1 && group0_cnt == total_nodes - 1) {
            rev_odd_even_trees++;
        }
    }

    return {odd_even_trees, rev_odd_even_trees};
}