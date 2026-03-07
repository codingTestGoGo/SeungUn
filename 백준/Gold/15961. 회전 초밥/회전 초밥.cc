#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n);
    for (int i = 0; i < n; i++) cin >> sushi[i];

    vector<int> cnt(d + 1, 0);
    int kind = 0;

    // 1. 초기 윈도우 설정 (0번부터 k개)
    for (int i = 0; i < k; i++) {
        if (cnt[sushi[i]] == 0) kind++;
        cnt[sushi[i]]++;
    }

    // 2. 쿠폰 처리 (쿠폰 초밥이 윈도우에 없으면 가짓수 +1)
    int max_kind = kind;
    if (cnt[c] == 0) max_kind = kind + 1;


    // 3. 슬라이딩 윈도우 이동
    for (int i = 0; i < n; i++) {
        // 맨 앞 초밥 제거 (sushi[i])
        cnt[sushi[i]]--;
        if (cnt[sushi[i]] == 0) kind--;

        // 맨 뒤 초밥 추가 (sushi[(i + k) % n])
        int next = sushi[(i + k) % n];
        if (cnt[next] == 0) kind++;
        cnt[next]++;

        // 현재 가짓수 계산 (쿠폰 포함)
        int current_kind = kind;
        if (cnt[c] == 0) current_kind++;

        max_kind = max(max_kind, current_kind);
        
        // 조기 종료 최적화 (이론상 최대 종류는 k+1)
        if (max_kind == k + 1) break;
    }

    cout << max_kind;

    return 0;
}