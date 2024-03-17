#include <bits/stdc++.h>

using namespace std;

int N, K, temp;
int dp[10004];

int main()
{
	cin >> N >> K;
	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = temp; j <= K; j++)
		{
			dp[j] += dp[j - temp];
		}
	}

	cout << dp[K];
}