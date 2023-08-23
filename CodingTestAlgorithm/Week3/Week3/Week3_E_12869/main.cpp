#include <bits/stdc++.h>

using namespace std;
int N;
int a[3];
int visited[64][64][64];
int _a[6][3] = {
	{9, 3, 1},
	{9,1,3},
	{3,1,9},
	{3,9, 1},
	{1,3,9},
	{1,9,3}
};

struct A {
	int a, b, c;
};

int solve(int a, int b, int c)
{
	queue<A>q;
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	while (q.size())
	{
		A now = q.front();
		q.pop();
		if (visited[0][0][0])
		{
			break;
		}
		for (int i = 0; i < 6; i++)
		{
			int na = max(0, now.a - _a[i][0]);
			int nb = max(0, now.b - _a[i][1]);
			int nc = max(0, now.c - _a[i][2]);
			if (visited[na][nb][nc])
			{
				continue;
			}
			visited[na][nb][nc] = visited[now.a][now.b][now.c] + 1;
			q.push({ na,nb,nc });
		}
	}

	return visited[0][0][0] - 1;
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	cout << solve(a[0], a[1], a[2]);
}