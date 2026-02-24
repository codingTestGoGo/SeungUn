#include <string>
#include <vector>

using namespace std;

int count = 0;
int tg;

void dfs(int number, vector<int> &numbers, int index)
{
    if (index == numbers.size())
    {
        if (number == tg) count++;
        return;
    }
    
    dfs(number + numbers[index], numbers, index+1);
    dfs(number - numbers[index], numbers, index+1);
}

int solution(vector<int> numbers, int target) {
    tg = target;
    dfs(0, numbers, 0);
    return count;
}