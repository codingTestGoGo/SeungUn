#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int total = 0;
    int biggestVideo = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
        if (biggestVideo < v[i]);
            biggestVideo = v[i];
    }

    int start = biggestVideo, end = total;
    int min = INT32_MAX;
    while (start <= end)
    {
        int blueRayCost = (start + end) / 2;
        int temp = 0;
        int blueRayCount = m;
        int i;
        for (i = 0; i < n; i++)
        {
            if (blueRayCount == 0) break;

            temp += v[i];
            if (temp > blueRayCost)
            {
                temp = 0;
                i--;
                blueRayCount--;
            }
        }

        //i가 부족한 건 블루레이 용량이 부족
        if (i < n)
        {
            start = blueRayCost+1;
            continue;
        }

        //다 담았을 떈 최솟값을 저장하고 용량을 줄인다.
        min = blueRayCost;
        end = blueRayCost-1;
    }

    cout << min;
}