#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // x >= y
    //2x + 2y = brown + 4 -> 짝수 + 짝수로 brown은 짝수
    
    //x + y = brown/2 + 2;
    //x * y = brown + yellow
    
    //y = brown/2 +2 - x
    //x(brown/2 + 2 - x) = brown + yellow
    //brown/2 *x + 2x - x^2 = brown + yellow
    //x^2 - (2 + brown/2)*x  + brown + yellow = 0;
    //(-b +- root(b^2 - 4ac)) / 2a
    // y = ((2 + brown/2) +- sqrt(pow(2 + brown/2) - 4(brown + yellow))) / 2
    
    //근의 공식 중 작은 값
    int y = ((2 + brown/2) - sqrt(pow(2+brown/2, 2) - 4*(brown + yellow))) / 2;
    int x = brown/2 + 2 - y;
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}