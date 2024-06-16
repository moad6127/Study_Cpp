#include <bits/stdc++.h>

using namespace std;

int N, a[104],b[104], dp[104][10][10][10][2];
string tempA, tempB;
int Mod(int x)
{
	return (x < 0) ? x + 10 : x % 10;
}

int Func(int here, int x, int y, int z, int flag)
{
	if (here == N)
	{
		return 0;
	}
	if (dp[here][x][y][z][flag] != -1)
	{
		return dp[here][x][y][z][flag];
	}
	if (Mod(x + a[here]) == Mod(b[here]))
	{
		dp[here][x][y][z][flag] = min(Func(here + 1, y, z, 0, 0), Func(here + 1, y, z, 0, 1));
		return dp[here][x][y][z][flag];
	}
	dp[here][x][y][z][flag] = 987654321;
	int _flag = flag ? 1 : -1;
	for (int i = 1; i <= 3; i++)
	{
		dp[here][x][y][z][flag] = min(dp[here][x][y][z][flag],1 + Func(here, Mod(x + i * _flag), y, z, flag));
		dp[here][x][y][z][flag] = min(dp[here][x][y][z][flag],1 + Func(here, Mod(x + i * _flag), Mod(y + i * _flag), z, flag));
		dp[here][x][y][z][flag] = min(dp[here][x][y][z][flag],1 + Func(here, Mod(x + i * _flag), Mod(y + i * _flag), Mod(z + i * _flag), flag));
	}
	return dp[here][x][y][z][flag];

}
int main()
{
	cin >> N>>tempA>>tempB;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++)
	{
		a[i] = tempA[i] - '0';
	}
	for (int i = 0; i < N; i++)
	{
		b[i] = tempB[i] - '0';
	}

	cout << min(Func(0, 0, 0, 0, 0), Func(0, 0, 0, 0, 1));
}