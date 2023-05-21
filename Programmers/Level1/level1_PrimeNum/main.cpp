#include <string>
#include <vector>

using namespace std;

//소수 = 1과 자기자신으로만 나눌수 있는 수
bool Prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (!(n % i))
        {
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= n; i++)
    {
        if (Prime(i))
        {
            answer++;
        }
    }
    return answer;
}