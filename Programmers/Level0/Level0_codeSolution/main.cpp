#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";

    bool mode{ false };
    for (int i = 0; i < code.size(); i++)
    {
        if (code[i] == '1')
        {
            mode = !mode;
            continue;
        }
        if (mode)
        {
            if (i % 2)
            {
                answer += code[i];
            }
        }
        else
        {
            if ((i % 2) == 0)
            {
                answer += code[i];
            }
        }
    }
    if (answer.empty())
    {
        answer = "EMPTY";
    }
    return answer;
}