#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> v(n);
    int result = 0;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        int target = v[i];
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

            int sum = v[start] + v[end];
            if (sum == target)
            {
                result++;
                break;
            }

            if (sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << result;
}