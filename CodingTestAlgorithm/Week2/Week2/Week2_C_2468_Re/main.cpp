#include<bits/stdc++.h>

using namespace std;
int N;
int a[104][104];
int visited[104][104];
int MIN = 1000;
int MAX = -1;
const int dy[4] = { -1, 1, 0 , 0 };
const int dx[4] = { 0, 0, -1, 1 };
int result =1 ;

void Func(int y, int x, int s)
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
		if (a[ny][nx] < s)
		{
			continue;
		}
		Func(ny, nx, s);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			MIN = min(MIN, a[i][j]);
			MAX = max(MAX, a[i][j]);
		}
	}

	for (int i = MIN; i <= MAX; i++)
	{
		memset(visited, 0, sizeof(visited));
		int check{};
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (a[j][k] >= i && !visited[j][k])
				{
					Func(j, k, i);
					check++;
				}
			}
		}
		result = max(result, check);
	}
	cout << result;
}