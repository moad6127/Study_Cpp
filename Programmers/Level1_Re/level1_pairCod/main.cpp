#include <string>
#include <vector>

using namespace std;
vector<int> SKIPCODE(26, 0);

string solution(string s, string skip, int index) {
    for (auto e : skip)
    {
        SKIPCODE[e - 'a'] = 1;
    }
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < index; j++)
        {
            if (s[i] == 'z')
            {
                s[i] = 'a';
            }
            else
            {
                s[i] += 1;
            }
            while (true)
            {
                if (!SKIPCODE[s[i] - 'a'])
                {
                    break;
                }
                if (s[i] == 'z')
                {
                    s[i] = 'a';
                }
                else
                {
                    s[i] += 1;
                }
            }
        }
    }
    return s;
}
int main()
{
    solution("zzz", "abcdefg", 1);
}