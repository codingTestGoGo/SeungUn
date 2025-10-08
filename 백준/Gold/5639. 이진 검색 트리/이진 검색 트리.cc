#include <iostream>
#include <vector>

using namespace std;

void postorder(vector<int> &preorder, int start, int end)
{
    if (start > preorder.size() || end < 0) return;

    if (start > end) return;


    //왼쪽 트리와 오른쪽 트리를 찾아낸 후, 루트를 호출하면 된다.
    //트리 단위로 볼 때, 언제나 첫 번째는 루트 노드이다.
    int root = preorder[start];

    //왼쪽 트리의 end를 찾아낸다.
    int middle = start+1;
    for (; middle < preorder.size() && preorder[middle] < root; middle++);

    //왼쪽 트리 탐색
    postorder(preorder, start+1, middle-1);

    //오른쪽 트리 탐색
    postorder(preorder, middle, end);

    //후위탐색이므로, 자식 트리를 모두 탑색하고 나면 루트 출력
    cout << root << '\n';
}



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> preorder;

    int num;
    while (cin >> num) preorder.push_back(num);

    postorder(preorder, 0, preorder.size()-1);
}