#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";

    for (auto& e : new_id)
    {
        e = tolower(e);
    }
    for (auto e : new_id)
    {
        if (e == '-' || e == '_')
        {
            answer += e;
        }
        else if (e >= '0' && e <= '9')
        {
            answer += e;
        }
        else if (e >= 'a' && e <= 'z')
        {
            answer += e;
        }
        else if (e == '.')
        {
            if (!answer.empty() &&answer.back() != '.')
            {
                answer += e;
            }
        }
    }
    if (answer.back() == '.')
    {
        answer.pop_back();
    }

    if (answer.empty())
    {
        answer += 'a';
    }

    answer = answer.substr(0, 15);
    if (answer.back() == '.')
    {
        answer.pop_back();
    }
    while (true)
    {
        if (answer.length() > 2)
        {
            break;
        }
        answer += answer.back();
    }
    return answer;
}
int main()
{
    solution("");

}