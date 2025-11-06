#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> airport(n);
    int min = 1000000000;
    for (int i = 0; i < n; i++)
    {
        cin >> airport[i];
        if (airport[i] < min)
            min = airport[i];
    }

   //시간 t일때 i번째 포트가 처리할 수 있는 인원은 t / airport[i] 이다.

   long long start = 1, end = (long long)min * m;
   long long res = (long long)min * m;
   while (start <= end)
   {
        long long middle = (start + end) / 2;
        //printf("start %lld, end = %lld, middle %lld\n", start, end, middle);
        long long count = 0;
        for (const int &taketime : airport)
        {
            count += middle / taketime;
            if (count >= m) break;
        }

        if (count >= m)
        {
            end = middle-1;
            if (middle < res)
                res = middle;
        }
        else if (count < m)
            start = middle+1;
   }

   cout <<  res;
    
}