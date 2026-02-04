#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<>> pq(scoville.begin(), scoville.end());
    
    int cnt = 0;
    while (true)
    {
        const int lowest = pq.top();
        pq.pop();
        
        //가장 낮은 스코빌 지수가 K이상이라면, 종료
        if (lowest >= K)
        {
            return cnt;
        }
        
        //하나 꺼냈는데 비어있다면, -1 반환
        if (pq.empty())
        {
            return -1;
        }
        
        const int second = pq.top();
        pq.pop();
        
        pq.push(lowest + second*2);
        cnt++;
    }
}