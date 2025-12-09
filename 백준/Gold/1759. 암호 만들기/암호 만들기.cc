#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> alphabets;
int L, C;

void backtracking(int index, vector<char> &list, int cnt1, int cnt2)
{
    list.push_back(alphabets[index]);
    if (alphabets[index] == 'a'
        || alphabets[index] == 'e'
        || alphabets[index] == 'i'
        || alphabets[index] == 'o'
        || alphabets[index] == 'u')
    {
        cnt1 += 1;
    }
    else cnt2 += 1;

    // printf("index %d, cnt1 = %d, cnt2 = %d, string = ", index, cnt1, cnt2);
    // for (const char &c : list)
    //     cout << c;
    // cout << '\n';
    if (list.size() == L)
    {
        if  (cnt1 >= 1 && cnt2 >= 2)
        {
            for (const char &c : list)
                cout << c;
            cout << '\n';
        }
        list.pop_back();
        return;
    }

    for (; index < C-1; index++)
    {

        backtracking(index+1, list, cnt1, cnt2);
    }

    list.pop_back();
}

int main()
{
    cin >> L >> C;
    alphabets.resize(C);
    for (int i = 0; i < C; i++)
        cin >> alphabets[i];
    
    sort(alphabets.begin(), alphabets.end());

    vector<char> list;
    int cnt1 = 0, cnt2 = 0;

    for (int index = 0; index < C; index++)
    {
        backtracking(index, list, cnt1, cnt2);
    }
}