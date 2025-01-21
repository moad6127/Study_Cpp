#include <bits/stdc++.h>

using namespace std;

const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };
const int dy2[] = { 0, 1, 0, -1 };
const int dx2[] = { 1, 0, -1, 0 };
int r, c, t, result;
int a[51][51], visited[51][51], temp[51][51];
vector<pair<int, int>> air1;
vector<pair<int, int>> air2;
void spred()
{
	memset(visited, 0, sizeof(visited));
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < r;i++)
	{
		for (int j = 0; j < c;j++)
		{
			if (a[i][j])
			{
				int sum{};
				for (int k = 0; k < 4;k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || ny >= r || nx < 0 || nx >= c)
					{
						continue;
					}
					if (a[ny][nx] == -1)
					{
						continue;
					}
					temp[ny][nx] += a[i][j] / 5;
					sum += a[i][j] / 5;
				}
				temp[i][j] += a[i][j] - sum;
			}
		}
	}
	memcpy(a, temp, sizeof(temp));
}
vector<pair<int, int>> GetAir(int sy, int sx,const int dy[],const int dx[])
{
	vector<pair<int, int>> v;
	int cnt{};
	int y = sy;
	int x = sx;
	while (true)
	{
		int ny = y + dy[cnt];
		int nx = x + dx[cnt];
		if (ny == sy && nx == sx)
		{
			break;
		}
		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
		{
			cnt++;
			ny = y + dy[cnt];
			nx = x + dx[cnt];
		}
		if (ny == sy && nx == sx)
		{
			break;
		}
		y = ny;
		x = nx;
		v.push_back({ ny,nx });
	}
	return v;
}
void MoveAir(vector<pair<int, int>>& v)
{
	for (int i = v.size() - 1; i > 0;i--)
	{
		a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
	}
	a[v[0].first][v[0].second] = 0;
	return;
}

int main()
{
	cin >> r >> c >> t;
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cin >> a[i][j];
			if (a[i][j] == -1)
			{
				if (air1.empty())
				{
					air1 = GetAir(i, j, dy, dx);
				}
				else
				{
					air2 = GetAir(i, j, dy2, dx2);
				}
			}
		}
	}
	for (int i = 0;i < t;i++)
	{
		//확산
		spred();
		MoveAir(air1);
		MoveAir(air2);
		//공청작동
	}
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			if (a[i][j] == -1)
			{
				continue;
			}
			result += a[i][j];
		}
	}
	cout << result;
}