#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int a[104][104];
int visited[104][104];
int x_1, y_1, x_2, y_2;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
vector<int> result;
int dfs(int y, int x)
{
	visited[y][x] = 1;
	int temp{ 1 };
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n)
		{
			continue;
		}
		if (a[ny][nx] == 1)
		{
			continue;
		}
		if (visited[ny][nx])
		{
			continue;
		}
		temp += dfs(ny, nx);
	}
	return temp;
}
int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int y = y_1; y < y_2; y++)
		{
			for (int x = x_1; x < x_2; x++)
			{
				a[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				if (a[i][j] == 0)
				{
					result.push_back(dfs(i, j));
				}
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size()<<'\n';
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}

}