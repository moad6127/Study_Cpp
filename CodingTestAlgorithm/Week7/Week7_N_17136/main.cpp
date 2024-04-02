#include <bits/stdc++.h>

using namespace std;

int a[11][11];
int result = 100000;
map<int, int> maxPage;
bool check(int startX, int startY, int size)
{
	if (startY + size > 10 || startX + size > 10)
	{
		return false;
	}
	for (int i = startY; i < startY + size; i++)
	{
		for (int j = startX; j < startX + size; j++)
		{
			if (a[i][j] != 1)
			{
				return false;
			}
		}
	}
	return true;
}
void zFunc(int startX, int startY, int size,int value)
{
	for (int i = startY; i < startY + size; i++)
	{
		for (int j = startX; j < startX + size; j++)
		{
			a[i][j] = value;
		}
	}
}
void dfs(int y, int x, int cnt)
{
	if (cnt >= result)
	{
		return;
	}
	if (x == 10)
	{
		dfs(y + 1, 0, cnt);
		return;
	}
	if (y == 10)
	{
		result = min(cnt, result);
	}
	if (a[y][x] == 0)
	{
		dfs(y, x + 1, cnt);
		return;
	}

	for (int size = 5; size >= 1; size--)
	{
		if (maxPage[size] == 5)
		{
			continue;
		}
		if (check(x, y, size))
		{
			maxPage[size]++;
			zFunc(x, y, size, 0);
			dfs(y, x + size, cnt + 1);
			zFunc(x, y, size, 1);
			maxPage[size]--;
		}
	}
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> a[i][j];
		}
	}
	dfs(0, 0, 0);
	if (result == 100000)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
}