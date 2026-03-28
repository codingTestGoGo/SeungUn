#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    
    if (n == 1) return 1;
    //k가 유지할 수 있는지 확인하려 할떄
    //k 양쪽 다 k보다 작은 수가 남으면 안된다.
    //양쪽 구역의 풍선을 터트리면 k보다 큰 수를 유지하려 할때
    //작은 수 찬스를 사용안하면 구역의 최솟값
    //작은 수 찬스를 사용하면 두번째로 작은 값이 온다.
    //따라서
    
    //0. 누적 합으로 구간별 최솟값 저장
    //1. k의 왼쪽 구역과 오른쪽 구역의 최솟값을 구한다.
    //2. 두 구역 중 하나라도 최솟값이 k보다 크면 통과
    vector<int> minleft(n);
    vector<int> minright(n);
    minleft[0] = a[0];
    minright[n-1] = a[n-1];
    for (int i = 1; i < n-1; i++)
    {
        minleft[i] = min(minleft[i-1], a[i]);
        minright[n-i-1] = min(minright[n-i], a[n-i-1]);
    }
    minleft[n-1] = min(minleft[n-2], a[n-1]);
    minright[0] = min(minright[1], a[0]);
    
    for (int i = 1; i < n-1; i++)
    {
        const int k = a[i];
        const int left = minleft[i-1];
        const int right = minright[i+1];
        if (k < left || k < right)
            answer++;
    }
    
        
    return answer + 2;
}