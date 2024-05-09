#include <bits/stdc++.h>

using namespace std;

int N, M, C;
int a[24];
int pack[24];
int dp[24][1 << 14][24];

int Func(int here, int y, int c)
{
	if (here == M)
	{
		return 0;
	}

	if (dp[here][y][c])
	{
		return dp[here][y][c];
	}
	//보석을 담지 않고 가는것
	dp[here][y][c] = max(dp[here][y][c], Func(here + 1, y, C));
	for (int i = 0; i < N; i++)
	{
		//보석을 담는것
		bool haveJAM = (1 << i) & y; // 이미 담겼는가
		bool canIn = (c - a[i]) >= 0; // 담았을때 용량을 넘는가
		if (!haveJAM && canIn)
		{
			dp[here][y][c] = max(dp[here][y][c], Func(here, y | (1 << i), c - a[i]) + 1);
		}
	}
	return dp[here][y][c];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> M >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	cout << Func(0, 0, C);
}