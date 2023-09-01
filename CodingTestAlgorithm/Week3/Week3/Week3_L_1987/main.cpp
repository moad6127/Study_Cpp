#include <bits/stdc++.h>

using namespace std;


int R, C;
char a[24][24];
int visited[30];
const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0,0,-1,1 };
int result = -1;

void Func(int y, int x,int ret)
{
	result = max(ret, result);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
		{
			continue;
		}
		int next = a[ny][nx] - 'A';
		if (visited[next] == 0)
		{
			visited[next] = 1;
			Func(ny, nx, ret + 1);
			visited[next] = 0;
		}
	}
	
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
	visited[a[0][0] - 'A'] = 1;
	Func(0, 0, 1);
	cout << result;
}