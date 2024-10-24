#include <bits/stdc++.h>

using namespace std;

int n, m, jx, jy, sx, sy;
int result;
char a[301][301];
int visited[301][301];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
string s;

int main()
{
	cin >> n >> m >> jy >> jx >> sy >> sx;
	jx--;
	jy--;
	sx--;
	sy--;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
		}
	}
	queue<pair<int, int>> q;
	q.push({ jy,jx });
	visited[jy][jx] = 1;
	while (true)
	{
		result++;
		if (a[sy][sx] == '0')
		{
			break;
		}
		queue<pair<int, int>> temp;
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
				visited[ny][nx] = result;
				if (a[ny][nx] != '0')
				{
					a[ny][nx] = '0';
					temp.push({ ny,nx });
				}
				else
				{
					q.push({ ny,nx });
				}
			}
		}
		q = temp;
	}
	cout << visited[sy][sx];
}