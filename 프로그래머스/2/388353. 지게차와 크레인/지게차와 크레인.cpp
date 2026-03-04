#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>

using namespace std;

int ud[4] = {-1, 1, 0, 0};
int lr[4] = {0, 0, -1, 1};
int n, m;

bool bfs(const pair<int, int> start, const vector<string> &storage)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    
    while (!q.empty())
    {
        const pair<int, int> cur = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            const int nexty = cur.first + ud[i];
            const int nextx = cur.second + lr[i];

            if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
                continue;
            
            if (!visited[nexty][nextx] && storage[nexty][nextx] == '1')
            {
                if (nexty == 0 || nexty == n-1 || nextx == 0 || nextx == m-1)
                    return true;
                
                q.push({nexty, nextx});
                visited[nexty][nextx] = true;
            }
        }
    }
    
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n = storage.size(), m = storage[0].size();
    
    for (const string &request : requests)
    {
        const char ch = request[0];
        const int length = request.size();
        
        if (length == 1)
        {
            for (int i = 0; i < storage.size(); i++)
            {
                string &s = storage[i];
                for (int j = 0; j < s.size(); j++)
                {
                    if (s[j] == ch)
                    {
                        if (i == 0 || i == n-1 || j == 0 || j == m-1)
                            s[j] = '0';
                        else if (bfs({i, j}, storage))
                        {
                            s[j] = '0';
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < storage.size(); i++)
            {    
                string &s = storage[i];
                for (int j = 0; j < s.size(); j++)
                {
                    if (s[j] == ch)
                    {
                        s[j] = '0';
                    }
                }
            }
        }
        
        //printf("ch = %c, length = %d\n", ch, length);
        for (int i = 0; i < storage.size(); i++)
        {
            string &s = storage[i];
            //cout << s << '\n';
            for (char &c : s)
            {
                if (c == '0')
                    c = '1';
            }
        }
    }
    
    for (int i = 0; i < storage.size(); i++)
    {
        string &s = storage[i];
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] != '1' && s[j] != '0')
                answer += 1;
        }
     }
    return answer;
}