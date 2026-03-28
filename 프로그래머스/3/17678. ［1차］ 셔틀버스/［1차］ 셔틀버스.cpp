#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<pair<int, int>> crews(timetable.size());
    
    for (int i = 0; i < timetable.size(); i++)
    {
        stringstream ss(timetable[i]);
        string h, m;
        getline(ss, h, ':');
        getline(ss, m);
        crews[i] = {stoi(h), stoi(m)};
    }
    
    //빠른 순서대로 크루 정렬
    sort(crews.begin(), crews.end(), [](const pair<int, int> &a, const pair<int, int> &b){
       if (a.first !=  b.first)
           return a.first < b.first;
        return a.second < b.second;
    });
    
    //9시 버스 시작
    int start = 60*9;
    
    //가장 마지막 버스에 한자리 남을때까지 사람들을 보낸다.
    int tm = start, lasttm = start + t*(n-1);
    int front = 0;
    int ct = 0;
    while (front < crews.size() && tm <= lasttm)
    {
        int canride = tm == lasttm ? m-1 : m;
        while (crews[front].first * 60 + crews[front].second <= tm && canride)
        {
            front++;
            canride--;
        }
        
        tm = tm + t;
    }
    
   // cout << "front = " << front;
    
    //마지막 버스, 마지막 사람보다 1분 빠르게 탄다.
    //새치기할 사람이 없다면, 버스 도착 시간에 맞추어 탄다.
    if (front >= crews.size())
    {
        tm = lasttm;
    }
    else
    {
        tm = min(lasttm, crews[front].first * 60 + crews[front].second - 1);
    }
    
    string hour, minute;
    if (tm / 60 < 10)
    {
        hour = "0";
    }
    hour += to_string(tm/60);
    
    if (tm % 60 < 10)
    {
        minute = "0";
    }
    minute += to_string(tm%60);
    answer = hour + ":" + minute;
    return answer;
}