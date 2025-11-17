#include <iostream>
#include <string> 
#include <stack>

using namespace std;
string s;

bool IsAlphabet(const char &c)
{
    return (c >= 'A' && c <= 'Z');
}


int level(const char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0; 
}

int main()
{
    cin >> s;
    stack<char> operations; // 연산자만 저장할 스택

    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];

        if (IsAlphabet(c))
        {
            cout << c;
        }
        
        else if (c == '(')
        {
            operations.push(c);
        }
        
        else if (c == ')')
        {
          
            while (!operations.empty() && operations.top() != '(')
            {
                cout << operations.top();
                operations.pop();
            }
           
            if (!operations.empty())
                operations.pop(); 
        }
        
        else
        {
            while (!operations.empty() && operations.top() != '(' && level(operations.top()) >= level(c))
            {
                cout << operations.top();
                operations.pop();
            }
            
            operations.push(c);
        }
    }

    
    while (!operations.empty())
    {
        cout << operations.top();
        operations.pop();
    }

    return 0;
}