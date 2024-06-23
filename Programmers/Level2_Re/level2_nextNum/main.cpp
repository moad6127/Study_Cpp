#include <string>
#include <vector>

using namespace std;

int bitT(int x)
{
    int cnt{};
    while (x)
    {
        if (x & 1)
        {
            cnt++;
        }
        x /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = n + 1;
    int num = bitT(n);
    while (true)
    {
        if (num == bitT(answer))
        {
            break;
        }
        answer++;
    }
    return answer;
}