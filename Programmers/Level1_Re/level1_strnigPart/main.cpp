#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i <= t.size() - p.size(); i++)
    {
        string temp = t.substr(i, p.size());
        if (temp <= p)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    solution("10203", "15");
}