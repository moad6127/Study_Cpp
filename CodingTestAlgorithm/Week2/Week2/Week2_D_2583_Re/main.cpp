#include <bits/stdc++.h>


using namespace std;
int N, M, K;
int a[104][104];
int visited[104][104];
const int dy[4] = { -1, 1,0, 0 };
const int dx[4] = { 0, 0, -1, 1 };
vector<int> result;
int Func(int y, int x)
{
	visited[y][x] = 1;
	int sum{ 1 };
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
		{
			continue;
		}
		if (visited[ny][nx])
		{
			continue;
		}
		if (a[ny][nx])
		{
			continue;
		}
		sum += Func(ny, nx);
	}
	return sum;
}

int main()
{
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++)
	{
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				a[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j] && a[i][j] == 0)
			{
				int sum = Func(i, j);
				result.push_back(sum);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (auto e : result)
	{
		cout << e << " ";
	}
}