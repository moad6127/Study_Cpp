#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    bool flag{ true };
    for (auto& e : s)
    {
        if (e == ' ')
        {
            flag = true;
            answer += e;
            continue;
        }
        if (flag)
        {
            e = toupper(e);
            flag = false;
        }
        else
        {
            e = tolower(e);
        }
        answer += e;
    }

    return answer;
}