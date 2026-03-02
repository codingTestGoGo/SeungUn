#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0, Server = 1;
    
    //{종료 시간, 서버 갯수}
    queue<pair<int, int>> servers;
    
    
    for (int h = 0; h < players.size(); h++)
    {
        const int Player = players[h];
        const int remainPlayer = Player - Server * m;
        if (remainPlayer >= 0)
        {
            const int Needs = (remainPlayer / m) + 1;
            Server += Needs;
            answer += Needs;
            servers.push({h+k-1, Needs});
        }
        
        while (!servers.empty() && servers.front().first <= h)
        {
            Server -= servers.front().second;
            servers.pop();
        }
    }
    
    return answer;
}