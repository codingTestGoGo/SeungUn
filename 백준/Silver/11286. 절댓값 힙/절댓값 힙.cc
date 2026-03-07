#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Compare
{
    bool operator()(const int &a, const int &b)
    {
        const int absa = abs(a);
        const int absb = abs(b);
        if (absa != absb)
            return abs(a) > abs(b);
        
        return a > b;
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, Compare> pq;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        if (num == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';;
                pq.pop();
            }
            else
                cout << 0 << '\n';
        }
        else
            pq.push(num);
    }
}