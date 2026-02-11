#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
   queue<pair<int, int>> trucks; 
    int total = 0;
    int time = 0;
    
    for (int num : truck_weights) {
        // 트럭이 들어가기 위해 적어도 1초는 무조건 흐름 (혹은 이전 트럭 직후)
        time++; 
        
        // 1. 현재 시간(time)에 다리를 다 건넌 트럭 처리 (항상 먼저 체크)
        if (!trucks.empty() && trucks.front().first == time) {
            total -= trucks.front().second;
            trucks.pop();
        }
        
        // 2. 무게 초과 시, 공간이 날 때까지 시간 점프
        while (total + num > weight) {
            time = trucks.front().first; // 맨 앞 트럭이 나가는 시간으로 이동
            total -= trucks.front().second;
            trucks.pop();
        }
        
        // 3. 트럭 진입
        trucks.push({time + bridge_length, num});
        total += num;
    }
    
    return time + bridge_length;
}