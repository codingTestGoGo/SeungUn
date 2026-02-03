#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> priorities, int location) {
    
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    int sorting = 1;
    while (!q.empty())
    {
        const pair<int, int> cur = q.front();
        if (cur.second == pq.top())
        {
            if (cur.first == location)
            {
                return sorting;
            }
            q.pop();
            pq.pop();
            sorting++;
        }
        else
        {
            q.pop();
            q.push(cur);
        }
    }
}