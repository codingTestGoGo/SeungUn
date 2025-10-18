#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    int diff = n / 2;
    vector<bool> visited(n+1, false);

    for (int i = n-diff; i >= 1; --i)
    {
        if (visited[i]) continue;

        int j = i;
        while (j <= n)
        {
            if (visited[j])
            {
                j++;
                continue;
            }
            else
            {
                visited[j] = true;
                cout << j << ' ';
                j += diff;
            }
        }
    }
}

//3 6 2 5 1 4