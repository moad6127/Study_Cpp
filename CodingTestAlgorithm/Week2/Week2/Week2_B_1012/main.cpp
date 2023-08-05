#include <bits/stdc++.h>


using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0 , 1 , 0 , -1 };
int TC;
int M, N, K;


void dfs(int y, int x, vector<vector<bool>>& a, vector<vector<bool>>& visited)
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
		if (!visited[ny][nx] && a[ny][nx])
		{
			dfs(ny,nx,a,visited);
		}
	}
}

int main()
{
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		int result{};
		cin >> M >> N >> K;
		
		vector<vector<bool>> a(N, vector<bool>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, 0));
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
				if (!visited[j][k] && a[j][k])
				{
					dfs(j, k,a,visited);
					result++;
				}
			}

		}
		cout << result << '\n';
	}
}