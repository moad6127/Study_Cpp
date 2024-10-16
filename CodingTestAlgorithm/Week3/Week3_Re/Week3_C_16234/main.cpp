#include <bits/stdc++.h>

using namespace std;
int n, l, r, result;
int a[51][51];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int visited[51][51];


bool Func(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	int sum{a[y][x]};
	vector<pair<int, int>> lan;
	lan.push_back({ y,x });
	while (q.size())
	{
		pair<int,int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)
			{
				continue;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			int nums = abs(a[ny][nx] - a[now.first][now.second]);
			if (nums >= l && nums <= r)
			{
				q.push({ ny,nx });
				lan.push_back({ ny,nx });
				sum += a[ny][nx];
				visited[ny][nx] = 1;
			}
		}
	}
	int pe = sum / lan.size();
	for (auto e : lan)
	{
		a[e.first][e.second] = pe;
	}
	if (lan.size() > 1)
	{
		return true;
	}
	return false;
}
int main()
{
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	while (true)
	{
		int cnt{};
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] == 0)
				{
					if (Func(i, j))
					{
						cnt++;
					}
				}
			}
		}
		if (!cnt)
		{
			break;
		}
		result++;
	}
	cout << result;
}