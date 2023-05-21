#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;

    if (static_cast<long long>(sqrt(n)) == sqrt(n))
    {
        long long temp{};
        temp = static_cast<long long>(sqrt(n));
        temp += 1;
        answer = temp * temp;
    }
    else
    {
        answer = -1;
    }
    return answer;
}