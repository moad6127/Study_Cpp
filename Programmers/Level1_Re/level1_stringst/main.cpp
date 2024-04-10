#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt{};
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            cnt = 0;
            continue;
        }
        if (cnt % 2)
        {
            s[i] = tolower(s[i]);
        }
        else
        {
            s[i] = toupper(s[i]);
        }
        cnt++;
    }
    return s;
}