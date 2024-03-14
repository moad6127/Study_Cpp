#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[10004];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	fill(dp, dp + 10004, 987654321);
	dp[0] = 0;
	for (int i = 0; i < N; i++)
	{
		int temp{};
		cin >> temp;
		for (int j = temp; j <= K; j++)
		{
			dp[j] = min(dp[j], dp[j - temp] + 1);
		}
	}
	if (dp[K] == 987654321)
	{
		cout << -1;
	}
	else
	{
		cout << dp[K];
	}
}