#include <bits/stdc++.h>


using namespace std;

int N;
int a[12][12];
int visited[12][12];
int result = 10000000;
const int dy[4] = { -1, 1, 0 , 0 };
const int dx[4] = { 0, 0, -1, 1 };
const int checkY[4] = { -2, 2, 0 , 0 };
const int checkX[4] = { 0 , 0, -2, 2 };

void PrintV(const vector<vector<int>>& visited)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
}
void Func(int y, int x, int count, vector<vector<int>> visited,int sum)
{
	if (count == 3)
	{
		result = min(result, sum);
		PrintV(visited);
		return;
	}
	if (visited[y][x])
	{
		return;
	}
	sum += a[y][x];
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
		{
			return;
		}
		if (visited[ny][nx])
		{
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int chY = y + checkY[i];
		int chX = x + checkX[i];
		if (chY < 0 || chY >= N || chX < 0 || chX >= N)
		{
			continue;
		}
		if (visited[chY][chX])
		{
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		sum += a[ny][nx];
	}
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Func(i, j, count + 1, visited, sum);
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
	vector<vector<int>> visited(N, vector<int>(N, 0));
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < N ; j++)
		{
			Func(i, j, 0, visited,0);
		}
	}
	cout << result;
}