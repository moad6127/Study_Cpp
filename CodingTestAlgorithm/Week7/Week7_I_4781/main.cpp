#include <bits/stdc++.h>

using namespace std;
int n, c, result, cost, pri;
float m, p;
int dp[10004];

int main()
{
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0.f)
		{
			break;
		}
		cost = (int)m * 100;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			cin >> c >> p;
			pri = (int)p * 100;
			for (int j = pri; j <= cost; j++)
			{
				dp[j] = max(dp[j], dp[j - pri] + c);
			}
		}
		cout << dp[cost] << '\n';
	}
}