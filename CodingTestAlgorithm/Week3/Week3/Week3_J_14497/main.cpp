#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<string> a;
int visited[304][303];
int jx1, jy1, chx2, chy2;
const int dy[4] = { -1, 1, 0 ,0 };
const int dx[4] = { 0,0, -1, 1 };
int result;
int check;

int dfs(int y, int x)
{
	visited[y][x] = 1;
	int check{};
	if (a[y][x] =='#')
	{
		return 1;
	}
	if (a[y][x] == '1')
	{
		a[y][x] = '0';
		return 0;
	}
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
		check += dfs(ny, nx);
	}
	return check;
}

int main()
{
	cin >> N >> M>>jx1>>jy1>>chx2>>chy2;
	jx1 -= 1;
	jy1 -= 1;
	chx2 -= 1;
	chy2 -= 1;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		a.push_back(temp);

	}
	while (true)
	{
		if (dfs(jx1, jy1) > 0)
		{
			result++;
			break;
		}
		memset(visited, 0, sizeof(visited));
		result++;
	}

	cout << result;
	return 0;
}