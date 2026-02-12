#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        const string &curs = phone_book[i];
        const string &nexts = phone_book[i+1];

        //같은 전화번호는 중복해서 들어있지 않으므로 패스
        if (curs.size() >= nexts.size())
            continue;

        bool bFound = true;
        for (int k = 0; k < curs.size(); k++)
        {
            if (curs[k] != nexts[k])
            {
                bFound = false;
                break;
            }
        }

        if (bFound) return false;
    }
    
    return true;
}