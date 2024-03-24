#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long temp = num;
    while (temp != 1)
    {
        if (answer >= 500)
        {
            break;
        }
        if (temp % 2)
        {
            temp = (temp * 3) + 1;
        }
        else
        {
            temp /= 2;
        }
        answer++;
    }

    return answer >= 500 ? -1 : answer;
}
int main()
{
    solution(626331);
}