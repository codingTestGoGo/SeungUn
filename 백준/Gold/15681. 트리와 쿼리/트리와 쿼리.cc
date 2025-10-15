#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> g;

//임의의 '트리'에서(그래프 아님) 한 정점을 루트로 하는 트리 만들기
void makeTree(int node, int parent, vector<int> &parents, vector<vector<int>> &child)
{
    child[node].reserve(g[node].size());
    for (const int next : g[node])
    {
        if (next != parent)
        {
            //add Node to currentNode's child
            child[node].push_back(next);

            //set node's parent to current node
            parents[next] = node;

            makeTree(next, node, parents, child);
        }
    }
}

void countSubtreeNodes(int node, vector<int> &size, vector<vector<int>> &child)
{
    //루트+1
    size[node] = 1;
    for (const int next : child[node])
    {
        //자식 노드의 서브 트리 노드 갯수를 구하고,
        countSubtreeNodes(next, size, child);

        //구해진 값을 더한다.
        size[node] += size[next];
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    //n 정점의 수, r 루트의 번호, q 쿼리의 수
    int n, r, q; cin >> n >> r >> q;
    g.resize(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> parents(n+1, -1);
    vector<vector<int>> child(n+1);
    makeTree(r, -1, parents, child);
    vector<int> size(n+1, 0);
    countSubtreeNodes(r, size, child);
    for (int i = 0; i < q; i++)
    {
        int query; cin >> query;
        cout << size[query] << '\n';
    }

}