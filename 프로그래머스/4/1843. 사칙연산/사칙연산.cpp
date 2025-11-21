#include <vector>
#include <string>
#include <climits>

using namespace std;

int calculate(const int a, const int b, const string operation)
{
    if (operation == "+")
        return a + b;
    else
        return a - b;
}

int solution(vector<string> arr)
{
    int answer = -1;
    
    //숫자부터 세준다.
    const int arrSize = arr.size();
    int numberCount = (arrSize + 1) / 2;
    
    //0이 최소, 1이 최대
    vector<vector<vector<int>>> dp(arrSize, vector<vector<int>>(arrSize, vector<int>(2)));
    for (vector<vector<int>> &vv : dp)
    {
        for (vector<int> &v : vv)
        {
            v[0] = INT_MAX; v[1] = -INT_MAX;
        }
    }
    
    //범위가 1인 경우는 각 숫자값으로 한다.
    for (int arri = 0; arri < arrSize; arri += 2)
    {
        dp[arri][arri][0] = dp[arri][arri][1] = stoi(arr[arri]);
    }
    
    //dp로 길이가 2인 범위부터 차근차근 세준다.
    for (int size = 2; size <= numberCount; size++)
    {
        for (int start = 0; start < arr.size() - 2*(size-1); start += 2)
        {
            //start = 0; start < 1; start += 2
            int end = start + 2*(size-1);
            for (int Rangei = start; Rangei <= end - 2; Rangei += 2)
            {
                int res_max, res_min; 
                if (arr[Rangei+1] == "+")
                {
                    res_min = dp[start][Rangei][0] + dp[Rangei + 2][end][0];
                    res_max = dp[start][Rangei][1] + dp[Rangei + 2][end][1];
                }
                else
                {
                    res_min = dp[start][Rangei][0] - dp[Rangei + 2][end][1];
                    res_max = dp[start][Rangei][1] - dp[Rangei + 2][end][0];
                }
             
                dp[start][end][0] = min(dp[start][end][0], res_min);
                dp[start][end][1] = max(dp[start][end][1], res_max);
            }
        }
    }
    
    answer = dp[0][arrSize-1][1];
    return answer;
}