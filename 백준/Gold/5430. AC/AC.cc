#include <bits/stdc++.h>

using namespace std;

bool Applyfunc(deque<int> &number, const char &c, bool &bUpper)
{
    if (c == 'R')
        bUpper = !bUpper;
    if (c == 'D')
    {
        if (number.size() == 0)
        {
            cout << "error\n";
            return false;
        }

        if (bUpper)
            number.pop_front();
        else
            number.pop_back();
    }

    return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        string command; cin >> command;
        int n; cin >> n;
        deque<int> number;

        //'\n' 삭제
        cin.ignore();
        string numbs; cin >> numbs;

        numbs.erase(remove(numbs.begin(), numbs.end(), '['), numbs.end());
        numbs.erase(remove(numbs.begin(), numbs.end(), ']'), numbs.end());

        stringstream ss(numbs);

        string num;
        while (getline(ss, num, ','))
        {
            number.push_back(stoi(num));
        }

        // for (const int &numb : number)
        //     cout << numb;

        bool bUpper = true;
        bool bFailed = false;
        for (const char &c : command)
        {
            if (!Applyfunc(number, c, bUpper))
            {
                bFailed = true;
                break;
            }
        }

        if (bFailed)
            continue;
        
        cout << '[';
        while (number.size() > 1)
        {
            if (bUpper)
            {
                cout << number.front() << ',';
                number.pop_front();
            }
            else
            {
                cout << number.back() << ',';
                number.pop_back();
            }
        }

        if (number.size() == 1)
            cout << number.front();
        cout << "]\n";
    }
}