#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x{};
    int cntX{};
    int cntN{};
    for (int i = 0; i < s.size(); i++)
    {
        if (!x)
        {
            x = s[i];
            cntX++;
        }
        else
        {
            if (s[i] == x)
            {
                cntX++;
            }
            else
            {
                cntN++;
            }
            if (cntX == cntN)
            {
                answer++;
                x = 0;
                cntX = 0;
                cntN = 0;
            }
        }
    }
    if (cntX != cntN)
    {
        answer++;
    }
    return answer;
}