#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for (int tk = 0; tk < T; tk++)
    {
        int x, y; cin >> x >> y;

        long long length = y-x;
        long long n = (long long)sqrt(length);

        //13 1+2+3+3+2+1+1
        //15 1+2+3+2+1 + 6(1+2+3)
        //16 1+2+3+4+3+2+1 + 0
        if (n*n == length)
            cout << 2*n-1 << '\n';
        else if (n*n < length && length <= n*n + n)
            cout << 2*n << '\n';
        else
            cout << 2*n+1 <<'\n';
    }
}