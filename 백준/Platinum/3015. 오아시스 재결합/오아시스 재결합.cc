#include <iostream>
#include <stack>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    //<height, 연속된 같은 키 사람 수>
    stack<pair<int, long long>> st;
    long long result = 0;

    for (int i = 0; i < N; i++)
    {
        //현재 사람 정보 <키, 1>
        int height; cin >> height;
        long long current_count = 1;

        //stack에 있는 사람들이 현재보다 키가 작다면, 결과에 추가한다.
        //stack에 있는 사람은 안쪽에 있을수록 키가 크다. 키가 작아지는 순서의 선택지는 이전 이 코드의 반복에서 사라진다.
        while (!st.empty() && st.top().first < height)
        {
            result += st.top().second;
            st.pop();
        }

        //이전사람들과 키가 같다면 사람 수를 그만큼 증가하고 stack에서 제거한다(정보 축약).
        //키가 같은 연속된 사람 끼리는 볼 수 있으니 그만큼 카운트한다.
        if (!st.empty() && st.top().first == height)
        {
            current_count += st.top().second;
            result += st.top().second;
            st.pop();
        }

        //이전 사람보다 키가 작다면 인접한 경우만 카운트한다.
        if (!st.empty())
        {
            result += 1;
        }

        st.push({height, current_count});
    }

    cout << result;
}