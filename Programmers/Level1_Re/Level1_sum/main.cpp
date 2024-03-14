#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    string temp = to_string(n);
    for (auto e : temp)
    {
        answer += e - '0';
    }

    return answer;
}