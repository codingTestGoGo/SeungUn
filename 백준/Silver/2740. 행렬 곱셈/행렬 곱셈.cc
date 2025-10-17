#include <iostream>

using namespace std;


int main()
{
  int n, m, k;
  int p[100][100];
  int q[100][100];
  int res[100][100];

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> p[i][j];
    }
  }

  // cout << '\n';
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cout << p[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  cin >> m >> k;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < k; j++)
    {
      cin >> q[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      //res[i][j] = p[i][0] * q[0][k] + p[i][1] * q[1][k] .. + p[i][m] * q[m][k]
      for (int c = 0; c < m; c++)
      {
        res[i][j] += p[i][c] * q[c][j];
        //printf("p[%d][%d] * q[%d][%d] = %d, res[%d][%d] = %d\n", i, c, c, k, i, j, res[i][j]);
      }
      cout << res[i][j] << ' ';
    }
    cout << '\n';
  }


}
