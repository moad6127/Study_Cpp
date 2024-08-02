#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey)
    {
        int end = storey % 10;
        if (end > 5)
        {
            answer += 10 - end;
            storey /= 10;
            storey++;
        }
        else if (end < 5)
        {
            answer += end;
            storey /= 10;
        }
        else
        {
            answer += 5;
            if (((storey / 10) % 10) + 1 > 5)
            {
                storey /= 10;
                storey++;
            }
            else
            {
                storey /= 10;
            }

        }
    }

    return answer;
}

int main()
{
    solution(555);
}