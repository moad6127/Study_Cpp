#include <bits/stdc++.h>

using namespace std;
int n, m;
string a[51];
vector<pair<int, int>> l;
int result{};
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void bfs(int startY, int startX)
{
	int maxNum{};
	queue<pair<int, int>> q;
	int visited[51][51];
	memset(visited, -1, sizeof(visited));
	q.push({ startY,startX });
	visited[startY][startX] = 0;
	while (q.size())
	{
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			{
				continue;
			}
			if (visited[ny][nx] != -1)
			{
				continue;
			}
			if (a[ny][nx] == 'W')
			{
				continue;
			}
			visited[ny][nx] = visited[now.first][now.second] + 1;
			maxNum = max(maxNum, visited[ny][nx]);
			q.push({ ny,nx });
		}
	}

	result = max(result, maxNum);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 'L')
			{
				l.push_back({ i,j });
			}
		}
	}
	for (auto e : l)
	{
		bfs(e.first, e.second);
	}
	cout << result;
}