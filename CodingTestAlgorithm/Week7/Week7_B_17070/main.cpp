#include <bits/stdc++.h>

using namespace std;

int N;
int a[20][20], check[3][20][20];

int Func(int dir, int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N ||a[y][x] == 1)
	{
		return 0;
	}
	if (dir == 2)
	{
		if (a[y - 1][x] == 1 || a[y][x - 1] == 1)
		{
			return 0;
		}
	}
	if (y == N - 1 && x == N - 1)
	{
		return 1;
	}
	if (check[dir][y][x])
	{
		return check[dir][y][x];
	}
	if (dir == 0)
	{
		check[dir][y][x] = Func(0, y, x + 1) + Func(2, y + 1, x + 1);
	}
	else if (dir == 1)
	{
		check[dir][y][x] = Func(1, y + 1, x) + Func(2, y + 1, x + 1);
	}
	else
	{
		check[dir][y][x] = Func(0, y, x + 1) + Func(1, y + 1, x) + Func(2, y + 1, x + 1);
	}
	return check[dir][y][x];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << Func(0, 0, 1);

	return 0;
}