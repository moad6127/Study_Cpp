#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.begin(), X.end(), greater<>());
    sort(Y.begin(), Y.end(), greater<>());

    int nowX{};
    int nowY{};
    while (true)
    {
        if (nowX >= X.size() || nowY >= Y.size())
        {
            break;
        }
        if (X[nowX] == Y[nowY])
        {
            answer += X[nowX];
            nowX++;
            nowY++;
        }
        else
        {
            if (X[nowX] > Y[nowY])
            {
                nowX++;
            }
            else
            {
                nowY++;
            }
        }
    }
    if (answer.empty())
    {
        answer = "-1";
    }
    else
    {
        if (answer[0] == '0')
        {
            answer = "0";
        }
    }
    return answer;
}
int main()
{
    solution("5525", "1255");
}

