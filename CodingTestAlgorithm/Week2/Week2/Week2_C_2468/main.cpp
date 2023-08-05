#include <bits/stdc++.h>

using namespace std;

int N;
int a[101][101];
int minNum{ 101 }, maxNum{ 0 };
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0 , 1 , 0 , -1 };

void dfs(int y, int x, int checknum, vector<vector<bool>>& visited)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
		{
			continue;
		}
		if (a[ny][nx] > checknum && !visited[ny][nx])
		{
			dfs(ny, nx, checknum, visited);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			minNum = min(minNum, a[i][j]);
			maxNum = max(maxNum, a[i][j]);
		}
	}

	int maxResult{ 1 };
	for (int i = minNum; i < maxNum; i++)
	{
		int result{};
		vector<vector<bool>> visited(N, vector<bool>(N, 0));
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (!visited[j][k] && a[j][k] > i)
				{
					result++;
					dfs(j, k, i, visited);
				}
			}
		}
		maxResult = max(maxResult, result);
	}
	cout << maxResult;
}