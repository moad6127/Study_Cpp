#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int a[10][10];
int n, m, result = INT_MAX;
vector<pair<int, int>> v;

vector<pair<int, int>> FuncVector(int here, int dir)
{
	vector<pair<int, int>> ReturnV;
	int y = v[here].first;
	int x = v[here].second;
	if (a[y][x] == 1)
	{
		while (true)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
			{
				if (a[ny][nx] == 0)
				{
					a[ny][nx] = 8;
					ReturnV.push_back({ ny,nx });
				}
				y = ny;
				x = nx;
			}
			else
			{
				break;
			}
		}
	}
	else if (a[y][x] == 2)
	{
		for (int i = 0;i <= 2;i += 2)
		{
			int _y = y;
			int _x = x;
			while (1)
			{
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 8;
						ReturnV.push_back({ ny,nx });
					}
					_y = ny;
					_x = nx;
				}
				else
				{
					break;
				}
			}
		}
	}
	else if (a[y][x] == 3)
	{
		for (int i = 0;i < 2;i++)
		{
			int _y = y;
			int _x = x;
			while (1)
			{
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 8;
						ReturnV.push_back({ ny,nx });
					}
					_y = ny;
					_x = nx;
				}
				else
				{
					break;
				}
			}
		}
	}
	else if (a[y][x] == 4)
	{
		for (int i = 0;i < 3;i++)
		{
			int _y = y;
			int _x = x;
			while (1)
			{
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 8;
						ReturnV.push_back({ ny,nx });
					}
					_y = ny;
					_x = nx;
				}
				else
				{
					break;
				}
			}
		}
	}
	else if (a[y][x] == 5)
	{
		for (int i = 0;i <4;i++)
		{
			int _y = y;
			int _x = x;
			while (1)
			{
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 8;
						ReturnV.push_back({ ny,nx });
					}
					_y = ny;
					_x = nx;
				}
				else
				{
					break;
				}
			}
		}
	}
	return ReturnV;
}

void dfs(int here)
{
	if (here == v.size())
	{
		int cnt = 0;
		for (int i = 0; i < n;i++)
		{
			for (int j = 0; j < m;j++)
			{
				if (a[i][j] == 0)
				{
					cnt++;
				}
			}
		}
		result = min(cnt, result);
		return;
	}
	for (int k = 0; k < 4;k++)
	{
		vector<pair<int, int>> _chage = FuncVector(here,k);
		dfs(here + 1);
		for (auto e : _chage)
		{
			a[e.first][e.second] = 0;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			cin >> a[i][j];
			if (a[i][j] != 6 && a[i][j] != 0)
			{
				v.push_back({ i,j });
			}
		}
	}
	dfs(0);
	cout << result;

}