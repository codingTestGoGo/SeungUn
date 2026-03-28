#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
struct Node
{
    int x;
    int y;
    int i;
    int left;
    int right;
};

vector<Node> tree;
int Size = 0;
int root = 0;



void push(const Node &node)
{
    int CurNode = Size;
    tree[CurNode] = node;
    if (Size == 0)
    {
        root = 0;
        //printf("root = %d\n", node.i);
        Size++;
        return;
    }
    
    //루트보다 y좌표가 크면 루트 교체
    if (tree[root].y < tree[CurNode].y)
    {
        if (tree[root].x < tree[CurNode].x)
            tree[CurNode].left = root;
        
        else
            tree[CurNode].right = root;
        root = CurNode;
        //printf("root = %d\n", node.i);
        Size++;
        return;
    }
    
    int NextNode = root;
    while (true)
    {
        if (tree[NextNode].x < node.x)
        {
            if (tree[NextNode].right == -1)
            {
                tree[NextNode].right = CurNode;
                break;
            }
            NextNode = tree[NextNode].right;
        }
        else
        {
            if (tree[NextNode].left == -1)
            {
                tree[NextNode].left = CurNode;
                break;
            }
            NextNode = tree[NextNode].left;
        }
    }
    Size++;
}

vector<vector<int>> answer;
void searchTree(int CurNode)
{
    answer[0].push_back(tree[CurNode].i);
    
    if (tree[CurNode].left != -1)
        searchTree(tree[CurNode].left);
    
    if (tree[CurNode].right != -1)
        searchTree(tree[CurNode].right);
    
    answer[1].push_back(tree[CurNode].i);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    answer.resize(2);
    tree.resize(nodeinfo.size());
    vector<Node> nodes(nodeinfo.size());
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        const vector<int> &node =  nodeinfo[i];
        nodes[i] = {node[0], node[1], i+1, -1, -1};
    }
    
    sort(nodes.begin(), nodes.end(), [](const Node &a, const Node &b){
       return a.y > b.y; 
    });
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        push(nodes[i]);
    }
    
    //전위 후위 탐색->O(2n)
    searchTree(root);
    return answer;
}