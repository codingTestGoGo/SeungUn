#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(int dist_limit, int split_limit) {
    long long answer = 1;
    //어느 깊이 k의 노드 수를 추적해 트리가 완성되는 시점에 리프 노드 수의 최댓값을 답으로 구한다.
    //어느 깊이 k의 노드 수 P가 되는 시점에 사용한 분배 노드 수를 기록하여
    //더 적은 분배노드로 P를 만든 트리 경로가 있다면 생략한다.
    
    //{사용한 분배 노드 갯수, 어느 깊이 k의 노드 수}
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>> pq;
    
    //{어느 깊이 k의 노드 수, 사용한 분배 노드 갯수}
    unordered_map<long, int> mp;

    //깊이 1은 {0, 1}
    pq.push({0, 1});
    while (!pq.empty())
    {
        const auto cur = pq.top();
        pq.pop();
        
        const int& S = cur.first;
        const long long& P = cur.second;
        
        if (mp.find(P) != mp.end() && mp[P] <= S) continue;
        
        mp[P] = S;
        
        const static int nextc[2] = {2, 3};
        for (const int &c : nextc)
        {
            if (P * c > split_limit) continue;
            
            const int leftS = dist_limit - S;
            //현재 층의 노드 중, 분배 노드로 바꿀 수 있는 노드의 수
            // = min(남은 분배 노드 수, 현재 층의 노드 수)
            const long long take = min((long long)leftS, P);
            answer = max(answer, P + take * (c-1));
            
            //모든 노드를 분배 노드로 만들 수 있는 경우에만 탐색
            if (leftS >= P)
            {
                pq.push({S+take, P*c});
            }
        }
    }
    
    return answer;
}