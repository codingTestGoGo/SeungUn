#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    
    int r1, r2, r3; long long res = LONG_MAX;
    for (int i = 0; i < n-2; i++)
    {
        long long cur = v[i];
        int start = i+1, end = n-1;
        while (start < end)
        {
            long long total = cur + v[start] + v[end];
            if (abs(total) < res)
            {
                r1 = i;
                r2 = start;
                r3 = end;
                res = abs(total);
            }

            if (total < 0)
                start++;
            else
                end--;
        }
    }

    cout << v[r1] << ' ' << v[r2] << ' ' << v[r3];
}