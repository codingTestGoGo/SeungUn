#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s; cin >> s;
    int sum = 0;

    int bstar = false;
    bool bBool = false;
    for (char c : s)
    {
        bBool = !bBool;
        int mul = bBool ? 1 : 3;
        if (c == '*') 
        {
            bstar = bBool;
            //printf("bstar = %s\n", bstar ? "true" : "false");
            continue;
        }
        sum += (c - '0') * mul;
        //printf("%d += %d\n", sum - (c - '0') * mul, (c - '0') * mul);
    }

    //printf("sum = %d\n", sum);
    int result = 10 - (sum % 10);
    if (!bstar)
    {
        while (result % 3 != 0)
        {
            result += 10;
        }

        result /= 3;
    }

    if (result == 10) result = 0;
    cout << result;
}