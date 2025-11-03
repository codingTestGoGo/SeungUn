#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> requests(n);
    long long sum = 0; // 총합은 int 범위를 넘을 수 있으니 long long 추천
    int biggest = 0;

    for (int i = 0; i < n; i++)
    { 
        cin >> requests[i];
        sum += requests[i];
        if (biggest < requests[i])
            biggest = requests[i];
    }
    // 또는 C++ algorithm 헤더 사용
    // biggest = *max_element(requests.begin(), requests.end());
    // sum = accumulate(requests.begin(), requests.end(), 0LL); 

    int money; cin >> money;

    // [개선점 1] 모든 요청을 수용 가능한 경우, 미리 처리
    if (sum <= money)
    {
        cout << biggest;
        return 0;
    }

    int start = 0;
    int end = biggest;
    int result = 0;
    while (start <= end)
    {
        int middle = (start + end)/2;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (requests[i] >= middle)
                total += middle;
            else
                total += requests[i];
        }

        //예산과 딱 맞다면 끝낸다
        if (total == money)
        {
            result = middle;
            break;
        }

        //예산 안에 된다면 좀더 사용가능하게 해본다.
        else if (total < money)
        {
            if (middle >= biggest)
            {
                result = biggest;
                break;
            }

            start = middle + 1;
            if (result < middle)
                result = middle;
        }
        //예산 안에 안된다면 상한액을 줄인다.
        else
        {   
            end = middle - 1;
        }
    }

    cout << result;
}