#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while (n >= a)
    {
        int temp = b * (n / a);
        n %= a;
        n += temp;
        answer += temp;
    }
    return answer;
}
int main()
{
    solution(3, 1, 20);
}