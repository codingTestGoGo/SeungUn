#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int max_block = 0;

// 보드를 특정 방향으로 이동시키고 병합하는 함수
void move_board(int dir, vector<vector<int>>& board) {
    // dir -> 0: 위, 1: 아래, 2: 왼쪽, 3: 오른쪽
    for (int i = 0; i < n; ++i) {
        vector<int> line;
        
        // 1. 0이 아닌 숫자만 순서대로 추출
        for (int j = 0; j < n; ++j) {
            int r = i, c = j;
            if (dir == 0) { r = j; c = i; }             // 위로 이동: 열(i) 고정, 행(j) 순회
            else if (dir == 1) { r = n - 1 - j; c = i; }// 아래로 이동: 열(i) 고정, 행 역순(n-1-j) 순회
            else if (dir == 2) { r = i; c = j; }        // 왼쪽으로 이동: 행(i) 고정, 열(j) 순회
            else if (dir == 3) { r = i; c = n - 1 - j; }// 오른쪽으로 이동: 행(i) 고정, 열 역순(n-1-j) 순회
            
            if (board[r][c] != 0) {
                line.push_back(board[r][c]);
            }
        }
        
        // 2. 추출된 숫자들을 1회 병합 규칙에 맞게 처리
        vector<int> merged;
        for (size_t k = 0; k < line.size(); ++k) {
            if (k + 1 < line.size() && line[k] == line[k+1]) {
                merged.push_back(line[k] * 2);
                k++; // 합쳐졌으므로 다음 인덱스는 건너뜀
            } else {
                merged.push_back(line[k]);
            }
        }
        
        // 3. 남은 공간을 0으로 채움
        while (merged.size() < n) {
            merged.push_back(0);
        }
        
        // 4. 완성된 줄을 다시 보드의 원래 위치에 덮어씀
        for (int j = 0; j < n; ++j) {
            int r = i, c = j;
            if (dir == 0) { r = j; c = i; }
            else if (dir == 1) { r = n - 1 - j; c = i; }
            else if (dir == 2) { r = i; c = j; }
            else if (dir == 3) { r = i; c = n - 1 - j; }
            
            board[r][c] = merged[j];
        }
    }
}

// DFS를 이용한 완전 탐색 (최대 5회)
void dfs(int cnt, vector<vector<int>> board) {
    // 5번 이동을 완료한 경우 최댓값 갱신 후 반환
    if (cnt == 5) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                max_block = max(max_block, board[i][j]);
            }
        }
        return;
    }
    
    // 4가지 방향에 대해 DFS 수행
    for (int i = 0; i < 4; ++i) {
        vector<vector<int>> next_board = board; // 이전 상태 복사
        move_board(i, next_board);
        dfs(cnt + 1, next_board);
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> n)) return 0;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    
    dfs(0, board);
    
    cout << max_block << "\n";
    
    return 0;
}