#include <bits/stdc++.h>

using namespace std;

int N, M ,temp;
int nums[41];
int dp[41];
int Func(int here)
{
	if (here >= N - 1)
	{
		return 1;
	}
	if (nums[here])
	{
		return Func(here + 1);
	}
	if (dp[here] != -1)
	{
		return dp[here];
	}
	dp[here] = 0;
	if (!nums[here + 1])
	{
		dp[here] += (Func(here + 2) + Func(here + 1));
	}
	else
	{
		dp[here] += Func(here + 1);
	}
	return dp[here];
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		nums[temp - 1] = 1;
	}
	memset(dp, -1, sizeof(dp));
	cout<<Func(0);
}