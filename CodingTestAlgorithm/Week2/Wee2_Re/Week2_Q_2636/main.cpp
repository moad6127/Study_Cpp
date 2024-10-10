#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[104][104];
int sum, prev;
int t;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
set<pair<int, int>> s;
int visited[104][104];
void bfs()
{
	queue<pair<int, int>>q;
	memset(visited, 0, sizeof(visited));
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
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			{
				continue;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			if (a[ny][nx])
			{
				s.insert({ ny,nx });
				continue;
			}
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			sum += a[i][j];
		}
	}
	while (true)
	{
		s.clear();
		bfs();
		t++;
		if (sum == s.size())
		{
			break;
		}
		for (auto e : s)
		{
			a[e.first][e.second] = 0;
			sum--;
		}
	}
	cout << t<< '\n';
	cout << sum << '\n';
}