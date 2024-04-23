#include <bits/stdc++.h>

using namespace std;

long long N;
long long a[104];
long long dp[104][21];

long long Func(long long h, long long num)
{
	if (num < 0 || num > 20)
	{
		return 0;
	}
	if (h == N - 2)
	{
		if (a[N - 1] == num)
		{
			return 1;
		}
		return 0;
	}
	if (dp[h][num] != -1)
	{
		return dp[h][num];
	}

	dp[h][num] = Func(h + 1, num + a[h + 1]) + Func(h + 1, num - a[h + 1]);
	return dp[h][num];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<Func(0,a[0]);
}