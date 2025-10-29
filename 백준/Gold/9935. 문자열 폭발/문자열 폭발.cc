#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s, bomb; cin >> s >> bomb;
    int bs = bomb.size();
    vector<char> st;
    for (const char &c : s)
    {
        st.push_back(c);
        if (st.size() >= bomb.size())
        {
            bool bIsBomb = true;
            for (int i = st.size()-bs; i < st.size(); i++)
            {
                if (st[i] != bomb[i - st.size()+bs])
                {
                    bIsBomb = false;
                    break;
                }
            }

            if (bIsBomb)
            {
                for (int i = 0; i < bs; i++)
                {
                    st.pop_back();
                }
            }
        }
    }

    if (st.size() == 0)
        cout << "FRULA";

    for (const char &c : st)
        cout << c;
}