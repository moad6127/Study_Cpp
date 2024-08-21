#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkS(string s)
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
int splitInd(string s)
{
    int cnt{};
    int idx{ 1 };
    if (s[0] == '(')
    {
        cnt++;
    }
    else
    {
        cnt--;
    }
    while (true)
    {
        if (cnt == 0)
        {
            break;
        }
        if (s[idx] == '(')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        idx++;
    }
    return idx;
}

string Revers(string s)
{
    string result;
    for (auto e : s)
    {
        if (e == ')')
        {
            result.push_back('(');
        }
        else
        {
            result.push_back(')');
        }
    }
    return result;
}

string MFunc(string s)
{
    if (s.empty())
    {
        return string();
    }
    if (checkS(s))
    {
        return s;
    }
    int idx = splitInd(s);
    string u = s.substr(0, idx);
    string v;
    if (s.size() > idx)
    {
        v = s.substr(idx);
    }
    if (checkS(u))
    {
        u += MFunc(v);
    }
    else
    {
        string temp{ "(" };
        temp += MFunc(v);
        temp.push_back(')');
        u = u.substr(1);
        u.pop_back();
        temp += Revers(u);
        u = temp;
    }
    return u;
}

string solution(string p) {
    string answer = MFunc(p);
    return answer;
}

int main()
{
    solution("()))((()");
}