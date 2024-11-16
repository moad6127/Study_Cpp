#include <bits/stdc++.h>

using namespace std;
int r, c, result;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
char a[21][21];
void Func(int y, int x, int num, int cnt)
{
	result = max(result, cnt);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
		{
			continue;
		}
		int next = (1 << (int)(a[ny][nx] - 'A'));
		if ((num & next) == 0)
		{
			Func(ny, nx, num | next, cnt + 1);
		}
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}
	Func(0, 0, 1 << (int)(a[0][0] - 'A'), 1);
	cout << result;
}