#include <bits/stdc++.h>

using namespace std;


int N, M,result;
const int dy[4] = {-1, 1, 0 ,0};
const int dx[4] = { 0,0, -1, 1 };
void BSF(vector<vector<int>> map)
{
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2)
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			{
				continue;
			}
			if (map[ny][nx] == 0)
			{
				map[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}

	int count{};
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				count++;
			}
		}
	}
	result = max(result, count);
}
void MakeBlock(vector<vector<int>> map, int blockCount)
{
	if (blockCount == 0)
	{
		BSF(map);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				MakeBlock(map, blockCount - 1);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	vector<vector<int>>a(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}
	MakeBlock(a, 3);
	cout << result;
}