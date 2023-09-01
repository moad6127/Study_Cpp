#include <bits/stdc++.h>

using namespace std;


int R, C;
char a[24][24];
const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0,0,-1,1 };
int result = -1;

int dfs(int y, int x,set<char> check, vector<vector<int>> visited)
{
	auto c = check.insert(a[y][x]);
	visited[y][x] = 1;
	if (!c.second)
	{
		return check.size();
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
		{
			continue;
		}
		if (visited[ny][nx])
		{
			continue;
		}
		result = max(result, dfs(ny, nx, check,visited));
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < C; j++)
		{
			a[i][j] = temp[j];
		}
	}
	set<char> check;
	vector<vector<int>> visited(R, vector<int>(C, 0));
	cout<<dfs(0, 0, check,visited);
}