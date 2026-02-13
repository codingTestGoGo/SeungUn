#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    };
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>> mp;
    unordered_map<string, int> total;
    for (int i = 0; i < genres.size(); i++)
    {
        mp[genres[i]].push({plays[i], i});
        total[genres[i]] += plays[i];
    }
    
    priority_queue<pair<int, string>> pq;
    for (const auto &[key, value] : total)
    {
        pq.push({value, key});
    }
    
    while (!pq.empty())
    {
        const string genre = pq.top().second;
        pq.pop();
        
        int count = 2;
        while (!mp[genre].empty() && count > 0)
        {
            answer.push_back(mp[genre].top().second);
            mp[genre].pop();
            count--;
        }
    }
    return answer;
}