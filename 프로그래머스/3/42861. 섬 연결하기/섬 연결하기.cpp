#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int Start = 0;
const int End = 1;
const int Cost = 2;

vector<int> parents;

int Find(int a)
{
    if (a != parents[a])
    {
        parents[a] = Find(parents[a]);
    }
    
    return parents[a];
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    
    if (a != b)
        parents[b] = a;
}

int solution(int n, vector<vector<int>> costs) {  
    parents.resize(n);
    for (int i = 0; i < n; i++)
        parents[i] = i;
    
    sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b){
       return a[Cost] < b[Cost]; 
    });
    
    int result = 0;
    for (const vector<int> &cost : costs)
    {
        if (Find(cost[Start]) != Find(cost[End]))
        {
            Union(cost[Start], cost[End]);
            result += cost[Cost];
        }
    }
    
    return result;
}