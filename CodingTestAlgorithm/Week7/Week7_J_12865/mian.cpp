#include <bits/stdc++.h>

using namespace std;
int N, K, W, V;
int dp[100004];
int main()
{
	cin >> N >> K;
	while (N--)
	{
		cin >> W >> V;
		for (int j = K; j >= W; j--)
		{
			dp[j] = max(dp[j], dp[j - W] + V);
		}
	}
	cout << dp[K];
}