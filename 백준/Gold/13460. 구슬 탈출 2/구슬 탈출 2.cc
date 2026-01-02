#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
char map[11][11];
bool visited[11][11][11][11]; // Red_y, Red_x, Blue_y, Blue_x
int dy[] = {0, 0, -1, 1}; // 동, 서, 북, 남
int dx[] = {1, -1, 0, 0};

struct State {
    int ry, rx, by, bx, depth;
};

// 구슬을 한 방향으로 끝까지 미는 함수
void move(int &y, int &x, int &distance, int i) {
    while (map[y + dy[i]][x + dx[i]] != '#' && map[y][x] != 'O') {
        y += dy[i];
        x += dx[i];
        distance++;
    }
}

int bfs(int sry, int srx, int sby, int sbx) {
    queue<State> q;
    q.push({sry, srx, sby, sbx, 0});
    visited[sry][srx][sby][sbx] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.depth >= 10) break;

        for (int i = 0; i < 4; i++) {
            int nry = cur.ry, nrx = cur.rx, nby = cur.by, nbx = cur.bx;
            int r_dist = 0, b_dist = 0;

            // 각각 이동
            move(nry, nrx, r_dist, i);
            move(nby, nbx, b_dist, i);

            // 파란 구슬이 구멍에 빠지면 무조건 실패 (이번 경로는 무시)
            if (map[nby][nbx] == 'O') continue;

            // 빨간 구슬만 구멍에 빠지면 성공
            if (map[nry][nrx] == 'O') return cur.depth + 1;

            // 두 구슬이 겹쳤을 경우 처리
            if (nry == nby && nrx == nbx) {
                if (r_dist > b_dist) { // 빨간 구슬이 더 많이 움직였다면 뒤에 있었던 것
                    nry -= dy[i]; nrx -= dx[i];
                } else { // 파란 구슬이 더 많이 움직였다면
                    nby -= dy[i]; nbx -= dx[i];
                }
            }

            // 방문하지 않은 상태라면 큐에 삽입
            if (!visited[nry][nrx][nby][nbx]) {
                visited[nry][nrx][nby][nbx] = true;
                q.push({nry, nrx, nby, nbx, cur.depth + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ry, rx, by, bx;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                ry = i; rx = j;
            } else if (map[i][j] == 'B') {
                by = i; bx = j;
            }
        }
    }

    cout << bfs(ry, rx, by, bx) << endl;
    return 0;
}