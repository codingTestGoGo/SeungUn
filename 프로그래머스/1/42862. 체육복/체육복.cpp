#include <string>
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
void backtracking(const int &n, vector<int> &clothes, int i, int res)
{
    //n번쨰 왔다면 최댓값 갱신
    if (i == n)
    {
        //cout << i << ", num = " << clothes[i] << ", res = " << res << '\n';
        answer = max(res, answer);
        return;
    }
    
    //옷이 없다면 넘어감
    if (clothes[i] == 0)
    {
        backtracking(n, clothes, i+1, res);
        return;
    }
    
    //옷이 하나밖에 없는 경우엔 다음으로 넘어간다
    if (clothes[i] == 1)
    {
        backtracking(n, clothes, i+1, res+1);
        return;
    }
        
    if (clothes[i] > 1)
    {
        //자기 자신 추가
        res += 1;
        if (i > 0 && clothes[i-1] == 0)
        {
            clothes[i]--;
            clothes[i-1]++;
            backtracking(n, clothes, i+1, res+1);
            clothes[i]++;
            clothes[i-1]--;
        }
        
        if (i < n-1 && clothes[i+1] == 0)
        {
            clothes[i]--;
            clothes[i+1]++;
            backtracking(n, clothes, i+1, res);
            clothes[i]++;
            clothes[i+1]--;
        }
        //옷이 두 개 이상이지만 양쪽다 옷이 있을 땐 넘어간다.
        backtracking(n, clothes, i+1, res);
    }
}


int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n, 1);
    
    for (const int &lst : lost)
        clothes[lst-1] -= 1;
    for (const int &res : reserve)
        clothes[res-1] += 1;

    backtracking(n, clothes, 0, 0);
    return answer;
}