#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int xNum{}, yNum{};
    while (true)
    {
        if (xNum >= X.size() || yNum >= Y.size())
        {
            break;
        }
        if (X[xNum] == Y[yNum])
        {
            answer.push_back(X[xNum]);
            xNum++;
            yNum++;
        }
        else if (X[xNum] > Y[yNum])
        {
            yNum++;
        }
        else
        {
            xNum++;
        }
    }
    if (answer.empty())
    {
        answer = "-1";
    }
    else
    {
        sort(answer.begin(), answer.end(), greater<char>());
        if (answer.front() == '0' && answer.back() == '0')
        {
            answer = "0";
        }
    }
    return answer;
}
int main()
{
    string X{ "100" };
    string Y{ "2345" };
    solution(X, Y);
}