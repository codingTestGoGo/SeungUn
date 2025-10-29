#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> v(n);
    vector<int> cnt(1000000, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cnt[v[i]] += 1;
    }

    vector<int> result(n, -1);
    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty())
        {
            //q에 있는 index들을 비교
            int top = q.back();
            if (cnt[v[top]] < cnt[v[i]])
            {
                result[top] = v[i];
                q.pop_back();
            }
            else
                break;
        }

        q.push_back(i);
    }

    for (const int &i : result)
        cout << i << ' ';
}