#include <bits/stdc++.h>

using namespace std;

int n, m, t, d, result;
int a[30][30];
int dist[3000][3000];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> t >> d;
	//~ 입력받기
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			if (temp[j] >= 'a')
			{
				a[i][j] = temp[j] - 'a' + 26;
			}
			else
			{
				a[i][j] = temp[j] - 'A';
			}
		}
	}
	result = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			v.push_back(i * 100 + j);
		}
	}
	fill(&dist[0][0], &dist[0][0] + 3000 * 3000, 987654321);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int d = 0; d < 4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				{
					continue;
				}
				int check = abs(a[i][j] - a[ny][nx]);
				if (check <= t)
				{
					if (a[ny][nx] > a[i][j])
					{
						dist[i * 100 + j][ny * 100 + nx] = check * check;
					}
					else
					{
						dist[i * 100 + j][ny * 100 + nx] = 1;
					}
				}

			}
		}
	}
	for (int k : v)
	{
		for (int i : v)
		{
			for (int j : v)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int j : v)
	{
		if (d >= dist[0][j] + dist[j][0])
		{
			result = max(result, a[j / 100][j % 100]);
		}
	}
	cout << result;
}