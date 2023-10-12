#include <bits/stdc++.h>

using namespace std;

int N, M;
const int dy[4] = { 0,-1,0,1 };
const int dx[4] = { -1,0,1,0 };
int roomSize[2504];
int roomCnt;
int maxCnt;
int bMaxCnt;
int a[54][54];
int visited[54][54];

int dfs(int y, int x, int cnt)
{
	if (visited[y][x])
	{
		return 0;
	}
	visited[y][x] = cnt;
	int result{ 1 };
	for (int i = 0; i < 4; i++)
	{
		if (!(a[y][x] & (1 << i)))
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			result += dfs(ny, nx, cnt);
		}
	}
	return result;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				roomCnt++;
				roomSize[roomCnt] = dfs(i, j, roomCnt);
				maxCnt = max(maxCnt, roomSize[roomCnt]);
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i + 1 < M)
			{
				int a = visited[i + 1][j];
				int b = visited[i][j];
				if (a != b)
				{
					bMaxCnt = max(bMaxCnt, roomSize[a] + roomSize[b]);
				}
			}
			if (j + 1 < N)
			{
				int a = visited[i][j + 1];
				int b = visited[i][j];
				if (a != b)
				{
					bMaxCnt = max(bMaxCnt, roomSize[a] + roomSize[b]);
				}
			}
		}
	}
	cout << roomCnt << '\n';
	cout << maxCnt << '\n';
	cout << bMaxCnt << '\n';
}