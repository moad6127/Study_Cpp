#include <bits/stdc++.h>

using namespace std;
int N, L, R;

int a[54][54];
int visited[54][54];
int sum;
int result;
const int dy[4] = { -1, 1, 0 ,0 };
const int dx[4] = { 0, 0 ,-1, 1 };
bool checkCount;

vector<pair<int, int>> v;
void dfs(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
		{
			continue;
		}
		if (visited[ny][nx])
		{
			continue;
		}
		int check = abs(a[y][x] - a[ny][nx]);
		if (check >= L && check <= R)
		{
			v.push_back({ ny,nx });
			sum += a[ny][nx];
			dfs(ny, nx);
		}
	}
}
int main()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}

	while (true)
	{
		memset(visited, 0, sizeof(visited));
		checkCount = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					v.clear();
					v.push_back({ i,j });
					sum = a[i][j];
					dfs(i, j);
					if (v.size() == 1)
					{
						continue;
					}
					for (pair<int, int> e : v)
					{
						a[e.first][e.second] = sum / v.size();
						checkCount = 1;
					}
				}
			}
			
		}
		if (checkCount == 0)
		{
			break;
		}
		result++;

	}
	cout << result;

}