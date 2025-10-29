#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    //크기는 long long, 

    //다음 index로 넘어갈 때 높이가 낮아진다면 버려도 되는 값은 막대기의 높이
    //-> 어처피 더 낮은 막대기 기준으로 높이를 정해야 되기 때문
    // 스택에 index를 넣자

    // 1. index 0을 넣는다. 최대 넓이을 첫번째 직사각형으로
    // 2. index 1일때 확인
    /*
        스택에 가장 위에 있는 index j의 높이와 비교한다.
        2-1 i의 높이가 j보다 높거나 같을 때,
            스택에 j를 넣고 넘긴다.
        2-2 i의 높이가 j보다 낮을때
            스택에서 계속 꺼낸다.
                스택에서 꺼낸 index의 높이가 i보다 크면
                    꺼낸 카운트 x 높이 = 넓이
                스택에서 꺼낸 index의 높이가 i보다 작거나 같으면
                    멈춘다.
    */

    int n; cin >> n;
    vector<int> heights(n, 0);
    stack<int> st;
    long long MaxExtent = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
        //printf("heights[%d] = %d\n", i, heights[i]);

        if (!st.empty())
        {
            if (heights[st.top()] <= heights[i])
            {
                //printf("upper heights, push %d\n", i);
                st.push(i);
                continue;
            }
         
            //printf("heights[%d] lower histogram, start extent\n", i);
            int lastpopi = -1;
            while (!st.empty())
            {
                int topi = st.top();
                if (heights[topi] > heights[i])
                {
                    long long extent = (i-topi) * heights[topi];
                    //printf("extent(%d) = (%d) * %d = %lld, pop %d\n", topi, (i-topi), heights[topi], extent, topi);
                    if (MaxExtent < extent)
                        MaxExtent = extent;
                    
                    heights[topi] = heights[i];
                    lastpopi = topi;
                    st.pop();
                }
                else break;
            }

            if (heights[i] > 0)
            {
                //여기 히스토그램의 높이는 더이상 의미가 없다
                //앞으로 추가될 히스토그램에 반영될 높이는 i만큼의 높이
                heights[lastpopi] = heights[i];
                //printf("end extent, push %d\n", lastpopi);
                st.push(lastpopi);
            }
        }
        else
        {
            //printf("stack empty, push %d\n", i);
            st.push(i);
        }
    }

    while (!st.empty())
    {
        int topi = st.top();
        long long extent = (n-topi) * heights[topi];
        //printf("extent(%d) = (%d) * %d = %lld\n", topi, (n-topi), heights[topi], extent);
        if (MaxExtent < extent)
            MaxExtent = extent;

        st.pop();
    }

    cout << MaxExtent;
}