#include <iostream>
#include <vector>
using namespace std;

int dp[100004][4];

int Func(vector<vector<int>>& land, int here, int prev)
{
    if (here >= land.size())
    {
        return 0;
    }
    if (dp[here][prev])
    {
        return dp[here][prev];
    }
    for (int i = 0; i < 4; i++)
    {
        if (i == prev)
        {
            continue;
        }
        dp[here][prev] = max(dp[here][prev], Func(land, here + 1, i) + land[here][i]);
    }
    return dp[here][prev];
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    answer = Func(land, 0, -1);
    return answer;
}
int main()
{
    solution({ {1, 2, 3, 5},{5, 6, 7, 8},{4, 3, 2, 1} });
}