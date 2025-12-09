#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> alphabets;
int L, C;

void backtracking(int index, vector<char> &list, int cnt1, int cnt2)
{
    if (list.size() == L)
    {
        if  (cnt1 >= 1 && cnt2 >= 2)
        {
            for (const char &c : list)
                cout << c;
            cout << '\n';
        }
        return;
    }

    for (; index < C; index++)
    {
        list.push_back(alphabets[index]);
        if (alphabets[index] == 'a'
            || alphabets[index] == 'e'
            || alphabets[index] == 'i'
            || alphabets[index] == 'o'
            || alphabets[index] == 'u')
        {
            cnt1 += 1;
            backtracking(index+1, list, cnt1, cnt2);
            cnt1 -= 1;
        }
        else
        {
            cnt2 += 1;
            backtracking(index+1, list, cnt1, cnt2);
            cnt2 -= 1;
        }
        list.pop_back();
    }

}

int main()
{
    cin >> L >> C;
    alphabets.resize(C);
    for (int i = 0; i < C; i++)
        cin >> alphabets[i];
    
    sort(alphabets.begin(), alphabets.end());

    vector<char> list;
    backtracking(0, list, 0, 0);
}