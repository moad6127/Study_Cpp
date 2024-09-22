#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[103];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int visited[104][104];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	queue<pair<int, int>>q;
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
			if (s[ny][nx] == '0')
			{
				continue;
			}
			if (visited[ny][nx] != 0)
			{
				continue;
			}
			visited[ny][nx] = visited[now.first][now.second] + 1;
			q.push({ ny,nx });
		}
	}
	cout << visited[n - 1][m - 1];
}