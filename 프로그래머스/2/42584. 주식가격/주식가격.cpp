#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    vector<pair<int, int>> st;
    int i = 0;
    for (const int &price : prices)
    {
        if (st.empty() || st.back().first <= price)
            st.push_back({price, i});
        else
        {
            while (!st.empty() && st.back().first > price)
            {
                answer[st.back().second] = i - st.back().second;
                st.pop_back();
            }
            
            st.push_back({price, i});
        }
        
        i++;
    }
    
    while (!st.empty())
    {
        answer[st.back().second] = i - st.back().second - 1;
        st.pop_back();
    }
    return answer;
}