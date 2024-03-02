#include <bits/stdc++.h>

using namespace std;
int N, M;
char a[51][51], visitd[51][51];
int dp[51][51];
const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

int Func(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M || a[y][x] == 'H')
	{
		return 0;
	}
	if (visitd[y][x])
	{
		cout << -1 << '\n';
		exit(0);
	}
	if (dp[y][x])
	{
		return dp[y][x];
	}

	visitd[y][x] = 1;
	int val = a[y][x] - '0';
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * val;
		int nx = x + dx[i] * val;
		dp[y][x] = max(dp[y][x], Func(ny, nx) + 1);
	}
	visitd[y][x] = 0;
	return dp[y][x];
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			a[i][j] = temp[j];
		}
	}
	cout << Func(0, 0);

}