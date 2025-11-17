#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<int>> map;
int count = 0;

#define horizonal 0
#define vertical 1
#define digonal 2

void dfs(int BeforePosition, int y, int x)
{
    //printf("dfs %d %d\n", y, x);
    if (y == n-1 && x == n-1)
    {
        count += 1;
        return;
    }

    //오른쪽 이동
    //printf("beforeposistion = %d, %d < %d, map[%d][%d] == %d\n", BeforePosition, x+1, n, y, x+1, map[y][x+1]);
    if (BeforePosition != vertical && x+1 < n && map[y][x+1] != 1)
    {
        dfs(horizonal, y, x+1);
    }

    //아래로 이동
    if (BeforePosition != horizonal && y+1 < n && map[y+1][x] != 1)
    {
        dfs(vertical, y+1, x);
    }

    //대각선 이동
    if (x+1 < n && y+1 < n && map[y+1][x+1] != 1 && map[y][x+1] != 1 && map[y+1][x] != 1)
    {
        dfs(digonal, y+1, x+1);
    }
}


int main()
{
    cin >> n;
    map.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    //dfs
    dfs(horizonal, 0, 1);
    cout << count;
}