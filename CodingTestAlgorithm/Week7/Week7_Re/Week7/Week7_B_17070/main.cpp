#include <bits/stdc++.h>

using namespace std;

int n, a[24][24], dp[24][24][3];

bool Check(int y, int x, int dir)
{
	if (dir == 0 || dir == 2)
	{
		if (!a[y][x])
		{
			return true;
		}
	}
	else if (dir == 1)
	{
		if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n;j++)
		{
			if (Check(i, j + 1, 0))		dp[i][j + 1][0] += dp[i][j][0];
			if (Check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];
			
			if (Check(i + 1, j, 2))		dp[i + 1][j][2] += dp[i][j][2];
			if (Check(i + 1, j + 1, 1))	dp[i + 1][j + 1][1] += dp[i][j][2];
			
			if (Check(i, j + 1, 0))		dp[i][j + 1][0] += dp[i][j][1];
			if (Check(i + 1, j, 2))		dp[i + 1][j][2] += dp[i][j][1];
			if (Check(i + 1, j + 1, 1))	dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	int result{};
	for (int i = 0; i < 3;i++)
	{
		result += dp[n][n][i];
	}
	cout << result;
}