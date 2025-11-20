#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    //이분탐색 문제이니 어떤걸 이분탐색 할 것인지 정해야 함
    //사람이나 시간은 애매하다... 10억이라 이분탐색하기엔 너무 오래걸림
    
    //그래도 시간은로 해야할 것 같은데
    //최댓값은 가장 짧은 곳에서 모든 사람이 기다리는 걸로
    long long start = 0, end = (long long)times[0] * n;
    long long answer = end;
    while (start <= end)
    {
        long long time = (start + end) / 2;
        long long total = 0;
        for (int i = 0; i < times.size(); i++)
        {
            //심사대마다 가능한 사람 수
            total += time / times[i];
        }
        
        //time에 사람 수를 만족 못한다면
        if (total < n)
        {
            //time을 늘린다.
            start = time+1;
        }
        
        //time내에 사람 수를 만족하거나 더 크다면
        else
        {
            //time을 줄여본다.
            end = time-1;
            answer = time;
        }
    }
    
    return answer;
}