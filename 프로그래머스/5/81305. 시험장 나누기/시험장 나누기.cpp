#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int n = num.size();
 
    // 루트 찾기: 부모가 없는 노드
    vector<bool> has_parent(n, false);
    for (int i = 0; i < n; i++)
        for (int c : links[i])
            if (c != -1)
                has_parent[c] = true;
 
    int root = 0;
    for (int i = 0; i < n; i++)
        if (!has_parent[i]) { root = i; break; }
 
    // 반복적 후위 순회 순서 계산 (스택 오버플로 방지)
    vector<int> order;
    order.reserve(n);
    stack<int> stk;
    stk.push(root);
    while (!stk.empty()) {
        int node = stk.top(); stk.pop();
        order.push_back(node);
        for (int c : links[node])
            if (c != -1)
                stk.push(c);
    }
    reverse(order.begin(), order.end()); // 후위 순회 순서
 
    // mid 제한 아래에서 k-1번 이하 컷이 가능한지 검사
    auto check = [&](long long mid) -> bool {
        vector<long long> subtree(num.begin(), num.end());
        int cuts = 0;
        for (int node : order) {
            // 자식들의 subtree 값을 오름차순으로 처리
            // → 작은 자식을 먼저 합쳐야 subtree[node]가 최소화되어 부모에게 유리
            vector<long long> children;
            for (int c : links[node])
                if (c != -1) children.push_back(subtree[c]);
            sort(children.begin(), children.end());
 
            for (long long cv : children) {
                if (subtree[node] + cv > mid)
                    cuts++;               // 간선을 끊는다
                else
                    subtree[node] += cv;  // 자식을 합친다
            }
        }
        return cuts <= k - 1;
    };
 
    long long lo = *max_element(num.begin(), num.end());
    long long hi = accumulate(num.begin(), num.end(), 0LL);
 
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else            lo = mid + 1;
    }
    return (int)lo;
}