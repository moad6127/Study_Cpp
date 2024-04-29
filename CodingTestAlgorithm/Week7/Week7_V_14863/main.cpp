#include <bits/stdc++.h>

using namespace std;

int N, K, a, b, c, d;
pair<int, int> W[104];
pair<int, int> C[104];
int dp[104][100004];

int Func(int here, int time)
{
	if (here == N)
	{
		return 0;
	}
	if (dp[here][time])
	{
		return dp[here][time];
	}
	dp[here][time] = -1000000;
	if (time - W[here].first >= 0)
	{
		dp[here][time] = max(dp[here][time], Func(here + 1, time - W[here].first) + W[here].second);
	}
	if (time - C[here].first >= 0)
	{
		dp[here][time] = max(dp[here][time], Func(here + 1, time - C[here].first) + C[here].second);
	}

	return dp[here][time];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> W[i].first >> W[i].second >> C[i].first >> C[i].second;
	}
	cout << Func(0, K);
}