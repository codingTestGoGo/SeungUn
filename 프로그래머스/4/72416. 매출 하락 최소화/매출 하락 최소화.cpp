#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>

using namespace std;
vector<vector<int>> tree;
vector<int> ss;
vector<vector<int>> dp;
int answer = 0;
void backtracking(int Node)
{
    //자신 선택 비용
    dp[Node][1] = ss[Node-1];
    
    //리프인 경우
    if (tree[Node].empty())
    {
        dp[Node][0] = 0;
        return;
    }
    
    bool bSelected = false;
    int minchild = INT_MAX;
    for (const int next : tree[Node])
    {
        //자식 노드의 경우 먼저 구함
        backtracking(next);
        
        //자식 팀원의 결과값 중 적은 값을 더함
        int lowest = min(dp[next][0], dp[next][1]);
        dp[Node][0] += lowest;
        dp[Node][1] += lowest;
        
        if (dp[next][0] > dp[next][1])
        {
            bSelected = true;
        }
        else
        {
            minchild = min(minchild, dp[next][1] - dp[next][0]);
        }
    }
    
    //자식들중 아무도 선택 안된 경우, 가장 싼 값을 더함
    if (!bSelected)
    {
        dp[Node][0] += minchild;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    ss = sales;
    tree.resize(sales.size()+1);
    dp.resize(sales.size()+1, vector<int>(2, 0));
    for (const vector<int> &link : links)
    {
        tree[link[0]].push_back(link[1]);
    }
    
    backtracking(1);
    return min(dp[1][0], dp[1][1]);
}