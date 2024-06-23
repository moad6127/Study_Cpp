#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    for (auto e : s)
    {
        if (st.empty())
        {
            st.push(e);
        }
        else
        {
            if (e == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(e);
            }
        }
    }

    return st.empty();
}