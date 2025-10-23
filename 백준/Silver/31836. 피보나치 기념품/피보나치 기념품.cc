#include <iostream>
#include <vector>

// 벡터의 내용을 공백으로 구분하여 출력하는 헬퍼 함수
void print_vector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    // N=2는 예제 1과 동일하게 특별 처리 (사실 N % 3 = 2 로직으로 처리해도 정답)
    if (N == 2) {
        std::cout << 1 << "\n";
        std::cout << 1 << "\n";
        std::cout << 1 << "\n";
        std::cout << 2 << "\n";
        return 0;
    }

    std::vector<int> serim;
    std::vector<int> sungjoo;

    if (N % 3 == 0 || N % 3 == 2) {
        // Case 1: N % 3 = 0 또는 N % 3 = 2
        // N개의 기념품을 모두 사용
        int k = N % 3; // k는 0 또는 2가 됨
        for (int i = 1; i <= N; ++i) {
            if (i % 3 == k) {
                serim.push_back(i);
            } else {
                sungjoo.push_back(i);
            }
        }
    } else {
        // Case 2: N % 3 == 1
        // 1번 기념품을 버리고 N-1개 사용
        // (제출하신 코드처럼 N번을 버리고 1 ~ N-1로 계산해도 정답)
        for (int i = 2; i <= N; ++i) {
            if (i % 3 == 1) { // 2~N 범위에서 i % 3 == 1 인 것
                serim.push_back(i);
            } else {
                sungjoo.push_back(i);
            }
        }
    }

    // 세림이 정보 출력
    std::cout << serim.size() << "\n";
    print_vector(serim);

    // 성주 정보 출력
    std::cout << sungjoo.size() << "\n";
    print_vector(sungjoo);

    return 0;
}