#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> a;
const int dy[4] = { -1, 1, 0 , 0 };
const int dx[4] = { 0 ,0, -1, 1 };

int result;

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	vector<vector<int>> visited(N,vector<int>(M,0));
	q.push({ y,x });
	visited[y][x] = 1;
	while (q.size())
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
			if (visited[ny][nx] == 0 && a[ny][nx] == 'L')
			{
				visited[ny][nx] = visited[now.first][now.second] + 1;
				result = max(result, visited[ny][nx]);
				q.push({ ny,nx });
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		a.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 'L')
			{
				BFS(i,j);
			}
		}
	}
	cout << result - 1;

}