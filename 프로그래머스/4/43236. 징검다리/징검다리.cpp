#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    
    int size = rocks.size();
    // 출발지점(0)과 도착지점(distance)을 포함하여 정렬
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    // 이분 탐색 범위 설정
    int low = 1; // 최소 거리는 1 이상
    int r = distance;
    int answer = 0;

    while (low <= r) {
        int mid = (low + r) / 2; // 이번에 테스트할 "최소 거리"
        
        int removed_cnt = 0;
        int prev_rock = 0; // 출발 지점 위치

        for (int i = 0; i < rocks.size(); i++) {
            // 현재 돌과 이전 돌 사이의 거리가 mid보다 작으면
            if (rocks[i] - prev_rock < mid) {
                removed_cnt++; // 돌을 제거 (거리가 너무 짧음)
            } else {
                prev_rock = rocks[i]; // 거리가 충분하면 현재 돌을 기준점으로 갱신
            }
        }

        if (removed_cnt > n) {
            // 너무 많이 제거함 -> 기준 거리(mid)가 너무 큼 -> 줄여야 함
            r = mid - 1;
        } else {
            // n개 이하로 제거해서 가능했음 -> 거리를 더 늘려봐도 됨 (최댓값을 찾으므로)
            answer = mid; // 현재 mid는 가능한 답이므로 저장
            low = mid + 1;
        }
    }

    return answer;
}