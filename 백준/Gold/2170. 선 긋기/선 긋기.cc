#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if (a.first != b.first)
            return a.first < b.first;
        
        return a.second < b.second;
    });

    int rb = v[0].second;
    long long res = rb - v[0].first;
    for (int i = 0; i < n; i++)
    {
        res += v[i].second - v[i].first;
        res -= max(min(rb, v[i].second) - v[i].first, 0);
        rb = max(rb, v[i].second);
    }

    cout << res;
}