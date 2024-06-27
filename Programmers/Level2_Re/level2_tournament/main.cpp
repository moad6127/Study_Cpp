#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int A = min(a, b);
    int B = max(a, b);
    while (true)
    {
        answer += 1;
        if (B - A == 1)
        {
            if (A & 1)
            {
                break;
            }
        }
        if (A & 1)
        {
            A += 1;
        }
        if (B & 1)
        {

            B += 1;
        }
        A /= 2;
        B /= 2;
    }
    return answer;
}
int main()
{
    solution(8, 4, 7);
}