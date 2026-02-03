#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int total = 0;
    unordered_map<int, int> phoneketmon;
    for (const int & number : nums)
    {
        phoneketmon[number] += 1;
        total++;
    }
    
    const int cnt = phoneketmon.size();
    const int CanGet = total / 2;
    if (cnt > CanGet)
        return CanGet;
    else if (cnt == CanGet)
        return cnt;
    else
        return cnt;
    
}