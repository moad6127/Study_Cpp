//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N;
//int a[20][20], check[3][20][20];
//
//int Func(int dir, int y, int x)
//{
//	if (y < 0 || y >= N || x < 0 || x >= N ||a[y][x] == 1)
//	{
//		return 0;
//	}
//	if (dir == 2)
//	{
//		if (a[y - 1][x] == 1 || a[y][x - 1] == 1)
//		{
//			return 0;
//		}
//	}
//	if (y == N - 1 && x == N - 1)
//	{
//		return 1;
//	}
//	if (check[dir][y][x])
//	{
//		return check[dir][y][x];
//	}
//	if (dir == 0)
//	{
//		check[dir][y][x] = Func(0, y, x + 1) + Func(2, y + 1, x + 1);
//	}
//	else if (dir == 1)
//	{
//		check[dir][y][x] = Func(1, y + 1, x) + Func(2, y + 1, x + 1);
//	}
//	else
//	{
//		check[dir][y][x] = Func(0, y, x + 1) + Func(1, y + 1, x) + Func(2, y + 1, x + 1);
//	}
//	return check[dir][y][x];
//}
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	cout << Func(0, 0, 1);
//
//	return 0;
//}

#include <bits/stdc++.h>

using namespace std;

int n, a[24][24], dp[24][24][3];

bool check(int y, int x, int dir)
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
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check(i, j + 1, 0))
			{
				dp[i][j + 1][0] += dp[i][j][0];
			}
			if (check(i + 1, j + 1, 1))
			{
				dp[i + 1][j + 1][1] += dp[i][j][0];
			}

			if (check(i + 1, j, 2))
			{
				dp[i + 1][j][2] += dp[i][j][2];
			}
			if (check(i + 1, j + 1, 1))
			{
				dp[i + 1][j + 1][1] += dp[i][j][2];
			}

			if (check(i, j + 1, 0))
			{
				dp[i][j + 1][0] += dp[i][j][1];
			}
			if (check(i + 1, j, 2))
			{
				dp[i + 1][j][2] += dp[i][j][1];
			}
			if (check(i + 1, j + 1, 1))
			{
				dp[i + 1][j + 1][1] += dp[i][j][1];
			}
		}
	}
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}