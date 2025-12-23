#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // cin.tie(NULL);
    // ios::sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        pq.push(temp);
    }

    if (pq.size() == 1)
    {
        cout << 0;
        return 0;
    }

    int result = 0;
    while (!pq.empty())
    {
        int first = pq.top();
        pq.pop();

        //하나 남았다면 비교할 게 없음
        if (pq.empty()) break;

        int second = pq.top();
        result += first + second;
        pq.pop();

        //큐에서 가장 작은 두 값을 합쳐 다시 넣는다.
        pq.push(first + second);
    }

    cout << result;


}