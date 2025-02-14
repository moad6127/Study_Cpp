#include <bits/stdc++.h>

using namespace std;

// 0은 12시 2오른쪽 ,6 왼쪽
int t, k, num, dir, result;
string a[1004];

void Rotate(int here, int dir)
{
	if (dir == 1)
	{
		rotate(a[here].rbegin(), a[here].rbegin() + 1, a[here].rend());
	}
	else
	{
		rotate(a[here].begin(), a[here].begin() + 1, a[here].end());
	}
}

void Func(int here, int moveNum, int dir)
{
	if (here < 0)
	{
		return;
	}
	if (here >= t)
	{
		return;
	}

	int tempDir = dir == -1 ? 1 : -1;
	if (here - 1 >= 0 && moveNum != 1)
	{
		if (a[here - 1][2] != a[here][6])
		{	
			Func(here - 1, -1, tempDir);
		}
	}
	if (here + 1 < t && moveNum != -1)
	{
		if (a[here + 1][6] != a[here][2])
		{
			Func(here + 1, 1, tempDir);
		}
	}
	Rotate(here, dir);
}
int main()
{
	cin >> t;
	for (int i = 0; i < t;i++)
	{
		cin >> a[i];
	}
	cin >> k;
	for (int i = 0; i < k;i++)
	{
		cin >> num >> dir;
		Func(num - 1, 0, dir);
	}
	for (int i = 0;i < t;i++)
	{
		result += a[i][0] - '0';
	}
	cout << result;
}