#include <bits/stdc++.h>

using namespace std;

int n;
int a[104][104];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int MIN = 104, MAX = -1;
int visited[104][104];
int result = 1;

void dfs(int y, int x, int h)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
		{
			continue;
		}
		if (a[ny][nx] <= h)
		{
			continue;
		}
		if (visited[ny][nx] != 0)
		{
			continue;
		}
		dfs(ny, nx,h);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			MIN = min(MIN, a[i][j]);
			MAX = max(MAX, a[i][j]);
		}
	}
	for (int h = MIN; h <= MAX; h++)
	{
		memset(visited, 0, sizeof(visited));
		int temp{};
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] != 0)
				{
					continue;
				}
				if (a[i][j] > h)
				{
					dfs(i, j, h);
					temp++;
				}
			}
		}
		result = max(result, temp);
	}
	cout << result;
}