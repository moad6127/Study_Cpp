#include <string>
#include <vector>
#include <stack>
using namespace std;

bool Check(const string& s)
{
    stack<char>st;
    for (auto e : s)
    {
        if (st.empty())
        {
            if (e == ')' || e == '}' || e == ']')
            {
                return false;
            }
            st.push(e);
        }
        else
        {
            if (e == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else if(e ==']')
            {
                if (st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else if (e == '}')
            {
                if (st.top() == '{')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(e);
            }
        }
    }

    return st.empty() ? true : false;
}

int solution(string s) {
    int answer{};
    int n = s.size();
    s += s;
    for (int i = 0; i < n; i++)
    {
        string tempS = s.substr(i, n);
        if (Check(tempS))
        {
            answer++;
        }
    }
    return answer;
}
int main()
{
    solution("[](){}");
}