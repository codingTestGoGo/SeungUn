#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
   int answer = 0;
    
    //종료지점 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), [](const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    });
    
    //현재 결정할 교차점
    int start = routes[0][0], end = routes[0][1];
    answer = 1;
    for (const auto &route : routes)
    {
        
        if (route[0] <= start)
        {
            continue;
        }
        
        //현재 루트가 교차점에 포함되어 있다면 갱신
        else if (start < route[0] && route[0] <= end)
        {
            start = max(start, route[0]);
        }
        
        //교차점에 포함되어 있지 않다면 갱신
        else
        {
            start = route[0];
            end = route[1];
            answer++;
        }
    }
    
    return answer;
}