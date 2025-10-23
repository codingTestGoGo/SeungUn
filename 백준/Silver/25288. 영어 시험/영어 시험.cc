#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    string chars; cin >> chars;
    sort(chars.begin(), chars.end());

    bool bReverse = false;
    for (int i = 0; i < n; i++)
    {
        if (bReverse)
        {
            for (int j = chars.length()-1; j >= 0; --j)
                cout << chars[j];
        }
        else
        {
            for (int j = 0; j < chars.length(); ++j)
                cout << chars[j];
        }

        bReverse = !bReverse;
    }
}