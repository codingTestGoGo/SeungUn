#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;

    int start = 1, end = n;

    bool bBool = true;
    for (int i = 0; i < n; i++)
    {
        if (bBool)
        {
            cout << start << ' ';
            start++;
        }
        else
        {
            cout << end << ' ';
            end--;
        }

        bBool = !bBool;
    }
}