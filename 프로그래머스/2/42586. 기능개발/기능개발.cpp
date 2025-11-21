#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> answer;
    
    //각 작업들이 몇일 지나야 완료될 수 있는지 계산한다.
    int procCount = progresses.size();
    int days = 0;
    for (int i = 0; i < procCount; i++)
    {
        int leftproc = 100 - progresses[i];
        int needdays = leftproc / speeds[i] + (leftproc % speeds[i] == 0 ? 0 : 1);
        
        //필요한 날이 현재 날짜보다 크다면
        if (needdays > days)
        {
            //이 proc은 출하 기점
            answer.push_back(1);
            days = needdays;
        }
        
        //필요한 날이 현재 날짜보다 작거나 같다면
        else
        {
            //이전 출하 때 같이 출하
            answer[answer.size()-1] += 1;
        }
    }
    
    return answer;
}