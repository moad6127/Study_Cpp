#include <string>
#include <vector>

using namespace std;

int CheckNumOne(int num)
{
    int result{num & 1};
    while (num != 0)
    {
        num = (num >> 1);
        if ((num & 1) == 1)
        {
            result++;
        }
    }
    return result;
}

int solution(int n) {
    int answer = 0;

    int checkNum = CheckNumOne(n++);
    while (true)
    {
        if (checkNum == CheckNumOne(n))
        {
            answer = n;
            break;
        }
        n++;
    }
    return answer;
}