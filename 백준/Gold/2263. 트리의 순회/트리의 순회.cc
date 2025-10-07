#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
vector<int> position; 

void getPreorder(int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd || postStart > postEnd)
    {
        return;
    }

    int root = postorder[postEnd];
    cout << root << ' ';

    int rootPos = position[root];
    int leftSize = rootPos - inStart;

    getPreorder(inStart, rootPos - 1, postStart, postStart + leftSize - 1);
    getPreorder(rootPos + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    inorder.resize(n);
    postorder.resize(n);
    position.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        position[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    getPreorder(0, n - 1, 0, n - 1);

    return 0;
}