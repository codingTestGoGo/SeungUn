#include <iostream>
#include <vector>

using namespace std;
int r, c;
vector<vector<char>> map;
vector<bool> aplphabets;
vector<vector<bool>> visited;

int updown[4] = {1, -1, 0, 0};
int leftright[4] = {0, 0, -1, 1};
int result = 0;

void dfs(int y, int x, int count)
{
    char ch = map[y][x];
    aplphabets[ch - 'A'] = true;
    visited[y][x] = true;
    count += 1;

    //printf("c = %c, alphabet[%d] = true\n", ch, ch - 'A');
    for (int i = 0; i < 4; i++)
    {
        int nexty = y + updown[i];
        int nextx = x + leftright[i];

        if (nexty < 0 || nexty >= r || nextx < 0 || nextx >= c)
        {
            continue;
        }

        //printf("nexty = %d, nextx = %d\n", nexty, nextx);
        const char nextc = map[nexty][nextx] - 'A';

        if (!visited[nexty][nextx] && !aplphabets[nextc])
        {
            dfs(nexty, nextx, count);
        }
    }

    if (result < count)
        result = count;

    aplphabets[ch - 'A'] = false;
    visited[y][x] = false;
}

int main()
{
   cin >> r >> c;
   map.resize(r, vector<char>(c));
   visited.resize(r, vector<bool>(c, false));
   for (int i = 0; i < r; i++)
   {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
   }

   aplphabets.resize('Z' - 'A' + 1, false);
   //printf("alphabet size = %d\n", aplphabets.size());
   dfs(0, 0, 0);

   cout << result;
}