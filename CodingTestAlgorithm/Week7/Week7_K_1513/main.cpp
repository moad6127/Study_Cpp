#include <bits/stdc++.h>

using namespace std;

int N, M, C;
int m[51][51];
int a, b;
int l[51][51][51][51];
int Func(int y, int x, int postC, int cCnt)
{
	if (y > N || x > M)
	{
		return 0;
	}
	if (y == N && x == M)
	{
		if (cCnt == 0 && m[y][x] == 0)
		{
			return 1;
		}
		if (cCnt == 1 && m[y][x] > postC)
		{
			return 1;
		}
		return 0;
	}
	if (l[y][x][cCnt][postC] != -1)
	{
		return l[y][x][cCnt][postC];
	}
	l[y][x][cCnt][postC] = 0;
	if (m[y][x] == 0)
	{
		l[y][x][cCnt][postC] = (Func(y + 1, x, postC, cCnt) + Func(y, x + 1, postC, cCnt)) % 1000007;
	}
	else if (m[y][x] > postC)
	{
		l[y][x][cCnt][postC] = (Func(y + 1, x, m[y][x], cCnt - 1) + Func(y, x + 1, m[y][x], cCnt - 1)) % 1000007;
	}
	return l[y][x][cCnt][postC];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> C;
	memset(l, -1, sizeof(l));
	for (int i = 0; i < C; i++)
	{
		cin >> a >> b;
		m[a][b] = i + 1;
	}
	for (int i = 0; i <= C; i++)
	{
		cout << Func(1, 1, 0, i) << '\n';
	}
}