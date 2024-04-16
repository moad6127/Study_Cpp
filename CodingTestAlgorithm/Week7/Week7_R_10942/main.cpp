#include <bits/stdc++.h>

using namespace std;

int N, M, x, y;
int a[2004];
int dp[2004][2004];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++)
	{
		dp[i][i] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (a[i] == a[i + 1])
		{
			dp[i][i + 1] = 1;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			if (a[j] == a[j + i] && dp[j + 1][j + i - 1])
			{
				dp[j][j + i] = 1;

			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		cout << dp[x][y]<<'\n';
	}
}