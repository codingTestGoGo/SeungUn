#include <iostream>
#include <vector>

using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    // 신발끈 공식: S = x1y2 + x2y3 + x3y1 - (x1y3 + x2y1 + x3y2)
    long long s = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2);

    if (s > 0) {
        return 1;
    } else if (s < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    cout << ccw(x1, y1, x2, y2, x3, y3);
}