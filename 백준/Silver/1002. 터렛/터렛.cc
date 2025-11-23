#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            cout << -1 << '\n';
            continue;
        }

        double length = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if (length == r1 + r2)
        {
            cout << 1 << '\n';
            continue;
        }
        else if (length > r1 + r2)
        {
            cout << 0 << '\n';
            continue;
        }
        else
        {
            int big, small;
            if (r1 > r2)
            {
                big = r1;
                small = r2;
            }
            else
            {
                big = r2;
                small = r1;
            }

            if (length + small == big)
            {
                cout << 1 << '\n';
                continue;
            }
            else if (length + small > big)
            {
                cout << 2 << '\n';
                continue;
            }
            else
            {
                cout << 0 << '\n';
                continue;
            }
        }
    }
}