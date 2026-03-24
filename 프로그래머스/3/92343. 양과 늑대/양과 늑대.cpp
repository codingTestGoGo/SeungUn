#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges)
{
    int answer = 0;
    int n = info.size();
    vector<vector<int>> tree(n);
    for (const vector<int> &edge : edges)
    {
        const int n1 = edge[0], n2 = edge[1];
        tree[n1].push_back(n2);
    }
    
    auto dfs = [&](int state, int sheep, int wolf, auto&& dfs) -> void
    {
        answer = max(answer, sheep);    
        for (int i = 0; i < n; i++)
        {
            if (state & (1 << i))
            {
                const int sh = sheep + (info[i] ? 0 : 1);
                const int wf = wolf + (info[i] ? 1 : 0);
                
                if (sh <= wf) continue;
                
                int newState = state;
                newState &= ~(1 << i);
                for (int next : tree[i])
                {
                    newState |= (1 << next);
                }
                
                dfs(newState, sh, wf, dfs);
            }
        }
    };
    
    int init = 0;
    for (int next : tree[0])
    {
        init |= (1 << next);
    }
    dfs(init, 1, 0, dfs);
    return answer;
}