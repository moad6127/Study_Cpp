#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for (auto e : s)
    {
        if (st.empty())
        {
            if (e == ')')
            {
                answer = false;
                break;
            }
            st.push(e);
        }
        else
        {
            if (e == '(')
            {
                st.push(e);
            }
            else
            {
                st.pop();
            }
        }
    }
    if (!st.empty())
    {
        answer = false;
    }

    return answer;
}