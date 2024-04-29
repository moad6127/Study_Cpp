#include <string>
#include <vector>

using namespace std;

int GetCount(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int count{ 2 };
    for (int i = 2; i <= n / 2; i++)
    {
        if (!(n % i))
        {
            count++;
        }
    }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; i++)
    {
        int count = GetCount(i);
        if (count > limit)
        {
            answer += power;
            continue;
        }
        answer += count;
    }
    return answer;
}