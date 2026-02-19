#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string word) {
    //a aa aaa aaaa aaaaa aaaae aaaai aaaao aaaau
    //aaae aaaea aaaee aaaei aaaeo aaaeu
    //aaai aaaia, aaaie
    string cs[6] = {"", "A", "E", "I", "O", "U"};
    set<string> st;
    
    for (int a = 0; a < 6; a++)
    {
        string s1 = cs[a];
        for (int b = 0; b < 6; b++)
        {
            string s2 = s1 + cs[b];
            for (int c = 0; c < 6; c++)
            {
                string s3 = s2 + cs[c];
                for (int d = 0; d < 6; d++)
                {
                    string s4 = s3 + cs[d];
                    for (int e = 0; e < 6; e++)
                    {
                        st.insert(s4 + cs[e]);
                    }
                }
            }
        }
    }
    
    
    int answer = 0;
    for (const auto &it : st)
    {
        if (it == word)
            return answer;
        answer++;
    }
    
    return answer;
}