#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열을 숫자로 변환
unsigned long long order(const string &ban)
{
    unsigned long long result = 0, pw = 1;
    const int size = ban.size();
    
    for (int i = size - 1; i >= 0; --i)
    {
        result += (ban[i] - 'a' + 1) * pw;
        pw *= 26;
    }
    
    return result;
}

// 숫자를 문자열로 변환 (Bijective Base-26)
string target(long long n)
{
    string result;
    while (n > 0)
    {
        n--; // 0-based index로 조정하여 'a'~'z' 매핑
        result.push_back((n % 26) + 'a');
        n /= 26;
    }
    
    // 일의 자리가 먼저 들어갔으므로 문자열을 뒤집음
    reverse(result.begin(), result.end());
    return result;
}

string solution(long long n, vector<string> bans) {
    // 자료형을 unsigned long long으로 변경하여 오버플로우 방지
    vector<unsigned long long> orders;
    orders.reserve(bans.size()); // 메모리 재할당 방지 최적화

    for (const string &ban : bans)
    {
        orders.push_back(order(ban));
    }
    
    // 숫자를 기준으로 오름차순 정렬
    sort(orders.begin(), orders.end());
    
    // ban 리스트를 순회하며 n 값 보정
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i] <= n)
        {
            n++;
        }
    }
    
    return target(n);
}