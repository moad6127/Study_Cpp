#include<bits/stdc++.h>


using namespace std;
int N, M;
char a[104][104];
int visited[104][104];
const int dy[4] = { -1, 1, 0 , 0 };
const int dx[4] = { 0, 0, -1 ,1 };
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			a[i][j] = temp[j];
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

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
			if (visited[ny][nx])
			{
				continue;
			}
			if (a[ny][nx] == '0')
			{
				continue;
			}

			visited[ny][nx] = visited[now.first][now.second] + 1;
			q.push({ ny,nx });
		}
	}
	cout << visited[N - 1][M - 1];
}