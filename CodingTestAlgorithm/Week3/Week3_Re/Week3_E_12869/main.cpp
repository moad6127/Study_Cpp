#include <bits/stdc++.h>

using namespace std;
int n;
int result;
int a[3];
int visited[64][64][64];
vector<vector<int>> d =
{ {9, 3, 1,},
{9, 1, 3},
{3, 9, 1},
{3, 1, 9},
{1, 9, 3},
{1, 3, 9} };

struct info
{
	int a, b, c;
};
int bfs(int a, int b, int c)
{
	visited[a][b][c] = 1;
	queue<info> q;
	q.push({ a,b,c });
	while (q.size())
	{
		int nowa = q.front().a;
		int nowb = q.front().b;
		int nowc = q.front().c;
		q.pop();
		if (visited[0][0][0])
		{
			break;
		}
		for (int i = 0; i < 6; i++)
		{
			int na = max(0, nowa - d[i][0]);
			int nb = max(0, nowb - d[i][1]);
			int nc = max(0, nowc - d[i][2]);
			if (visited[na][nb][nc])
			{
				continue;
			}
			visited[na][nb][nc] = visited[nowa][nowb][nowc] + 1;
			q.push({ na,nb,nc });
		}
	}
	return visited[0][0][0] - 1;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << bfs(a[0], a[1], a[2]);
}