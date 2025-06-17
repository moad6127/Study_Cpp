#include <bits/stdc++.h>

using namespace std;

int n;
int a[20][20], dp[20][1<<16];

int Func(int here, int visited)
{
	if (visited == (1 << n) - 1)
	{
		return a[here][0] ? a[here][0] : 987654321;
	}

	if (dp[here][visited] != -1)
	{
		return dp[here][visited];
	}
	dp[here][visited] = 987654321;
	for (int i = 0; i < n;i++)
	{
		if (visited & (1 << i))
		{
			continue;
		}
		if (a[here][i] == 0)
		{
			continue;
		}
		dp[here][visited] = min(dp[here][visited], Func(i, visited | (1 << i)) + a[here][i]);
	}

	return dp[here][visited];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << Func(0, 1);
}