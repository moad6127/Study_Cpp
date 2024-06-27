#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> table(n + 1);
    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        table[i] = table[i - 1] % 1234567 + table[i - 2] % 1234567;
    }
    return table[n]% 1234567;
}