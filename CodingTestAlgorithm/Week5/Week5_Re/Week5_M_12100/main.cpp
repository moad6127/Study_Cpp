#include <bits/stdc++.h>

using namespace std;


int n, result, temp;


int Count(vector<vector<int>>& a)
{
	int mx{};
	for (int i = 0; i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			mx = max(mx, a[i][j]);
		}
	}
	return mx;
}

void Rotate(vector<vector<int>>& a)
{
	vector<vector<int>> temp(n, vector<int>(n, 0));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			temp[i][j] = a[n - j - 1][i];
		}
	}
	a = temp;
}

void Move(vector<vector<int>>& a)
{
	vector<vector<int>> temp(n, vector<int>(n, 0));
	
	for (int i = 0;i < n;i++)
	{
		int c = -1;
		int d = 0;
		for (int j = 0;j < n;j++)
		{
			if (a[i][j] == 0)
			{
				continue;
			}
			if (d && a[i][j] == temp[i][c])
			{
				temp[i][c] *= 2;
				d = 0;
			}
			else
			{
				temp[i][++c] = a[i][j];
				d = 1;
			}
		}
	}
	a = temp;
}

void Func(vector<vector<int>> a, int here)
{
	if (here == 5)
	{
		result = max(result, Count(a));
		return;
	}
	for (int i = 0;i < 4;i++)
	{
		vector<vector<int>> temp = a;
		Move(temp);
		Func(temp, here + 1);
		Rotate(a);
	}
}


int main()
{

	cin >> n;

	vector<vector<int>> a(n, vector<int>(n, 0));
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			cin >> a[i][j];
		}
	}

	Func(a, 0);

	cout << result;
}