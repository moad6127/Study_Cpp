#include <bits/stdc++.h>

using namespace std;
int T, M, N, K;
int visited[104][104];
int a[104][104];
const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0 , 0, -1, 1 };
void Func(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
		{
			continue;
		}
		if (visited[ny][nx])
		{
			continue;
		}
		if (a[ny][nx] == 1)
		{
			Func(ny, nx);
		}

	}
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		int result{};
		for (int j = 0; j < K; j++)
		{
			int x{}, y{};
			cin >> x >> y;
			a[y][x] = 1;
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (a[j][k] == 1 && !visited[j][k])
				{
					Func(j, k);
					result++;
				}
			}
		}
		cout << result << '\n';
	}
}