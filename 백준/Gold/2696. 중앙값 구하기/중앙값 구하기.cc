#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    vector<int> res;
    for (int i = 0; i < T; i++)
    {
        int m; cin >> m;
        res.clear();
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<>> minheap;

        for (int j = 1; j <= m; j++)
        {
            int num; cin >> num;
            int maxs = maxheap.size(), mins = minheap.size();
            const int total = maxs + mins;
            if (total == 0)
            {
                maxheap.push(num);
                maxs += 1;
            }
            else
            {
                if (maxs != 0 && num <= maxheap.top())
                {
                    maxheap.push(num);
                    maxs += 1;
                }
                else if (mins != 0 && num >= minheap.top())
                {
                    minheap.push(num);
                    mins += 1;
                }
                else if (maxs == 0)
                {
                    maxheap.push(num);
                    maxs += 1;
                }
                else
                {
                    minheap.push(num);
                    mins += 1;
                }
            }

            //printf("maxs = %d, mins = %d\n", maxs, mins);

            if (j % 2 != 0)
            {
                const int mid = total / 2 + 1;
                if (maxs >= mid)
                {
                    while (maxheap.size() > mid)
                    {
                        minheap.push(maxheap.top());
                        maxheap.pop();
                    }
                    
                }
                else
                {
                    while (maxheap.size() < mid)
                    {
                        maxheap.push(minheap.top());
                        minheap.pop();
                    }
                }

                res.push_back(maxheap.top());
                //printf("res[%d] = %d\n", res.size()-1, res.back());
            }
        }

        cout << res.size() << '\n';
        int cnt = 0;
        for (const int n : res)
        {
            cout << n << ' ';
            cnt++;
            if (cnt == 10)
            {
                cout << '\n';
                cnt = 0;
            }
        }
        cout << '\n';
    }
}