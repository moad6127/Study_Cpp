#include <bits/stdc++.h>

using namespace std;

int n, m, h, A, B;
int result = 987654321;
int a[31][31];

bool check()
{
	for (int i = 1; i <= n; i++)
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (a[j][start])
			{
				start++;
			}
			else if (a[j][start - 1])
			{
				start--;
			}
		}
		if (start != i)
		{
			return false;
		}
	}
	return true;
}

void Func(int here, int cnt)
{
	if (cnt > 3 || cnt >= result)
	{
		return;
	}
	if (check())
	{
		result = min(result, cnt);
		return;
	}
	for (int i = here; i <= h; i++)
	{
		for (int j = 1; j <n; j++)
		{
			if (a[i][j] || a[i][j - 1] || a[i][j + 1])
			{
				continue;
			}
			a[i][j] = 1;
			Func(i, cnt + 1);
			a[i][j] = 0;
		}
	}
}
int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> A >> B;
		a[A][B] = 1;
	}
	Func(1, 0);
	if (result == 987654321)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
}