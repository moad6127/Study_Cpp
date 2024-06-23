#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        int f = dp[i - 1] + dp[i - 2];
        f = f % 1234567;
        dp.push_back(f);
    }
    return dp[n];
}