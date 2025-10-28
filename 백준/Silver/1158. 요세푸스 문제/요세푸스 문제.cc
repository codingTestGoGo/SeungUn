#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    cout << "<";

    while (!q.empty()) {
        
        // a. K-1번 사람을 맨 뒤로 보냄
        for (int i = 0; i < K - 1; ++i) {
            int front_person = q.front();
            q.pop();
            q.push(front_person);
        }

        int removed_person = q.front();
        q.pop();
        cout << removed_person;

        if (!q.empty()) {
            cout << ", ";
        }
    }

    cout << ">\n";

    return 0;
}