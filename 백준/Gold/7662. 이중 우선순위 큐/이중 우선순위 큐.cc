#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    multiset<int> ms;
    for (int i = 0; i < T; i++)
    {
        int k; cin >> k;
        ms.clear();

        for (int j = 0; j < k; j++)
        {
            char cmd; int num; cin >> cmd >> num;
            if (cmd == 'I')
            {
                ms.insert(num);
            }
            else if (cmd == 'D' && !ms.empty())
            {
                if (num == 1)
                {
                    auto it = prev(ms.end());
                    ms.erase(it);
                }
                else if (num == -1)
                {
                    ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
}