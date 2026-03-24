#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
void backtracking(int i, int n, int l)
{
    if (i == n*2)
    {
        if (l == 0) answer++;
        return;
    }
    
    //'(' 추가
    backtracking(i+1, n, l+1);
    
    //')' 추가
    if (l > 0)
        backtracking(i+1, n, l-1);
}

int solution(int n) {
    backtracking(0, n, 0);

    return answer;
}