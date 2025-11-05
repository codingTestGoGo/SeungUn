#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int min_city_dist = 1e9;
vector<pair<int, int>> houses;
vector<pair<int, int>> chicks;
vector<int> selected_indices;

// M개의 치킨집을 선택하는 조합을 찾는 DFS(백트래킹) 함수
// start_index: 탐색을 시작할 치킨집 인덱스 (조합을 위함)
// count: 현재까지 선택한 치킨집의 개수
void solve(int start_index, int count) 
{
    if (count == m) 
    {
        int current_city_dist = 0;

        for (int i = 0; i < houses.size(); ++i) 
        {
            int min_house_dist = 1e9;
            for (int j = 0; j < selected_indices.size(); ++j) 
            {
                int chick_idx = selected_indices[j];
                int dist = abs(houses[i].first - chicks[chick_idx].first) + 
                           abs(houses[i].second - chicks[chick_idx].second);
                
                min_house_dist = min(min_house_dist, dist);
            }
            current_city_dist += min_house_dist; // 이 집의 치킨 거리를 도시에 더함
        }

        min_city_dist = min(min_city_dist, current_city_dist);
        return;
    }

    for (int i = start_index; i < chicks.size(); ++i) 
    {
        selected_indices.push_back(i);
        solve(i + 1, count + 1);
        selected_indices.pop_back();
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int type;
            cin >> type;
            if (type == 1) 
                houses.push_back({i, j});
            else if (type == 2) 
                chicks.push_back({i, j});
        }
    }

    solve(0, 0); 

    cout << min_city_dist;

    return 0;
}