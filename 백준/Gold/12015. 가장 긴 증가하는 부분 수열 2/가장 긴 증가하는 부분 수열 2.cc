#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    int cur, size = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        //printf("nums[%d] = %d, cur = %d\n", size-1, nums[size-1], cur);
        if (size == 0)
        {
            nums[size] = cur;
            size += 1;
            //printf("empty, nums[%d] = %d\n", size-1, cur);
        }
        else if (nums[size-1] < cur)
        {
            nums[size] = cur;
            size += 1;
           // printf("nums[%d] = %d\n", size-1, cur);
        }
        else if (nums[size-1] > cur)
        {
            int start = 0, end = size-1;
            while (start < end)
            {
                int midi = (start + end) / 2;
                int mid = nums[midi];

                //이미 같은 숫자가 있으면 탐색 종료
                if (cur == mid)
                {
                   // printf("cur %d == mid %d\n", cur, mid);
                    start = midi;
                    break;
                }
                if (cur < mid)
                {
                    end = midi;
                }
                else
                {
                    start = midi+1;
                }
            }

            //이분탐색이 자동 종료되는 시점 -> cur과 가장 가까운 숫자 찾음 -> 대체
            //cur이 현재 있는 숫자보다 작다면 교체 => 더 좋은 순열
            if (cur < nums[start])
            {
                nums[start] = cur;
               // printf("replace nums[%d] = %d\n", start, cur);
            }
           // else printf("cur %d >=nums[%d] %d\n",cur,  start, nums[start]);
        }
    }

    cout << size;
}