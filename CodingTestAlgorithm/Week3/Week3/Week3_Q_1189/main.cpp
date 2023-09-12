#include <bits/stdc++.h>


using namespace std;

int R, C, K;
char a[15][15];
int visited[15][15];
int startY;
int startX;
int endY;
int endX;
const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

int Func(int y, int x, int count)
{

	if (y == endY && x == endX)
	{
		if (visited[y][x] == K)
		{
			return 1;
		}
		return 0;
	}
	int result{};
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
		{
			continue;
		}
		if (visited[ny][nx])
		{
			continue;
		}
		if (a[ny][nx] == 'T')
		{
			continue;
		}
		visited[ny][nx] = visited[y][x] + 1;
		result += Func(ny, nx, count + 1);
		visited[ny][nx] = 0;
	}
	return result;
}

int main()
{
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < C; j++)
		{
			a[i][j] = temp[j];
		}
	}

	startY = R - 1;
	startX = 0;
	endY = 0;
	endX = C - 1;
	visited[startY][startX] = 1;
	cout<<Func(startY, startX, 1);
}