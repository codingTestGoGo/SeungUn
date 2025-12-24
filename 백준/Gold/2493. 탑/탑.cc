#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    //{탑의 높이, 번호}
    stack<pair<int, int>> st;

    for (int i = 1; i <= n; i++)
    {
        int height; cin >> height;

        //height보다 낮은 탑들은 제거
        while (!st.empty() && st.top().first < height)
            st.pop();

        if (st.empty())
        {
            cout << 0 << ' ';
        }
        else
        {
            cout << st.top().second << ' ';
        }

        st.push({height, i});
    }
}