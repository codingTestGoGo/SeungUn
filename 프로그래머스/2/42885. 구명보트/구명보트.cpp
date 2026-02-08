#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    
    sort(people.begin(), people.end());
    int start = 0, end = people.size() - 1;
    int answer = 0;
    while (start <= end)
    {
        if (start == end)
        {
            answer++;
            break;
        }
        
        if (people[start] + people[end] > limit)
        {
            answer++;
            end--;
        }
        else
        {
            answer++;
            start++;
            end--;
        }
    }
    
    
    return answer;
}