#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

int ud[4] = {-1, 0, 1, 0};
int lr[4] = {0, -1, 0, 1};
int n, m;
vector<vector<int>> map;
vector<vector<bool>> visited;
int cnt = 0;

bool SearchRoom(const pair<int, int> &Node, int &d, pair<int, int> &NextNode);

bool ClearRoom(const pair<int, int> &Node, int d)
{
    //현재 칸이 청소 되어 있지 않다면 청소
    if (!visited[Node.first][Node.second])
    {
        cnt += 1;
        //printf("clear room [%d, %d], d = %d\n", Node.first, Node.second, d);
    }

    visited[Node.first][Node.second] = true;

    //4방향 탐색 시작
    pair<int, int> NextNode;
    bool bResult = SearchRoom(Node, d, NextNode);
    if (bResult)
    {
        return ClearRoom(NextNode, d);
    }

    //갈 곳이 없다면 현재 보는 방향 뒤쪽으로 후퇴 시도
    else
    {
        int backWay = (d+2)%4;
        pair<int, int> backNode = make_pair<int , int>(Node.first + ud[backWay], Node.second + lr[backWay]);

        //만약 후진할 수 없다면(방이 없거나 벽이라면)
        if (backNode.first < 0 || backNode.first >= n || backNode.second < 0 || backNode.second >= m
            || map[backNode.first][backNode.second])
        {
            //종료
            //printf("can't go back, system off\n");
            return false;
        }

        //후퇴이므로 방향 유지
        //printf("search failed, back to [%d, %d]\n", backNode.first, backNode.second);
        return ClearRoom(backNode, d);
    }
}

bool SearchRoom(const pair<int, int> &Node, int &d, pair<int, int> &NextNode)
{
    for (int i = 1; i < 5; i++)
    {
        //현재 방향에서 90도 회전
        int curWay = (d+i)%4;

        const int nexty = Node.first + ud[curWay];
        const int nextx = Node.second + lr[curWay];
        if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;

        //방문 안한 곳이 있다면 값 저장 후 리턴
        if (map[nexty][nextx] != 1 && !visited[nexty][nextx])
        {
            d = curWay;
            NextNode.first = nexty;
            NextNode.second = nextx;
            return true;
        }
    }

    //모든 방면이 청소되었다면 return false;
    return false;
}

int main()
{
    cin >> n >> m;
    pair<int, int> start; int d; cin >> start.first >> start.second >> d;

    map.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    if (d == 1) d = 3;
    else if (d == 3) d = 1;
    ClearRoom(start, d);

    cout << cnt;
}