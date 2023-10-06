#include <bits/stdc++.h>

using namespace std;
int R, C;
char a[22][22];
int result;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
void Func(int y, int x, int num, int cnt)
{
	result = max(result, cnt);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
		{
			continue;
		}
		int nextNum = (1 << (int)(a[ny][nx] - 'A'));
		if ((num & nextNum) == 0)
		{
			Func(ny, nx, num | nextNum, cnt + 1);
		}
	}
}


int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> a[i][j];
		}
	}

	Func(0, 0, 1 << (int)(a[0][0] - 'A'), 1);
	cout << result << '\n';
}