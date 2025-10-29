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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> result(n, -1);
    vector<int> q;
    for (int i = n-1; i >= 0; --i)
    {
    
        while (!q.empty())
        {
            int top = q.back();
            if (top > v[i])
            {
                result[i] = top;
                break;
            }
            else
                q.pop_back();
        }

        q.push_back(v[i]);
    }

    for (const int &i : result)
        cout << i << ' ';
}