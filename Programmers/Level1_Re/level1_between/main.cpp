#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int m = max(a, b);
    int n = min(a, b);
    for (n; n <=m; n++)
    {
        answer += n;
    }
    return answer;
}