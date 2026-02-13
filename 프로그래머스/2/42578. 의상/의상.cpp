#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> mp;
    for (const vector<string> &s : clothes)
    {
        mp[s[1]] += 1;
    }
    
    for (const auto &[key, value] : mp)
    {
        answer *= value + 1;
    }
    
    answer -= 1;
    return answer;
}