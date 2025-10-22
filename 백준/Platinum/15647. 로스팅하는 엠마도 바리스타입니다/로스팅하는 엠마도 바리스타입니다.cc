#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> parents;
vector<vector<pair<int, int>>> childs;
vector<int> cnt;
vector<long long> dists;
int n;

void printTreeState();

void makeTree(int node, int parent)
{
    cnt[node] = 1;

    for (const pair<int, int> &childNode : graph[node])
    {
        const int next = childNode.first;
        const int dist = childNode.second;
        if (next != parent)
        {
            parents[next] = node;
            childs[node].push_back({next, dist});

            makeTree(next, node);
            dists[node] += dists[next] + (long long)cnt[next] * dist;
            cnt[node] += cnt[next];
        }   
    }

    //printf("dist[%d] = %d, cnt[%d] = %d\n", node, dists[node], node, cnt[node]);
}

//1
//2       6
//3 4     9 10
//  7 8 5

void mindistTree(int node)
{
    for (const pair<int, int> &childNode : childs[node])
    {
        const int child = childNode.first;
        const int d = childNode.second;
        //printf("child %d  : dist[node] = %d, left char %d, +dist %d, dists[%d],", child, dists[node], dists[child] + d*cnt[child], d*(cnt[node] - cnt[child]), dists[child]);             
        dists[child] = dists[node] - (long long)d*cnt[child] + (long long)d*(n - cnt[child]);
        //printf("result = %d\n",  dists[child]);
        mindistTree(child);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    graph.resize(n+1);
    parents.resize(n+1, -1);
    childs.resize(n+1);
    cnt.resize(n+1, 0);
    dists.resize(n+1, 0);

    for (int i = 0; i < n-1; i++)
    {
        int u, v, d; cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    //루트 1에 대해 트리를 구하면서 최단거리 dist[1] 측정
    //자식 노드의 최단거리의 합은
    //자식노드를 child, 부모를 node
    //트리의 노드 갯수를 cnt, child와 node의 거리를 d일때
    //dists[child] = dists[node] + d*(cnt[node] - cnt[child]) + dists[child];
    makeTree(1, -1);
    mindistTree(1);

    for (int i = 1; i <= n; i++)
    {
        cout << dists[i] << '\n';
    }
}