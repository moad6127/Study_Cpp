#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;
map<pair<int, int>, int>m;
queue<pair<int, int>> q;

void check(int x, int y, int cnt)
{
	if (m[{x, y}])
	{
		return;
	}
	m[{x, y}] = cnt + 1;
	q.push({ x,y });
}

int bfs(int x, int y)
{
	m[{x, y}] = 1;
	q.push({ x,y });
	while (q.size())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		check(a, y, m[{x, y}]);
		check(x, b, m[{x, y}]);
		check(0, y, m[{x, y}]);
		check(x, 0, m[{x, y}]);
		check(min(x + y, a), max(0, x + y - a), m[{x, y}]);
		check(max(0, x + y - b), min(x + y, b), m[{x, y}]);
	}
	if (m[{c, d}])
	{
		return m[{c, d}] - 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	cin >> a >> b >> c >> d;
	cout << bfs(0, 0);
}