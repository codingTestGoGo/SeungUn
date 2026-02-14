#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Compare
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int CurTime = 0;
    int j = 0;
    int count = 0;
    
    sort (jobs.begin(), jobs.end(), [](const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    });
    
    //최소 비용 힙
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    while (count < jobs.size())
    {
        //현재 시간보다 신청 시간이 적은 요청을 큐에 넣는다.
        while (j < jobs.size() && jobs[j][0] <= CurTime)
            pq.push(jobs[j++]);
        
        //대기 큐가 없다면 다음 요청으로 시간을 건너뛴다.
        if (pq.empty())
        {
            CurTime = jobs[j][0];
        }
        else
        {
            //우선순위가 가장 높은 작업을 실행시킨다 가정하고, 종료 시간으로 점프한다.
            const vector<int> top = pq.top();
            pq.pop();
            CurTime = CurTime + top[1];
            answer += CurTime - top[0];
            count++;
        }
    }    
    
    return answer / jobs.size();
}