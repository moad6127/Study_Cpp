#include <string>
#include <vector>

using namespace std;

int table[60004];
const int MOD{ 1000000007 };
int solution(int n) {
    int answer = 0;
    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        table[i] = table[i - 1] % MOD + table[i - 2] % MOD;
    }
    return table[n]%MOD;
}