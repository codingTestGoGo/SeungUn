#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        const int target = v[i];
        int start = 0, end = n-1;
        while (start < end)
        {
            if (start == i)
            {
                start++;
                continue;
            }

            if (end == i)
            {
                end--;
                continue;
            }

            const long long sum = v[start] + v[end];
            if (sum == target)
            {
                res++;
                break;
            }
            else if (sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << res;
}