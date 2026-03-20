#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

string GetWord(const string &message, int start, int end)
{
    string res(message.begin() + start, message.begin() + end);
    return res;
}

//true : 스포일러 단어
bool UpdateSpoilerRanges(int &s_ri, const vector<vector<int>> &spoiler_ranges, const int wstart, const int wend)
{
    if (s_ri >= spoiler_ranges.size())
        return false;
    
    int spstart = spoiler_ranges[s_ri][0], spend = spoiler_ranges[s_ri][1];
//     cout << wstart << ' ' << wend << '\n';
//     cout << spstart << ' ' << spend << '\n'; 
    
    if (wend < spstart)
    {
        return false;
    }
    if (wend >= spstart && wend <= spend)
    {
        return true;
    }
    
    //이 이후에 경우는 다음 탐색에 다음 범위로 넘어감
    s_ri++;
    
    //스포일러 범위가 단어 안에 있는 경우
    if (wstart <= spstart && wend >= spend)
    {
        return true;
    }
    
    if (wstart >= spstart && wstart <= spend)
    {
        return true;
    }
    
    else if (wstart > spend)
    {
        //다음 스포일러 범위 탐색
        return UpdateSpoilerRanges(s_ri, spoiler_ranges, wstart, wend);
    }
    
    return false;
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    //스포 방지 단어와 그렇지 않은 단어 구분'
    vector<string> spoilers;
    set<string> not_spoilers;
    set<string> openned_spoilers;
    int s_ri = 0;
    int answer = 0;
    int index = 0;
    while (index < message.size())
    {
        if (message[index] == ' ')
            index++;
        else
        {
            const int wstart = index;
            int wend = wstart;
            while (wend < message.size() && message[wend] != ' ')
                wend++;
            
            string word = GetWord(message, wstart, wend);
            if (UpdateSpoilerRanges(s_ri, spoiler_ranges, wstart, wend-1))
            {
                //cout << "spoiler word : '" << word << "'\n";
                spoilers.push_back(word);
            }
            else
            {
                //cout << "not_spoiler word : '" << word << "'\n";
                not_spoilers.insert(word);
            }
            
            index = wend;
        }
    }
    //스포 방지 단어를 하나씩 공개
    for (const string &word : spoilers)
    {
        //1. 이전에 공개된 스포 방지 단어에 있는지 확인
        if (openned_spoilers.find(word) != openned_spoilers.end())
        {
            continue;
        }
        
        openned_spoilers.insert(word);
        //2. 스포 방지가 아닌 단어에 있는지 확인
        if (not_spoilers.find(word) != not_spoilers.end())
        {
            continue;
        }
        
        //3. 검사를 통과하면 answer+1
        answer++;
    }
    return answer;
}