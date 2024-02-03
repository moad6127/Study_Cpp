#include <string>
#include <vector>

using namespace std;

bool check(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' || s[i] == '5')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

vector<int> solution(int l, int r) {
    vector<int> answer;

    for (int i = l; i <= r; i++)
    {
        string temp = to_string(i);
        if (check(temp))
        {
            answer.push_back(i);
        }
    }
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}