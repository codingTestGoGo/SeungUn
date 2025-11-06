#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int n; cin >> n;
   vector<long long> v(n);
   for (int i = 0; i < n; i++)
    cin >> v[i];

    sort(v.begin(), v.end());

    long long min = 10000000000;
    int resi, resa, resb;
    for (int i = 0; i < n-2; i++)
    {
        long long total = v[i];
        int start = i+1; int end = n-1;
        while (start < end)
        {
            long long tempTotal = v[start] + v[end] + total;
            if (tempTotal == 0)
            {
                cout << v[i] << ' ' << v[start] << ' ' << v[end];
                return 0;
            }

            if (abs(tempTotal) < abs(min))
            {
                min = tempTotal;
                resi = i; resa = start; resb = end;
                //printf("min %lld, {%lld, %lld, %lld}\n", min, v[resi], v[resa], v[resb]);
            }

            if (tempTotal > 0)
                end--;
            if (tempTotal < 0)
                start++;
        }
    }

    cout << v[resi] << ' ' << v[resa] << ' ' << v[resb];
}