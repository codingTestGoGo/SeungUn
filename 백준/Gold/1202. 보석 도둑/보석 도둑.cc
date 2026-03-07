#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   int n, k; cin >> n >> k;
   vector<int> bags(k);
   vector<pair<int, int>> jewels(n);

   priority_queue<int> pq;
   for (int i = 0; i < n; i++)
   {
     int m, v; cin >> m >> v;
     jewels[i] = {m, v};
   }

   for (int i = 0; i < k; i++)
   {
      cin >> bags[i];
   }

   sort(jewels.begin(), jewels.end());
   sort(bags.begin(), bags.end());

   unsigned long long answer = 0;
   int ji = 0;
   for (const int &bag : bags)
   {
        while (ji < jewels.size() && jewels[ji].first <= bag)
        {
            pq.push(jewels[ji].second);
            ji++;
        }
        
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();  
        }
   }

   cout << answer;
}