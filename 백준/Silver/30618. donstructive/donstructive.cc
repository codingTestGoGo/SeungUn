#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    int leftSize = n/2, rightSize = n - leftSize;
    vector<int> left, right;
    left.reserve(leftSize), right.reserve(rightSize);

    bool bright = true;
    for (int i = 1; i <= n; i++)
    {
        if (bright)
            right.push_back(i);
        else
            left.push_back(i);

        bright = !bright;
    }

    for (int i = 0; i < leftSize; i++)
        cout << left[i] << ' ';

    for (int i = rightSize-1; i >= 0; --i)
    {
        cout << right[i] << ' ';
    }
}