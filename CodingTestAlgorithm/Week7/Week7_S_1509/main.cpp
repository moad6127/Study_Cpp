#include <bits/stdc++.h>

using namespace std;

string s;
int dp[2504][2504], dp_min[2504];

int Func(int h)
{
	if (h == s.size())
	{
		return 0;
	}
	if (dp_min[h] != 987654321)
	{
		return dp_min[h];
	}
	for (int i = 1; h + i <= s.size(); i++)
	{
		if (dp[h][i])
		{
			dp_min[h] = min(dp_min[h], Func(h + i) + 1);
		}
	}
	return dp_min[h];
}
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		dp[i][1] = 1;
	}
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][2] = 1;
		}
	}
	for (int size = 3; size <= s.size(); size++)
	{
		for (int i = 0; i + size <= s.size(); i++)
		{
			if (s[i] == s[i + size - 1] && dp[i + 1][size - 2])
			{
				dp[i][size] = 1;
			}
		}
	}
	fill(dp_min, dp_min + 2504, 987654321);
	cout << Func(0);
}