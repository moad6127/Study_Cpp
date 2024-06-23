#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;


    for (int start = 1; start <= n; start++)
    {
        int temp{start};
        for (int i = start + 1; i <= n; i++)
        {
            temp += i;
            if (temp == n)
            {
                temp = 0;
                answer++;
                break;
            }
            if (temp > n)
            {
                break;
            }
        }
    }
    return answer + 1;
}
int main()
{
    solution(15);
}