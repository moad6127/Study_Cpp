#include <bits/stdc++.h>

using namespace std;

int n, m;
int w;
int a[1028][1028];
int tree[1028][1028];
void Update(int y, int x, int value)
{
	while (y <= n)
	{
		int j = x;
		while (j <= n)
		{
			tree[y][j] += value;
			j += (j & -j);
		}
		y += (y & -y);
	}
}
int Sum(int y, int x)
{
	int s = 0;
	while (y > 0)
	{
		int j = x;
		while (j > 0)
		{
			s += tree[y][j];
			j -= (j & -j);
		}
		y -= (y & -y);
	}
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			Update(i, j, a[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> w;
		if (w)
		{
			int y1{}, x1{}, y2{}, x2{};
			cin >> y1 >> x1 >> y2 >> x2;
			cout << Sum(y2, x2) - Sum(y1 - 1, x2) - Sum(y2, x1 - 1) + Sum(y1 - 1, x1 - 1) << '\n';
		}
		else
		{
			int y{}, x{}, c{};
			cin >> y >> x >> c;
			Update(y, x, c - a[y][x]);
			a[y][x] = c;
		}
	}
}