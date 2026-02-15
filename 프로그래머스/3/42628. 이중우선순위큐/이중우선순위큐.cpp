#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<>> pq_min;
    
    //st_min 최대 힙에서 제거된 숫자, 가장 작은 숫자가 맨 위에
    //st_max 최소 힙에서 제거된 숫자, 가장 큰 숫자가 맨 위에
    priority_queue<int> st_max;
    priority_queue<int, vector<int>, greater<>> st_min;
    for (const string &op : operations)
    {
        stringstream ss(op);
        string operation; ss >> operation;
        string num; ss >> num;
        if (operation == "I")
        {
            int numi = stoi(num);
            pq_max.push(numi);
            pq_min.push(numi);
        }
        else if (operation == "D")
        {
            //최댓값 삭제
            if (num == "1")
            {
                //최소 힙에서 제거된 숫자 중 가장 큰 숫자가 최대 힙 숫자와 같으면 제거
                while (!st_max.empty() && !pq_max.empty() && st_max.top() == pq_max.top())
                {
                    pq_max.pop();
                    st_max.pop();
                }
                
                //최댓값 삭제, 삭제된 숫자 등록
                if (!pq_max.empty())
                {
                    int top = pq_max.top();
                    pq_max.pop();
                    st_min.push(top);
                }
            }
            else if (num == "-1")
            {
                //최대 힙에서 제거된 숫자 중 가장 작은 숫자가 최소 힙 숫자와 같으면 제거
                while (!st_min.empty() &&  !pq_min.empty() && st_min.top() == pq_min.top())
                {
                    pq_min.pop();
                    st_min.pop();
                }
                
                //최솟값 삭제, 삭제된 숫자 등록
                if (!pq_min.empty())
                {
                    int top = pq_min.top();
                    pq_min.pop();
                    st_max.push(top);
                }
            }
        }
    }
    
    //최대 최소 힙에서 제거된 숫자 마저 제거
    while (!st_max.empty() && !pq_max.empty() && st_max.top() == pq_max.top())
    {
        pq_max.pop();
        st_max.pop();
    }
    
    while (!st_min.empty() &&  !pq_min.empty() && st_min.top() == pq_min.top())
    {
        pq_min.pop();
        st_min.pop();
    }
    
    if (pq_max.empty())
    {
        answer.push_back(0); answer.push_back(0);
    }
    else
    {
        answer.push_back(pq_max.top()); answer.push_back(pq_min.top());
    }
    
    return answer;
}