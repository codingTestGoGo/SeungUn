#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, K;
int map[20][20];
// 주사위 상태: 0:빈칸, 1:윗면, 2:뒷면(북), 3:오른쪽(동), 4:왼쪽(서), 5:앞면(남), 6:아랫면
int dice[7] = {0, 0, 0, 0, 0, 0, 0};

// 이동 방향: 1:동, 2:서, 3:북, 4:남
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void roll(int dir) {
    int d1=dice[1], d2=dice[2], d3=dice[3], d4=dice[4], d5=dice[5], d6=dice[6];
    
    if (dir == 1) { // 동
        dice[1] = d4; dice[3] = d1; dice[6] = d3; dice[4] = d6;
    } else if (dir == 2) { // 서
        dice[1] = d3; dice[4] = d1; dice[6] = d4; dice[3] = d6;
    } else if (dir == 3) { // 북
        dice[1] = d5; dice[2] = d1; dice[6] = d2; dice[5] = d6;
    } else if (dir == 4) { // 남
        dice[1] = d2; dice[5] = d1; dice[6] = d5; dice[2] = d6;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int dir;
        cin >> dir;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 지도를 벗어나는 경우 해당 명령 무시
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        // 주사위 굴리기
        roll(dir);
        x = nx; y = ny;

        // 바닥면 상태 확인 및 복사
        if (map[x][y] == 0) {
            map[x][y] = dice[6];
        } else {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }

        // 윗면 출력
        cout << dice[1] << "\n";
    }

    return 0;
}