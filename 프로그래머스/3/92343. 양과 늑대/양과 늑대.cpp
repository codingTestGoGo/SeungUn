#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

vector<vector<int>> tree;
vector<int> info_v;
int ans = 0;

void dfs(vector<int> next_nodes, int sheep, int wolf)
{
    ans = max(ans, sheep);
    //printf("ans = %d, sheep = %d, wolf = %d\n", ans, sheep, wolf);
    for (int i = 0; i < next_nodes.size(); i++)
    {
        int node = next_nodes[i];
        
        const int sh = sheep + (info_v[node] ? 0 : 1);
        const int wf = wolf + (info_v[node] ? 1 : 0);
        if (sheep <= wolf) continue;
        
        vector<int> temp(next_nodes.begin(), next_nodes.end());
        swap(temp[i], temp[temp.size()-1]);
        temp.pop_back();
        for (int next : tree[node])
        {
            temp.push_back(next);
        }
        
        dfs(temp, sh, wf);
    }
}


int solution(vector<int> info, vector<vector<int>> edges)
{
    info_v = info;
    tree.resize(info.size());
    for (const vector<int> &edge : edges)
    {
        const int n1 = edge[0], n2 = edge[1];
        tree[n1].push_back(n2);
    }
    
    dfs(tree[0], 1, 0);
    return ans;
}