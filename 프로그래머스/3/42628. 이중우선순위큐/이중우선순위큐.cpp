#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;
    for (const string &s : operations)
    {
        stringstream ss(s);
        string op;
        int num;
        ss >> op >> num;
        
        if (op == "I")
            ms.insert(num);
        
        else if (op == "D" && !ms.empty())
        {
            if (num == 1)
            {
                auto it = prev(ms.end());
                ms.erase(it);
            }
            else
                ms.erase(ms.begin());
        }
    }
    
    if (ms.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*ms.rbegin());
        answer.push_back(*ms.begin());
    }
    return answer;
}