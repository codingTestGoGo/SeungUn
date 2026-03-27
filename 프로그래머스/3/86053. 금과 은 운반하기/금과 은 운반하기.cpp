#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 0;
    int n = g.size();
    long long start = 1, end = 1e15;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long gold, silver, totalmine;
        gold = silver = totalmine = 0;
        for (int i = 0; i < n; i++)
        {
            long long cnt = (mid + t[i]) / (2*t[i]);
            long long total = cnt * w[i];
            
            //printf("cnt = %lld, total = %lld\n", cnt, total);
            
            gold += min((long long)g[i], total);
            silver += min((long long)s[i], total);
            totalmine += min((long long)g[i] + s[i], total);
        }
        
        //printf("mid = %lld, %lld, %lld, %lld\n", mid, gold, silver, totalmine);
        if (gold >= a && silver >=b && totalmine >= a+b)
        {
            answer = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    
    return answer;
}