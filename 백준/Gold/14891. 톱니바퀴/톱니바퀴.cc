#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const bool S = true;
const bool N = false;
vector<vector<bool>> Cogwheels;
vector<pair<int, int>> CogWheelSide;

void SpinWheels(const int CogWheel, const int Way, const vector<bool> &IsSynchro, vector<bool> &visited)
{
    visited[CogWheel-1] = true;
    //printf("%d wheel spin %s\n", CogWheel, Way == 1 ? "right" : "left");

    //휠을 시계방향으로 회전
    pair<int ,int> &WheelSide = CogWheelSide[CogWheel-1];
    if (Way == 1)
    {
        WheelSide.first = WheelSide.first-1 >= 0 ? WheelSide.first-1 : 7;
        WheelSide.second = WheelSide.second-1 >= 0 ? WheelSide.second-1 : 7;
    }

    //반시계 방향으로 회전
    else
    {
        WheelSide.first = WheelSide.first + 1 <= 7 ? WheelSide.first+1 : 0;
        WheelSide.second = WheelSide.second + 1 <= 7 ? WheelSide.second+1 : 0;
    }

    const int leftSync = CogWheel-2;
    const int RightSync = CogWheel-1;

    //왼쪽에 톱니바퀴가 있고, 왼쪽과 싱크되어 있으면
    if (leftSync >= 0 && IsSynchro[leftSync])
    {
        //왼쪽 톱니바퀴를 반대 방향으로 돌림
        if (!visited[CogWheel-2])
            SpinWheels(CogWheel-1, Way*-1, IsSynchro, visited);
    }

    //오른쪽에 톱니바퀴가 있고, 오른쪽과 싱크되어 있으면
    if (RightSync <= 2 && IsSynchro[RightSync])
    {
        //오른쪽 톱니바퀴를 반대 방향으로 돌림
        if (!visited[CogWheel])
            SpinWheels(CogWheel+1, Way*-1, IsSynchro, visited);
    }
}

int main()
{
    Cogwheels.resize(4, vector<bool>(8));
    //톱니바퀴의 왼쪽 오른쪽 방향
    CogWheelSide.resize(4, {6, 2});
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c; cin >> c;
            if (c == '1')
                Cogwheels[i][j] = S;
            else
                Cogwheels[i][j] = N;
        }
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++)
    {
        int CogWheel, Way; cin >> CogWheel >> Way;

        vector<bool> IsSynchro(3, false);
        for (int i = 0; i < 3; i++)
        {
            //왼쪽 휠의 오른쪽 극, 오른쪽 휠의 왼쪽 극
            const bool LW = Cogwheels[i][CogWheelSide[i].second];
            const bool RW = Cogwheels[i+1][CogWheelSide[i+1].first];

            //다르면 움직이고, 같으면 안 움직임
            if (LW != RW)
                IsSynchro[i] = true;
        }
        
        //휠 움직이기
        vector<bool> visited(4, false);
        SpinWheels(CogWheel, Way, IsSynchro, visited);
    }

    int Score = 0;
    for (int i = 0; i < 4; i++)
    {
        int Topidx = CogWheelSide[i].first+2;
        if (Topidx > 7) Topidx -= 8;

        if (Cogwheels[i][Topidx] == S)
            Score += pow(2, i);
    }

    cout << Score;
}