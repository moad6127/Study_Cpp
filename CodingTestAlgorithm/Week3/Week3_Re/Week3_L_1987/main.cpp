#include <bits/stdc++.h>	
using namespace std;

int r, c;
char a[21][21];
int visited[30];
string s;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int result;
void dfs(int y, int x,int cnt)
{
	visited[a[y][x] - 'A'] = 1;
	result = max(cnt, result);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		int next = a[ny][nx] - 'A';
		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
		{
			continue;
		}
		if (visited[next])
		{
			continue;
		}
		visited[next] = 1;
		dfs(ny, nx, cnt + 1);
		visited[next] = 0;
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];
		}
	}
	dfs(0, 0,1);
	cout << result;
}