#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int n, m;
vector<int> v;

void backtracking(int index, int count, vector<int> &result)
{
    //printf("v[%d] = %d\n", index, v[index]);
    if (index > v.size()) return;

    result.push_back(v[index]);
    count += 1;

    //printf("index = %d, count = %d\n", index, count);
    if (count == m)
    {
        for (const int &number : result)
            cout << number << ' ';
        cout << '\n';

        result.pop_back();
        return;
    }

    for (int nexti = index; nexti < v.size(); nexti++)
    {
        backtracking(nexti, count, result);
    }

    result.pop_back();
    count -= 1;
}


int main()
{
    cin >> n >> m;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        st.insert(num);
    }

    for (auto it : st)
    {
        //printf("num = %d\n", it);
        v.push_back(it);
    }

    //sort(v.begin(), v.end());
    vector<int> result;
    //printf("v.size() = %ld\n", v.size());
    for (int i = 0; i < v.size(); i++)
        backtracking(i, 0, result);
}