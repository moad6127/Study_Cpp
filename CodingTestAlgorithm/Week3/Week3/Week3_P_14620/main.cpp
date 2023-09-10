#include <bits/stdc++.h>


using namespace std;

int N;
int a[12][12];
int visited[12][12];
int result = 10000000;
const int dy[4] = { -1, 1, 0 , 0 };
const int dx[4] = { 0, 0, -1, 1 };

bool Check(int y, int x)
{
	if (visited[y][x])
	{
		return 0;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
		{
			return 0;
		}
		if (visited[ny][nx])
		{
			return 0;
		}
	}
	return 1;
}

int SetF(int y, int x)
{
	visited[y][x] = 1;
	int sum = a[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		sum += a[ny][nx];
	}
	return sum;
}
void RemoveF(int y, int x)
{
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}

void Func(int count, int sum)
{
	if (count == 3)
	{
		result = min(result, sum);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Check(i, j))
			{
				Func(count + 1, sum + SetF(i, j));
				RemoveF(i,j);
			}
		}
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
		}
	}
	Func(0, 0);
	cout << result;
}