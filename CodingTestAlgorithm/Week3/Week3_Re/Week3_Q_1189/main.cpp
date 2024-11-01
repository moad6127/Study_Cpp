#include <bits/stdc++.h>

using namespace std;

int r, c, k;
string s;
char a[10][10];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int visited[10][10];
int startX, startY, endX, endY, result;

void Func(int y, int x, int num)
{
	if (y == endY && x == endX && num ==k)
	{
		result++;
		return;
	}
	if (num > k)
	{
		return;
	}
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
		{
			continue;
		}
		if (a[ny][nx] == 'T')
		{
			continue;
		}
		if (visited[ny][nx])
		{
			continue;
		}
		visited[ny][nx] = 1;
		Func(ny, nx, num + 1);
		visited[ny][nx] = 0;
	}
}
int main()
{
	cin >> r >> c >> k;
	startX = 0;
	startY = r - 1;
	endX = c - 1;
	endY = 0;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];
		}
	}
	Func(startY, startX, 1);
	cout << result;
}