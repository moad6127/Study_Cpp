#include <bits/stdc++.h>

using namespace std;

int t, m, n, k, x, y;
int a[52][52];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0,-1,0,1 };
int visited[52][52];
void Func(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
		{
			continue;
		}
		if (a[ny][nx] == 0)
		{
			continue;
		}
		if (visited[ny][nx] != 0)
		{
			continue;
		}
		Func(ny, nx);
	}
}
int main()
{
	cin >> t;
	for (int T = 0; T < t; T++)
	{
		int result{};
		cin >> m >> n >> k;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1)
				{
					if (visited[i][j] == 0)
					{
						result += 1;
						Func(i, j);
					}
				}
			}
		}
		cout << result << '\n';
	}
}