#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool check(const vector<vector<int>> &q, const vector<int> &ans, const vector<int> &cur)
{
   for (int qi = 0; qi < q.size(); qi++)
   {
       const vector<int> &curq = q[qi];
       const int &curans = ans[qi];
       
       int i = 0, j = 0, same = 0;
       while (i < curq.size() && j < cur.size())
       {
           if (curq[i] == cur[j])
           {
               i++;
               j++;
               same++;
           }
           else if (curq[i] > cur[j])
           {
               j++;
           }
           else
           {
               i++;
           }
       }
       
       if (same != curans)
            return false;
   }    
    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    vector<int> cur;
    for (int a = 1; a <= n-4; a++)
    {
        for (int b = a+1; b <= n-3; b++)
        {
            for (int c = b+1; c <= n-2; c++)
            {
                for (int d = c+1; d <= n-1; d++)
                {
                    for (int e = d+1; e <= n; e++)
                    {
                        if (check(q, ans, {a, b, c, d, e}))
                        {
                            answer+=1;
                        }
                    }
                }
            }
        }
    }
    return answer;
}