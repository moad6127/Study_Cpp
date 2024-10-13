#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    // y^2 + x^2 = d^2;

    for (long long i = 0; i <= d; i += k)
    {
        long long y = sqrt(((long long)d  * d) - (i * i));
        answer += (long long)floor(y / k) + 1;
    }
    return answer;
}