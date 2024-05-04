#include <bits/stdc++.h>

using namespace std;
vector<int> a;
map<pair<int,int>, int> pw;
int dp[100004][5][5];
void Pw()
{
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (i == j)
			{
				pw[{i, j}] = 1;
				continue;
			}
			if (i == 0)
			{
				pw[{i, j}] = 2;
				continue;
			}
			if (abs(i - j) == 2)
			{
				pw[{i, j}] = 4;
				continue;
			}
			else
			{
				pw[{i, j}] = 3;
				continue;
			}
		}
	}
}

int Func(int here,int left, int right)
{
	if (a[here] == 0)
	{
		return 0;
	}
	if (dp[here][left][right])
	{
		return dp[here][left][right];
	}
	dp[here][left][right] = 987654321;

	if (a[here] != right)
	{
		dp[here][left][right] = min(dp[here][left][right],Func(here + 1, a[here], right) + pw[{left, a[here]}]);
	}
	if (a[here] != left)
	{
		dp[here][left][right] = min(dp[here][left][right],Func(here + 1, left, a[here]) + pw[{right, a[here]}]);
	}


	return dp[here][left][right];
}

int main()
{
	while (true)
	{
		int temp{};
		cin >> temp;
		a.push_back(temp);
		if (temp == 0)
		{
			break;
		}

	}
	Pw();


	cout << Func(0, 0, 0);

}