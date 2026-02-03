#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    for (const char &c : s)
    {
        if (c == '(')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            
            st.pop();
        }
    }

    //비워져 있으면 true, 아니면 false
    return st.empty();
}